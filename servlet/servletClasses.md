### HttpServlet (class)
* Servlet 객체를 만들 때 extends 하는 클래스이다.
* service(), doGet(), doPost(), destroy()와 같은 콜메서드가 정의되어 있다.

### HttpServletRequest - interface
* http 서블릿 요청에 대한 정보를 제공하는 객체이며, 서블릿 컨테이너에 의해 생성되여 서블릿 서비스 메서드의 매개변수로 전달된다.
* getAttribute(String name), setAttribute(String name, Object value) : 데이터 설정, 추출
* setCharacterEncoding(String Encoding) : 메시지 바디에 문자 데이터 인코딩 설정
* getParameter(String name) : name에 해당하는 파라미터 가져옴
* getParameterValues(String name) : name에 해다아는 여러 파라미터 가져옴
* getServletContext() : servletContext 객체 가져옴
* getRequestDispatcher(String path) : 브라워의 요청을 특정 경로로 이동하기 위한 RequestDispatcher 객체 리턴
* getHeader(String headerName)
* getCookies()
* getSession()

### HttpServletResponse - interface
* http 서블릿 응답에 대한 기능을 제공하는 객체이며, 서블릿 컨테이너에 의해 생성되여 서블릿 서비스 메서드의 매개변수로 전달된다.
* setContentType(String) : 응답 메시지 데이터 형식 설정
* getWriter() : 메시지 바디와 연결된 출력 스트림 리턴
* setStatus(int) : 상태 코드 설정
* addCookie(Cookie) : 헤더 값으로 쿠키 추가
* setRedirect(String) : 경로 값에 해당하는 화면을 다시 요청

### ServletConfig
* 초기화 중에 서블릿에 정보를 전달하기 위해 서블릿 컨테이너에서 사용하는 서블릿 구성 객체를 의미한다.
* web.xml의 해당 서블릿 객체에 <init-param>을 통해 설정
```xml
<init-param>
    <param-name>boardEncoding</param-name>
    <param-value>UTF-8</param-value>
</init-param>
```
* 해당 서블릿 객체 클래스 위에 @WebServlet의 변수 initPararam을 통해 설정 가능
```java
@WebServlet(initParams = @WebInitParam(name = "boardEncoding", value = "UTF-8"))
public class Servlet extends HttpServlet{
    
}
```
* 서블릿 객체에서 ServletConfig의 정보를 가져오기 위해서는 init(ServletConfig config)메서드를 통해 가져올 수 있다.
```java
@Override
protected void init(ServletConfig config){
            String encoding = config.getInitParameter("boardEncoding");
        }
```
* getInitParameter(String name) : name 파라미터 값을 가져옴
* Enumeration getInitParameterNames() : 여러 파라미터의 이름 가져옴
* getServletContext() : ServletContext 객체 리턴
* getServletName() : 서블릿 객체 이름 리턴

### ServletContext
* ServletConfig는 단일 서블릿과 연관된 객체, ServletContext는 전체 서블릿과 관련된 객체
* getAttribute(String name), setAttribute(String name, Object value) : 데이터 설정, 추출 
* web.xml에 <context-param>을 통해 설정
```xml
    <context-param>
        <param-name>boardEncoding</param-name>
        <param-value>UTF-8</param-value>
    </context-param>
```