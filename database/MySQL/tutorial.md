출처 : https://dev.mysql.com/doc/refman/8.0/en/tutorial.html

### 도움말
* mysql -- help

### 서버 연결 및 연결 해제
* 로그인 : mysql - h [hostname] -u [username] -p [databaseName]// 이후 비밀번호 입력
* 로그인 완료 시 프롬프트가 mysql> 이 됨.
* 연결 해제 : QUIT(또는 \q)
* 서버의 버전과 날짜 확인 : SELECT VERSION(), CURRENT_DATE;

### 쿼리 입력
* 쿼리는 일반적으로 ;으로 끝나는 SQL문으로 구성
* 쿼리 조회시 나타나는 시간은 wall clock time이 아님. 네트워크 영향을 받음
* 대소문자를 구분하지 않는다.

### 프롬프트 별 상태 의미
* mysql> : 새 쿼리 준비
* -> : 다음 줄의 쿼리를 기다리는 중. 세미콜론이 나올때 까지 나타남.
* '> : 작은 따옴표가 닫힐 때 까지 나타남.
* "> : 큰따옴표가 닫힐때 까지 나타남.
* `> : 백틱이 닫힐때 까지 나타남.
* /*> : 다음 줄을 기다림. 주석이 끝날때 까지 나타남.(/* */)
* 쿼리를 취소하는 방법 : \c. 만약 '> 인 상태에서는 '\c.

### 데이터베이스
* 서버에 존재하는 데이터베이스 검색 : SHOW DATABASES;, 권한 없는 계정으로 실행 시 표시되지 않음
* 데이터 베이스 사용 : USE DatabaseName;
* 데이터베이스 권한 설정 : GRANT ALL ON databaseName.* TO 'mysql_name'@'client_host'
* 생성 : CREATE DATABASE databaseName; // 데이터베이스 이름은 대소문자 구분
* 모든 테이블 조회 : SHOW TABLES;
* 
### 테이블 생성
* 생성 : CREATE TABLE tableName (name1 VARCHAR(20), name2 VARCHAR(100) ... );
* 테이블 전체 표 조회 : DESCRIBE tableName;

### 테이블에 데이터 넣기
* 텍스트 파일 작성 : 각 텍스트 단일 줄에 컬럼 순서에 맞춰 작성. 컬럼 값의 구분은 탭으로 구분. null 값은 \N 사용
* 텍스트 파일로 로드 : LOAD DATA LOCAL INFILE '경로' INTO TABLE 테이블 이름;
* 윈도우의 경우 LINES TERMINATED BY '\r\n';을 추가해야 한다.
* 하나씩 추가 : INSERT INTO 테이블 이름 VALUES('', '', ...);

### 조회
* 모두 조회 : SELECT *
* 특정 칼럼 조회 : SELECT 칼럼이름1, 칼럼이름2
* 특정 로우 조회 : SELECT * WHERE 조건문(AND, OR 가능);
* 정렬 : ORDER BY 칼럼이름1, 칼럼이름2;
* 대소문자 구분 정렬 : ORDER BY BINARY 칼럼이름;
* 내림차순 정렬 : DESC;
* DATE 타입 차이 조회 : SELECT TIMEDIFF(YEAR, DATE칼럼1, DATE칼럼2). 
* 현재로부터 차이 조회 : 칼럼 2를 CURDATE()로 변경.
* DATE 타입에서 형식 변경 : MONTH(칼럼1), YEAR(칼럼) 등
* NULL 값 조회 : 비교연산자가 적용되지 않음. IS NULL, IS NOT NULL 사용
* 특정 값을 포함하는 조회 : LIKE 조건; REGEXP_LIKE(칼럼 ,정규식);
* 행 개수 : COUNT(*)
* 

### 수정
* UPDATE 데이터베이스이름 SET 변경할 컬럼이름 = '변경할 값' WHERE 조건;