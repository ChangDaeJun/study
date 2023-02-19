### servlet container와 tomcat
* servlet은 인터페이스이며, tomcat은 Java Servlet, Java Server Pages, Java Websocket 등을 구현한 서블릿 컨테이너이다.
* servlet container는 동적으로 작동하는 웹서버이다.
* tomcat 내부적으로 servlet container는 catalina로 구현되어 있으며, 정적 웹서버는 coyote, JSP는 Jasper을 통해 구현하게 된다.
* 위와 같은 구조로 tomcat 자체로 웹 서버 서비스가 가능(동적 : catalina, 정적 : coyote)

### 서블릿 규칙
* 서블릿은 public 클래스이여야 한다.
* HttpServlet 클래스를 상속받아야 한다.
* 기본 생성자가 반드시 존재해야 한다.
* 콜백 메소드를 오버라이딩하여 사용한다.

### 서블릿 계층 구조
* Servlet(Interface) - GenericServlet(class) - HttpServlet(class) - 만들어야 할 서블릿(class)

### 서블릿 생성과 라이프 사이클
* 서블릿 클래스 객체는 기본적으로 lazy-loading이며, 최초 요청이 있을 때 생성된다.
* <load-on-startup>1</load-on-startup>을 통해 프리 로딩으로 변경이 가능하다.
* 서블릿 객체는 단 하나의 객체만 생성되며, 이후 요청에 대해 생성된 객체를 사용한다.
* 서블릿 컨테이너는 쓰레드 풀에서 스레드 객체 하나를 서블릿 객체에 할당하고, 스레드 객체는 서블릿의 service() 메서드를 호출한다.
* 만약 service()를 오버라이딩하지 않았다면, HttpServlet의 service()가 실행되며, 요청 방식에 맞춰 doGet, doPost 중 하나를 호출한다.
* 서블릿 객체는 최초 호출 시 객체 생성으로 인해 수행 시간이 오래 걸린다. 이후에는 객체 생성 없이 쓰레드 할당하여 빠른 수행이 가능하다.

### 서블릿 콜백 메서드
* init() : 최초 요청에 대해 디폴트 생성자를 이용하여 서블릿 객체를 생성 한 뒤 무조건 호출되는 메서드, 멤버 변수를 초기화 할 수 있음
* service() : 실질적인 사용자 요청 로직 처리, 상속하지 않으면 부모의 service() 사용되며 이로 인해 doGet 또는 doPost 사용 됨
* doGet()
* doPost()
* destroy() : 서블릿 객체 삭제 직전 호출, 서블릿 객체의 리로딩 과정에서도 호출됨