### 왜 데이터베이스를 사용하는가?(Why use database?)
1. 데이터를 공유하고, 협업할 수 있다.(동시 접근 지원)
2. 데이터를 빠르게 조회할 수 있다.(인덱스)
3. 데이터 중복을 최소화한다.
4. 일관성을 유지한다.(동시성 제어, 트랜잭션)
5. 데이터 보안을 강화할 수 있다.(접근 제어)

### 여러 방식의 데이터베이스
1. 계층적 데이터베이스: 데이터를 계층 형태로 저장, 데이터 중복이 발생할 수 있으며, 복잡한 관계 표현이 힘듬.
2. 네트워크 데이터베이스: 네트워크 구조로 데이터를 저장, 복잡한 설계와 유지 관리, 표준화 문제
3. 객체형 데이터베이스: 객체 형태로 저장, 언어마다 다른 객체성으로 표준화 문제

### 관계 데이터 모델 용어 정리(Words in Relational Database)
<img width="552" alt="image" src="https://github.com/ChangDaeJun/study/assets/97227920/24341e2c-caef-44d0-9133-92cc63de0f0a">

* 릴레이션(relation), 테이블(table) : 행과 열로 구성된 테이블을 의미한다.
* 관계(relationship) : 테이블과 테이블 간의 관계를 의미한다. 외래키에 의해 생긴다.
* 속성(attribute), 열(column) : 테이블이 가지고 있는 속성
* 도메인(domain) : 속성이 가질 수 있는 데이터의 집합
* 튜플(tuple), 행(row) : 테이블에 저장된 특정 정보
* 스키마(schema) : 속성과 자료의 타입과 같은 정보
* 인스턴스(instance) : 튜플의 집합, 스키마에 따라 테이블에 실제 저장된 데이터 집합


### 키(Key)
* 슈퍼키(super key) : 튜플을 유일하게 식별할 수 있는 속성 집합
* 후보키(candidate key) : 슈퍼키 중 최소성을 만족하는 키(일부 속성을 제거해도 슈퍼키인 경우는 최소성을 만족하지 않는다.)
* 기본키(primary key) : 후보키 중 하나를 선정하여 대표성을 갖는 키, 기본키 제약이 존재한다.
* 대리키(surrogate key), 인조키(artificial key) : 가상의 속성을 통해 기본키를 삼는 경우
* 대체키(alternate key) : 기본키가 아닌 후보키
* 외래키(foreign key) : 다른 테이블의 기본키를 참조하는 속성

### 무결성 제약조건(integrity constraint)
1. 도메인 무결성 제약조건(domain integrity constraint)
   * 각 속성 값은 도메인이 지정한 type, null/not null, default check 등을 준수해야 한다.
2. 개체 무결성 제약조건(Entity integrity constraint)
   * 기본키 제약 조건과 동일하며, 기본키에는 null이 금지되고, 중복이 안되며, 변경이 불가능하다.
   * 삽입, 삭제 시 개체 무결성을 확인하다.
3. 참조 무결성 제약조건(referential integrity constraint)
   * 외래키 제약 조건과 동일하며, 자식은 부모 기본키와 동일한 도메인을 사용한다.
   * 삽입 : 부모의 기본키 도메인 제약조건이 맞는지 확인한다.
   * 삭제 : 부모 삭제 시 4가지 옵션을 선택할 수 있다.(Restricted, Cascade, Default, Null)
4. UNIQUE 제약조건
   * 튜플은 유일해야 한다.

### 관계대수 연산자(relational algebra operator)
1. 기본 연산자
   * Selection : 조건에 맞는 튜플 검색
   * Projection : 선택한 속성만 검색
   * Union(U) : 합집합
   * Difference(-) : 차집합
   * Cartesian Product(X) : 두 테이블의 카테시안 곱

2. 유도 연산자
   * Intersection : 교집합(유도식 : (A U B) - ((A - B) + (B- A)))
   * Division : 릴레이션 속성 값 전부를 만족하는 투플의 속성 검색(?)
   * Join : 공통 속성을 기준으로 속성 값이 같은 튜플을 수평으로 결함(유도식 : Selection(A X B) )
     * 세타 조인(theta join) : 조인 중 속성 값이 조건에 맞는 경우
     * 동등 조인(equi join, inner join) : 세타 조인에서 조건이 = 인 경우
     * 자연 조인(natural join) : 자연 조인의 결과에서 중첩되는 속성 제거
     * 외부 조인(outer join) : 자연 조인 시 조인에 실패한 튜플을 보여주기 위해 값이 없는 속성을 null로 표기(left, right, full 로 구분)
     * 세미 조인(semi join) : 자연 조인 후 한쪽 릴레이션 결과만 반환

3. 기타
   * rename : 테이블이나 속성 이름을 변경

### 이상현상(anomaly)
* 삭제이상(deletion anomaly) : 투플 삭제 시 다른 정보도 같이 삭제됨
* 삽입이상(insertion anomaly) : 투플 삽입 시 특정 속성 값이 null로 들어가게 됨
* 수정이상(update anomaly) : 투플 수정 시 중복된 일부 정보만 수정하여, 데이터 불일치 발생

