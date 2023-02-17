### 톰캣 설치
* tomcat 홈페이지 접속 : https://tomcat.apache.org/
* 좌측 메뉴 중 원하는 버전 다운로드 찾아 클릭.
* 버전 : 자카르타 ee 의 경우 10 이상의 버전을 사용하자.(9로 할 경우 충돌 나더라)
* tar.gz -> 압축해제.
* 이후 톰켓을 사용하는 곳에서 해당 폴더를 경로 설정해주면 됨.
* 터미널 실행 : bin 폴더에서 ./startup.sh ./shupdown.sh 으로 시작, 종료

### java EE
* 인텔리제이 커뮤니티 버전에서는 정식 지원을 하지 않는다. 자동 완성의 이점이 없으니, 추천하지 않음.
* 인텔리제이 ultimate 에서는 프로젝트 생성 단계에서 간단하게 Jakarta EE 프로젝트로 생성하여 만들 수 있다.

### 기본적인 구조
* src > main > java 밑에 자바 코드 구성
* src > main > webapp 에 jsp, html 존재
* Servlet은 @WebServlet을 통해 요청 경로를 설정할 수 있다.
``` java
@WebServlet(name = "helloServlet", value = "/hello-servlet")
public class HelloServlet extends HttpServlet {
...
}
```
* 또는, web-INF에 있는 web.xml에 별도로 추가하여 경로와 이름을 설정할 수 있다.
``` xml
<servlet>
    <servlet-name>helloServlet</servlet-name>
    <servlet-class>com.study1.jsp4.HelloServlet</servlet-class>
</servlet>
<servlet-mapping>
    <servlet-name>helloServlet</servlet-name>
    <servlet-class>/helloServlet</servlet-class>
</servlet-mapping>
```

### 톰켓 서버
* 톰캣 역시 자바로 작성된 서버 -> 클래스 객체 생성이 가능함.
* 톰켓 서버는 웹서버와 서블릿 컨테이너로 구성. 각 정적 컨텐츠, 동적 컨텐츠를 처리한다.
* 동적 컨텐츠는 서블릿 컨테이너가 처리 해준다. 서블릿 컨테이너는 클래스를 생성하고 관리

### 서블릿 규칙
* javax.servlet, javax.servlet.http import 혹은 jakarta. *
* public 클래스 선언
* HttpServlet 상속
* 기본 생성자 필수
* 콜백 메소드 오버라이딩

### 서블릿 계층 구조
* Servlet(Interface) - GenericServlet(class) - HttpServlet(class) - 만들어야 할 서블릿 클래스

### 서블릿 생성과 라이프 사이클
* 콜백 메서드 : 특정 시점에 서블릿 컨테이너가 자동으로 호출해주는 메소드
* 서블릿 클래스 객체는 lazy-loading으로, 서버 요청이 있을 때 새성
* <load-on-startup>1</load-on-startup>을 통해 프리 로딩으로 변경 가능
* 서블릿 객체는 단 하나의 객체만 생성
* 쓰레드 풀 : 서블릿 컨테이너가 생성한 다수의 스레드 객체가 등록, 스레드 객체가 서블릿의 service() 메서드 호출
* 서블릿 객체는 최초 호출 시 객체 생성으로 인해 수행 시간이 오래 걸림, 그 이후에는 생성된 객체의 쓰레드 풀을 사용하여 service()메서드만 반복적으로 실행

### 서블릿 콜백 메서드
* init() : 최초 요청에 대해 디폴트 생성자를 이용하여 서블릿 객체를 생성 한 뒤 무조건 호출되는 메서드, 멤버 변수를 초기화 할 수 있음
* service() : 실질적인 사용자 요청 로직 처리, 상속하지 않으면 부모의 service() 사용되며 이로 인해 doGet 또는 doPost 사용 됨
* doGet() 
* doPost()
* destroy() : 서블릿 객체 삭제 직전 호출, 서블릿 객체의 리로딩 과정에서도 호출됨