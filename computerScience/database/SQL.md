### SQL 종류
* 데이터 정의어(DDL) : 테이블이나 관계 구조 생성하는데 사용, create, alter, drop 등
* 데이터 조작어(DML) : 테이블에서 데이터를 검색, 삽입, 수정, 삭제하는데 사용, select, insert, delete, update 등
* 데이터 제어어(DCL) : 데이터의 사용 권한을 관리하는데 사용, grant, revoke 등

## 데이터 조작어

### SELECT
* 조회하고자 하는 도메인 이름 작성.
* 전체 조회 : *

### WHERE
* 조건을 검색할 때 사용
* 비교 연산자 : =, <, >, <= 등
* 범위 검색 : between 10000 and 20000
* 집합 : In (a, b, c). Not in (a, b, c)
* 패턴 : Like '정규식 패턴' : 반드시 한글 작은 따옴표가 아닌 영문 작은 따옴표로 작성할 것 !
* null : IS NULL, IS NOT NULL, IF NULL
* 논리 연산자 : AND, OR, NOT

### ORDER BY
* 특정 조건에 따라 정렬하여 출력 : ORDER BY 도메인 이름
* 오름차순 : ASC; 보통은 오름차순이 디폴트
* 내림차순 : DESC;

### 집계 함수
* 도메인 값의 합 : SUM(도메인 이름)
* 평균 : AVG()
* 개수 : COUNT()
* 최댓값, 최솟값 : MAX(), MIN()

### GROUP BY
* 속성이 같은 값끼리 그룹을 묶어 표현할 수 있다.
* ``` 
  SELECT  userid, COUNT(*), SUM(price) 
  FROM  Orders
  GROUP BY userid;
  -> userid가 동일한 튜플끼리 묶어 한 유저가 구매한 개수와 구매한 총 가격을 산출할 수 있다.
  ```
* Having 을 통해 그룹에 대해 제한할 수 있다. 위 문장에 havaing count(*) >=2;을 작성하면, 유저가 적어도 2개 이상 물건을 산 경우만 노출된다.
* group by 후 select 문에는 그룹을 만들 때 사용한 속성과 집계함수만 사용이 가능하다.
* having 은 단독으로 사용되지 않으며, where절 보다 뒤에 나와야 한다. 반드시 집계함수만 사용가능하다.

### 조인
* FROM 절에 조인하고자 하는 릴레이션의 이름을 작성. 예 : from customer, order;
* 두 릴레이션에 동일한 이름의 도메인이 있는 경우 A.domain, B.domain 으로 구분한다.
* 자기 자신과 조인하는 셀프 조인도 가능하다. 이때 릴레이션에 적절한 이름을 지정해주어야 한다. 예 : from A a1, A a2;

### 부속질의
* 쿼리문을 괄호()로 묶어 새로운 릴레이션처럼 사용할 수 있다.

### 집합연산
* 합집합 : 쿼리1 UNION 쿼리 2 처럼 사용 가능
* 차집합, 교집합은 IN, NOT IN을 사용하여 부속질의를 사용하면 구현할 수 있다.

### EXISTS
* 부속질의문의 어떤 행이 조건에 만족할 경우 참이다.


## 데이터 정의어

### CREATE 문
```
    CREATE TABLE 테이블_이름(
    도메인_이름      INTEGER
    도메인_이름      VARCHAR(20) // 문자열 크기 20 이하
    도메인_이름      INTEGER DEFAULT 10000 CHECK(도메인_이름 >= 1000) // 기본값 10000, 1000 이상의 수만 가능
    도메인_이름      INTEGER PRIMARY KEY //기본키 설정
    도메인_이름      INTEGER NOT NULL // null 허용 안함
    FOREIGN KEY(외부키_이름) REFERENCES 외부테이블_이름(외부키_이름) ON DELETE CASCADE
    );
```

### ALTER 문
* 테이블 속성, 제약 변경, 기본키 및 외래키 변경 가능
```
ALTER TALBE 테이블이름
ADD 도메인_이름  INTEGER // 도메인 추가
DROP COLUMN 도메인_이름 // 도메인 삭제
AlTER COLUMN   // 도메인 변경
```