### 정규화(normalization)
* 이상현상이 발생하는 테이블을 수정하여 문제를 해결하는 것
* 함수 종속성 : 속성 집합 A에 의해 B가 결정될 경우, B가 A에 의해 함수 종속적이라고 할 수 있다. 또한, 릴래이션 전체 속성은 반드시 기본키에 함수 종속적이다.

#### 제 1 정규형(1NF)
* 각 행의 교집합은 하나의 속성만 갖고, 각 열의 교집합은 반드시 하나의 값만 갖는다.(A relation which the intersection of each row and column contains one and only one value.)
* 다음과 같은 경우는 1 정규형이 아니다.
* 한 속성에 여러 값을 넣는 경우

| name | address      | phoneNumber                  |
|------|--------------|------------------------------|
| Chang | Korea, Seoul | 010-1111-1111, 010-2222-2222 |
| Kim  | Korea, Busan | 010-3333-3333                |
* 중복된 행을 갖는 경우

| name  | address      | phoneNumber   |
|-------|--------------|---------------|
| Chang | Korea, Seoul | 010-1111-1111 |
| Chang | Korea, Seoul | 010-2222-2222 |
| Kim   | Korea, Busan | 010-3333-3333 |
* 중복된 열을 갖는 경우

| name  | address      | phoneNumber1  | phoneNumber2  |
|-------|--------------|---------------|---------------|
| Chang | Korea, Seoul | 010-1111-1111 | 010-2222-2222 |
| Kim   | Korea, Busan | 010-3333-3333 | null          |

* 위와 같은 테이블은 다음과 같은 이상현상을 일으킨다.
```
    1. 삽입이상 : 중복된 열을 갖는 경우 null 값을 삽입해야 한다.
    2. 수정이상 : 중복된 행을 갖는 경우에서 Chang의 address을 하나의 행만 변경 시 데이터 일관성이 회손된다.
```

* 위 테이블은 다음과 같이 수정할 수 있다.

| name  | address      |
|-------|--------------|
| Chang | Korea, Seoul |
| Kim   | Korea, Busan |

| name  | phoneNumber   |
|-------|---------------|
| Chang | 010-1111-1111 |
| Chang | 010-2222-2222 |
| Kim   | 010-3333-3333 |

#### 2 정규형(2NF)
* 1 정규형을 만족하며, 모든 속성이 기본키에 완전 함수 종속이다.(A relation is int first normal form and every non-primary key attribute is fully functionally dependent on the primary key.)

| num | class    | class room | point |
|-----|----------|------------|-------|
| 1   | database | 110        | 3.5   |
| 2   | network  | 111        | 4.2   |
| 1   | network  | 111        | 4.5   |
| 2   | database | 110        | 3.8   |

* 위 경우는 1정규형을 만족하면서, 2정규형을 만족하지 못하는 경우이다.
* 위와 같은 테이블은 다음과 같은 이상현상을 일으킨다.
```
    1. 삽입이상 : 새로운 class을 추가할 경우 수강학생과 수강 성적이 없어 null 값이 들어가게 된다.
    2. 수정이상 : database의 class room을 202로 변경할 경우, 데이터 중복으로 인한 불일치가 발생할 수 있다.
    3. 삭제이상 : 1,2 학생의 데이터베이스 수강을 취소할 경우 해당 class의 class room 정보도 같이 사라진다.
```

* 위 테이블에서는 수강 내역, 강좌 정보라는 두 함수 종속이 존재하기 때문이다.
* 수강 내역 : (num, class) -> point
* 강좌 정보 : (class) -> class room
* 여기서 class room은 기본키인 (num, class)가 아닌, 기본키의 부분집합인 class에 종속되어, 완전 종속되지 못한다.

* 위 테이블은 다음과 같이 해결할 수 있다.

| num | class    | point |
|-----|----------|-------|
| 1   | database |  3.5  |
| 2   | network  | 4.2   |
| 1   | network  | 4.5   |
| 2   | database | 3.8   |

| class    | class room |
|----------|------------|
| database | 110        |
| network  | 111        |

#### 3 정규형(3NF)
* 2 정규형이면서, 기본키가 아닌 속성이 비이행적 종속을 만족한다.(A relation that is in first and second normal form and in which no non-primary key is transitively dependent on the primary key)
* 이행적 종속 : A(PK) -> B -> C 으로, C 역시 A에 종속되어 있지만, 이행적으로 종속되어 있다.
* 다음과 같은 경우, 2정규형을 만족하면서, 3 정규형을 만족하지 못한다.

| user num | grade   | discount(%) |
|----------|---------|-------------|
| 1        | gold    | 10          |
| 2        | silver  | 5           |
| 3        | diamond | 15          |
| 4        | none    | 0           |
| 5        | silver  | 5           |

