### 톰캣 설치
* tomcat 홈페이지 접속 : https://tomcat.apache.org/, 원하는 버전 설치
* 톰캣 10 이상은 jakarta EE의 구현체, java EE의 구현은 톰캣 9 이하로 사용.
* 맥의 경우 tar.gz 을 받아 압축을 풀어준 뒤, 해당 폴더를 톰캣 경로로 지정해 줄 수 있다.
* 터미널에서는 bin 폴더의 ./startup.sh ./shupdown.sh 으로 시작과 종료를 할 수 있다.

### java EE(jakarta EE) 설치
* java ee는 자바를 이용한 서버 개발을 위한 플랫폼. 이 안에 JSP, Servlet에 대한 인터페이스 존재
* 이클립스는 ee 버전을 다운 받아 설치 가능
* 인텔리제이의 경우 커뮤니티 에디션이 Java ee를 지원하지 않는다. 왠만하면 ultimate 에디션으로 사용하는 것을 권장

### Servlet 시작하기
* Servlet은 HttpServlet을 상속받은 클래스에 @WebServlet 어노테이션을 추가하여 서블릿 설정과 요청 경로를 설정할 수 있다.
``` java
@WebServlet(name = "helloServlet", value = "/hello-servlet")
public class HelloServlet extends HttpServlet {
...
}
```
* 또는 web-INF에 있는 web.xml에 서블릿의 경로와 이름을 설정할 수 있다.
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
* servlet 객체에는 doGet(), doPost(), service() 등의 콜메서드를 오버라이딩하여 서블릿 요청을 처리할 수 있다.
``` java
@WebServlet(name = "helloServlet", value = "/hello-servlet")
public class HelloServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest requst, HttpServletResponse response){
        //내부구현
    }
}
```
* 요청받은 정보는 HttpServletRequest를 통해 받을 수 있으며, HttpServletResponse을 통해 응답을 넘겨줄 수 있다.