### DROP
* 테이블 삭제 : DROP TABLE 테이블 이름

## 데이터 조작어
* INSERT 문 : 새로운 튜플 추가, INSERT INTO 테이블 이름(a, b, c, d) VALUES(a, b, c, d);
* UPDATE 문 : 특정 속성 값 수정, UPDATE 테이블 이름 SET 변경문 WHERE 조건문;
* DELETE 문 : DELETE FROM 테이블 이름 WHERE 검색조건;

## 내장함수

### 숫자 함수
* 절대값 : ABS()
* 올림 : CEIL()
* 내림 : FLOOR()
* 반올림 : ROUND(수, 기준점)
* 자연로그 값 : LOG()
* 제곱 : POWER(수, 횟수)
* 제곱근 : SQRT()
* 양수 음수 판단 : SIGN() // 양수 1, 음수 -1, 0 0

### 문자함수
* 문자 연결 : CONCAT(s1, s2)
* 문자 소문자로 변경 : LOWER()
* 문자 대문자로 변경 : UPPER()
* 문자 왼쪽에 지정한 자리수 만큼 지정한 문자로 채움 : LPAD(str, cnt, '추가할 문자')
* 문자 오른쪽에 지정한 자리수 만큼 지정한 문자로 채움 : RPAD(str, cnt, '추가할 문자')
* 문자 자르기(sub) : SUBSTR(str, start, end)
* 문자열 양쪽에 지정된 문자 삭제 : TRIM(str)(공백제거), TRIM('*' from '***aaaaa***')
* 아스키코드값 반환 : ASCII()
* 문자열의 바이트 반환 : LENGTH()
* 문자열의 개수(길이) 반환 : CHAR_LENGTH()
* 문자열 속 문자 교채 : REPLACE(str, old, new)

### 날짜 시간 함수
* 문자 데이터를 날짜 데이터로 변환 : STR_TO_DATE(str, format)
* 날짜 데이터를 문자 데이터로 변환 : DATE_FORMAT(date, format)
* 날짜 데이터에 주어진 시간 더하기 : ADDDATE(date, time), time = INTERVAL 10 DAY
* 날짜 데이터의 날짜부분 출력 : DATE(date)
* 두 날짜 차이 반환 : DATEDIFF(date1, date2)
* DB 시간 출력 : SYSDATE
* 데이터 포맷은 찾아보기

### 부속질의
* 스칼라 부속질의 : select 안에서 사용, 행과 열의 개수를 잘 맞춰야함
* 인라인 부속질의 : from 에서 사용, 기존의 테이블로부터 가상의 테이블인 뷰를 만들어 사용
* 중첩질의 : where문에서 사용

### 뷰(쀼쀼쀼)
* 생성 : create view 이름 AS(select 쿼리)
* 수정 : create OR replace view as(select)
* 삭제 : drop view

### 인덱스
* 데이터베이스는 보조기억장치(하드, ssd)에 기록되기에 디스크 입출력 시간에 절대적인 영향을 받는다.
* 데이터베이스는 버퍼에 자주사용하는 데이터를 저장하며, 이는 LRU 알고리즘을 통해 빈도에 따라 저장한다.
* 인덱스 : 튜플의 키값에 대한 물리적 위치를 기록해둔 자료구조.
* 특징
  * 인덱스는 테이블에서 한개 이상의 속성을 이용하여 생성
  * 빠른 검색과 효율적인 레코드 접근 가능
  * 순서대로 정렬된 속성과 데이터 위치만 보유하므로 테이블보다 작은 공간 차지
  * 일반적으로 B- tree 사용
  * 데이터의 수정, 삭제 등 변경 시 인덱스의 재구성 필요
* 인덱스는 데이터의 종류가 작아 선택도가 높은 도메인에 대해서는 사용하지 않는 것이 좋다.
  * 인덱스는 WHERE절에서 자주 사용되어야 한다.
  * 조인에 자주 사용되어야 한다.
  * 단일 테이블에 인덱스가 많으면 속도가 느려짐
  * 속성의 복잡도가 낮을 때 유리
