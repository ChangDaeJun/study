### 왜 데이터베이스를 사용하는가?(Why use database?)
1. 데이터를 공유하고, 협업할 수 있다.(동시 접근 지원)
2. 데이터를 빠르게 조회할 수 있다.(인덱스)
3. 데이터 중복을 최소화한다.
4. 일관성을 유지한다.(동시성 제어, 트랜잭션)
5. 데이터 보안을 강화할 수 있다.(접근 제어)

### 관계 데이터 모델 용어 정리(Word in Relational Database)
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
   * 각 속성 값은 도메인이 지정한 type, null/not null, defaultm check 등을 준수해야 한다.
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


### 참고 자료(reference)
* 박우창, 남송휘, 이현룡, MySQL로 배우는 데이터베이스 개론과 실습(한빛아카데미, 2019)
* E. F. Codd, A Relational Model of Data for Large Shared Data Banks(1970)
