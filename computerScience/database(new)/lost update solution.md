## 갱신손실(Lost Update)

### 구현 환경
* Spring Boot, JPA, MySQL

### 구현 코드
```java
@Entity
@ToString
public class Member {
    @Id
    @GeneratedValue
    @Column(name = "MEMBER_ID")
    private Long id;

    private String name;

    private String address;

    private String phoneNum;
    
    //getter, setter
}
```
```java
public interface MemberRepository extends JpaRepository<Member, Long> {
    @Lock(LockModeType.PESSIMISTIC_WRITE)
    @Query(value = "select m From Member m where m.id =:id")
    Member findByIdForUpdate(Long id);
}
```
```java
@Service
public class MemberService {

    @Autowired
    private MemberRepository memberRepository;

    @Transactional
    public void updatePhoneNum(Long id, String num){
        Member member = memberRepository.findById(id).get();
        member.setPhoneNum(num);
    }

    @Transactional
    public void updateName(Long id, String name){
        Member member = memberRepository.findById(id).get();
        member.setName(name);
    }

    @Transactional
    public void updateAdd(Long id, String add){
        Member member = memberRepository.findById(id).get();
        member.setAddress(add);
    }

    @Transactional
    public void updatePhoneNumInLock(Long id, String num){
        Member member = memberRepository.findByIdForUpdate(id);
        member.setPhoneNum(num);
    }

    @Transactional
    public void updateNameInLock(Long id, String name){
        Member member = memberRepository.findByIdForUpdate(id);
        member.setName(name);
    }

    @Transactional
    public void updateAddInLock(Long id, String add){
        Member member = memberRepository.findByIdForUpdate(id);
        member.setAddress(add);
    }
}
```

### 갱신손실 테스트
* 위 서비스의 updateAdd와 updateName을 멀티쓰레드 환경에서 동시에 실행할 경우 갱신손실의 문제가 발생한다.
```java
    @Test
    @RepeatedTest(10)
    public void 갱신손실_테스트() throws Exception{
        Member member = new Member("name" , "address", "010-1111-1111");
        memberRepository.save(member);
        Long id = member.getId();
        ExecutorService executorService = Executors.newFixedThreadPool(3);

        executorService.execute(() -> {
            memberService.updateName(id, "name11");
        });
        executorService.execute(() -> {
            memberService.updateAdd(id, "address11");
        });
        executorService.execute(() -> {
            memberService.updatePhoneNum(id, "010-2222-2222");
        });

        executorService.shutdown();
        executorService.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);

        Member member1 = memberRepository.findById(id).get();
        System.out.println(member1.toString());
    }
```
* 해당 테스트의 결과는 다음과 같다.
```
Member(id=1, name=name, address=address, phoneNum=010-2222-2222)
Member(id=2, name=name, address=address, phoneNum=010-2222-2222)
Member(id=3, name=name, address=address, phoneNum=010-2222-2222)
Member(id=4, name=name, address=address11, phoneNum=010-1111-1111)
Member(id=5, name=name, address=address, phoneNum=010-2222-2222)
Member(id=6, name=name, address=address, phoneNum=010-2222-2222)
Member(id=7, name=name, address=address11, phoneNum=010-1111-1111)
Member(id=8, name=name, address=address, phoneNum=010-2222-2222)
Member(id=9, name=name11, address=address, phoneNum=010-1111-1111)
Member(id=10, name=name, address=address, phoneNum=010-2222-2222)
Member(id=11, name=name11, address=address, phoneNum=010-1111-1111)
```

### Lock을 통한 갱신손실 방지
* @Lock(LockModeType.PESSIMISTIC_WRITE)는 JPA의 비관적 락으로, 데이터베이스의 락 기법을 사용한다.
* MySQL을 기준으로 select * from Member for update;로 sql이 발생하며, 동일한 row의 접근을 막는다.
* 해당 테스트는 다음과 같다.
```java
    @Test
    @RepeatedTest(100)
    public void 갱신손실_락_테스트() throws Exception{
        Member member = new Member("name" , "address", "010-1111-1111");
        memberRepository.save(member);
        Long id = member.getId();
        ExecutorService executorService = Executors.newFixedThreadPool(3);

        executorService.execute(() -> {
            memberService.updateNameInLock(id, "name11");
        });
        executorService.execute(() -> {
            memberService.updateAddInLock(id, "address11");
        });
        executorService.execute(() -> {
            memberService.updatePhoneNumInLock(id, "010-2222-2222");
        });

        executorService.shutdown();
        executorService.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);

        Member member1 = memberRepository.findById(id).get();
        System.out.println(member1.toString());
    }
```

* 테스트의 결과는 다음과 같다.
```
Member(id=1, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=2, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=3, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=4, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=5, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=6, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=7, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=8, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=9, name=name11, address=address11, phoneNum=010-2222-2222)
...
Member(id=94, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=95, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=96, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=97, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=98, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=99, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=100, name=name11, address=address11, phoneNum=010-2222-2222)
Member(id=101, name=name11, address=address11, phoneNum=010-2222-2222)
```