* (user num) -> (grade) -> (discount)인 이행적 종속을 만족한다.
* 위 테이블은 다음과 같은 이상현상을 나타낸다.
```
    1. 삭제 이상 : user num = 4 행을 삭제할 경우, none 등급의 할인율도 같이 삭제된다.
    2. 수정 이상 : silver의 할인율을 올리기 위해 중복된 데이터를 수정해야 한다.
    3. 삽입 이상 : 할인율이 20%인 새로운 등급 master을 등록하기 위해서는 user num = null 로 삽입해야 한다.
```
* 유저 등급과 등급 할인율 관계를 분리해서 이를 해결할 수 있다.

| user num | grade   |
|----------|---------|
| 1        | gold    |
| 2        | silver  |
| 3        | diamond |
| 4        | none    |
| 5        | silver  |

| grade   | discount(%) |
|---------|-------------|
| gold    | 10          |
| silver  | 5           |
| diamond | 15          |
| none    | 0           |

#### BCNF(Boyce Codd Normal Form)
* 릴레이션의 모든 함수 종속성의 결정자는 후보키이다.(A relation is BCNF if and only if every determinant is a candidate key)

#### 4 정규형
* 다차 종속이 존재하지 않는다.

#### 5 정규형
* 조인 종속이 존재하지 않는다.

### 트랜잭션(transaction)
* 데이터베이스 작업의 최소 단위이면서, ACID 성질을 갖는다.
* 트랜잭션 수행 과정
```
1. 데이터베이스 테이블을 읽고, 이를 버퍼에 저장한다.
2. 버퍼의 데이터를 수정한다.
3. 버퍼의 값을 데이터베이스에 저장한다.
```
* 실제로는 2번 절차가 끝난 후 사용자에게 완료됨을 알린다.
* DBMS는 각 트랜잭션이 디스크에 접근하는 것을 막고, 이를 일괄처리함으로써 빠른 응답성을 보장한다.

### ACID 성질
* 원자성(Atomicity) : 트랜잭션의 작업은 모두 수행되거나 모두 수행되지 않아야 한다.(all or nothing)
* 일관성(Consistency) : 데이터베이스는 항상 일관된 상태를 유지해야 한다.
* 고립성(Isolation) : 트랜잭션은 다른 트랜잭션의 영향으로 데이터 값이 훼손되어서는 안된다.
* 지속성(Durability) : 수행된 트랜잭션은 영구적으로 반영되어야 한다.

### 동시성 제어(Concurrency control)
* 트랜잭션의 데이터 접근을 제어하는 행위
* 동시성 제어를 하지 않을 경우 갱신손실, 오손읽기, 반복 불가능 읽기, 유령데이터 읽기 등의 문제가 발생한다.
* 데이터베이스에서는 공유락(LS)와 배타락(LX), 2단계 락킹과 고립 수준을 통해 해당 문제를 해결한다.
* 공유락과 배타락은 데이터에 대해 다음과 같이 요청과 락을 관리한다.

| 구분    | LS 상태 | LX 상태 |
|-------|-------|-------|
| LS 요청 | 승인    | 대기    |
| LX 요청 | 대기    | 대기    |

* 하지만, 데이터 점유를 언제 해제하느냐에 따라 데이터의 일관성이 깨질 수 있다.
* 이를 해결하기 위해 2단계 락킹에서는 데이터를 점유하는 확장단계와 데이터 점유를 해제하는 수축단계로 나눈다.
* DBMS에서는 고립 수준 명령어를 통해 간단하게 제어하는 기능을 제공한다.

| 이름               | Select            | Update | 기타                                                              | 효과                            |
|------------------|-------------------|--------|-----------------------------------------------------------------|-------------------------------|
| Read uncommitted | 공유락 X             | 배타락 O  | 다른 트랜잭션의 공유락과 배타락이 걸린 데이터 읽음                                    | 없음                            |
| Read committed   | 공유락 O 끝나고 바로 해지   | 배타락 O  | 다른 트랜잭션의 공유락을 읽고, 배타락은 못읽음                                      | 오손읽기 예방                       |
| Repeatable read  | 공유락 O 트랜잭션 끝까지 유지 | 배타락 O  | 다른 트랜잭션의 공유락을 읽고, 배타락은 못읽음                                      | 오손읽기, 반복 불가능 읽기 예방            |
| Serializable     | 공유락 O 트랜잭션 끝까지 유지 | 배타락 O  | 다른 트랜잭션의 공유락을 읽고, 배타락은 못읽음 <br/> 인덱스 공유락을 통해 다른 트랜잭션의 INSERT 금지 | 오손읽기, 반복 불가능 읽기, 유령 데이터 읽기 예방 |


### 참고 자료(reference)
* 박우창, 남송휘, 이현룡, MySQL로 배우는 데이터베이스 개론과 실습(한빛아카데미, 2019)
* E. F. Codd, A Relational Model of Data for Large Shared Data Banks(1970)
* 정규화 : https://ko.wikipedia.org/wiki/%EC%A0%9C1%EC%A0%95%EA%B7%9C%ED%98%95
