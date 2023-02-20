### HttpServlet (class)
* Servlet 객체를 만들 때 extends 하는 클래스이다.
* service(), doGet(), doPost(), destroy()와 같은 콜메서드가 정의되어 있다.

### HttpServletRequest - interface
* http 서블릿 요청에 대한 정보를 제공하는 객체이며, 서블릿 컨테이너에 의해 생성되여 서블릿 서비스 메서드의 매개변수로 전달된다.
* getAttribute(String name), setAttribute(String name, Object value) : 데이터 저장, 데이터 조회를 할 수 있다.
* setCharacterEncoding(String Encoding) : 메시지 바디에 문자 데이터 인코딩을 설정한다.
* getParameter(String name) : name에 해당하는 파라미터 가져온다.
* getParameterValues(String name) : name에 해당하는 여러 파라미터 가져온다.
* getRequestDispatcher(String path) : 브라우저의 요청을 특정 경로로 이동하기 위한 RequestDispatcher 객체를 가져온다.
* getHeader(String headerName) : 요청에서 헤더 부분을 가져온다.
* getCookies() : 요청에서 쿠키 값을 쿠키 배열로 가져온다.
* getSession() : 요청에서 세션을 가져온다.

### HttpServletResponse - interface
* http 서블릿 응답에 대한 기능을 제공하는 객체이며, 서블릿 컨테이너에 의해 생성되여 서블릿 서비스 메서드의 매개변수로 전달된다.
* setContentType(String) : 응답 메시지의 데이터 형식 설정한다. 예 : UTF-8
* getWriter() : 메시지 바디와 연결된 출력 스트림을 반환한다. 반환 받은 PrintWriter 객체를 통해 메시지 바디를 작성할 수 있다.
* setStatus(int) : 응답 상태 코드를 설정한다.
* addCookie(Cookie) : 응답 값으로 쿠키를 넣는다.
* setRedirect(String) : 경로 값에 해당하는 화면을 리디렉트 응답한다.

### ServletConfig
* 초기화 중에 서블릿에 정보를 전달하기 위해 서블릿 컨테이너에서 사용하는 서블릿 구성 객체를 의미한다.
* web.xml의 해당 서블릿 객체에 <init-param>을 통해 설정할 수 있다.
```xml
<init-param>
    <param-name>boardEncoding</param-name>
    <param-value>UTF-8</param-value>
</init-param>
```
* 해당 서블릿 객체 클래스 위에 @WebServlet의 변수 initPararam을 통해 설정 가능하다.
```java
@WebServlet(initParams = @WebInitParam(name = "boardEncoding", value = "UTF-8"))
public class Servlet extends HttpServlet{
    
}
```
* 서블릿 객체에서 ServletConfig의 정보를 가져오기 위해서는 초기화 메서드인 init(ServletConfig config)메서드를 통해 가져올 수 있다.
```java
@Override
protected void init(ServletConfig config){
            String encoding = config.getInitParameter("boardEncoding");
        }
```
* getInitParameter(String name) : name 파라미터 값을 가져온다.
* Enumeration getInitParameterNames() : 여러 파라미터의 이름을 가져온다.
* getServletContext() : ServletContext 객체를 리턴한다.
* getServletName() : 서블릿 객체 이름을 리턴한다.

### ServletContext
* ServletContext는 전체 서블릿과 관련된 객체이다.
* getAttribute(String name), setAttribute(String name, Object value) : 데이터 설정, 추출한다.
* web.xml에 <context-param>을 통해 설정할 수 있다.
```xml
    <context-param>
        <param-name>boardEncoding</param-name>
        <param-value>UTF-8</param-value>
    </context-param>
```

### HttpSession, ServletConfig, HttpServletRequest을 통한 정보 전달
* 위 세 객체는 모두 동일한 메서드 setAttribute(), getAttribute()을 통해 정보를 저장하고, 불러올 수 있다.
* HttpRequest는 서블릿 컨테이너가 생성하여 매개변수로 전달하기에 포워드 방식을 통해 다른 서블릿에 정보를 전달 할 수 있다.
```java
    request.setAttribute("name", value);
    RequestDispatcher dispatcher = request.getRequestDispatcher("url");
    dispatcher.forword(request, response);
```
* 리디렉트 방식에서는 request를 전달할 수 없기에 정보를 전달할 수 없다.
* HttpSession은 각 브라우저에 대한 정보를 저장하기에 서블릿과 관계없이 정보를 저장하고, 사용할 수 있다.
* 하지만, 세션은 각 브라우저 별로 정보를 서버에 저장하기에, 많은 양을 저장할 경우 서버 메모리에 문제가 생길 수 있다.
* ServletContext는 서블릿 컨테이너가 생성될 때 생성되며, 컨테이너가 종료될 때 사라진다.
* 또한 모든 서블릿은 ServletContext에 접근할 수 있다.