## 저장 프로그램(Stored Program)
* 저장 프로그램 : 저장 루틴, 트리거, 이벤트
* 저장 루틴 : 프로시저, 함수
* 프로시저 : 작업 순서가 정해진 독립된 프로그램 수행 단위

### 프로시저
* 선언부와 실행부 : BEGIN - END
* 주석 : /**/ 또는 --
* 정의 시작 : CREATE PROCEDURE
* 프로시저 안의 명령어 종료를 뜻하는 ; 와 구분하기 위해 구문 구분자 설정 : delimiter
* ```
    delimiter //
    CREATE PROCEDURE dorepeat(p1 INT)
    BEGIN
    SET @x = 0;
    REPEAT SET @x = @x + 1; UNTIL @x > p1 END REPEAT;
    END
    //
  
    Query OK, 0 rows affected (0.00sec)
    
    delimiter;
  ```
* 프로시저 삭제 : DROP PROCEDURE 이름
* 프로시저 제어문
  * DELIMITER : 구문 종료 기호 설정
  * BEGIN - END : 프로그램 문을 블록화, 중첩 가능
  * IF - ELSE
  * LOOP
  * WHILE
  * REPEAT
  * RETURN

### 트리거
* 트리거 : 데이터의 변경문이 실행될 때 자동으로 실행되는 프로시저

### 샤용자 정의 함수
* 별도로 함수를 정의하여 사용할 수 있다.

## DB - java 연동
* jdbc : 각 DBMS 제조사에서 제품에 맞게 구현한 API, java.sql.*;
```java
import java.io.*;
import java.sql.*;

public class BookList{
    Connection conn;
    
    public BookList(){
        String Driver = "";
        String url = "jdbc://localhost:3306/db이름";
        String userid = "userid";
        String password = "password";
        
        //드라이버 존재 여부 확인
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        }catch (ClassNotFoundException e){
            e.printStackTrace();
        }
        
        //url에 id와 password를 통해 접속, conn에 결과값 보냄
        try {
            conn = DriverManager.getConnection(url, userid, password);
        }catch (SQLException e){
            e.printStackTrace();
        }
    }
    
    public void sqlRun(String query){
        try {
            //상태 생성
            Statement statement = conn.createStatement();
            //쿼리문 실행 후 결과를 받아옴.
            ResultSet resultSet = statement.executeQuery(query);
            
            //결과 집합에서 row 10 을 가져옴
            resultSet.getInt(10);
            
            conn.close();
        }catch (SQLException e){
            e.printStackTrace();
        }
    }
}
```