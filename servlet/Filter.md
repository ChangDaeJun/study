### 필터
* 서블릿에 요청이 가기 전, 서블릿의 응답이 클라이언트에 전송되기 전에 수행되는 객체이다.
* web.xml을 통한 등록
```xml
<filter>
	<filter-name>timeCheck</filter-name>
	<filter-class>com.ssamz.web.common.TimeCheckFilter</filter-class>
</filter>
<filter-mapping>
	<filter-name>timeCheck</filter-name>
	<url-patten>*.do</url-patten>
</filter-mapping>
```
* 어노테이션을 통한 등록 : 반드시 Filter클래스를 상속한다.
```java
@WebFilter(filterName = "timeCheck", value = "*.do")
public class TimeCheckFilter implements Filter {
    
}
```
* url patten을 통해 필터가 적용될 서블릿을 지정할 수 있다.
* 예제
```java
@WebFilter(filterName = "timeCheck", value = "*.do")
public class TimeCheckFilter implements Filter {
    public TimeCheckFilter() {
        System.out.println("timeCheck filter on");
    }

    public void init(FilterConfig config) throws ServletException {
        System.out.println("timeCheck filter init");
    }

    public void destroy() {
        System.out.println("timeCheck filter destroy");
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws ServletException, IOException {
        System.out.println("timeCheck filter doFilter start");
        chain.doFilter(request, response);
        System.out.println("사후 처리 구역");
    }
}
```
* doFilter의 매개변수 request, response는 서블릿으로 보내질, 또는 서블릿에서 나온 요청과 응답이다.
* 필터를 적용하기 위해서는 반드시 매개변수 chain에 doFilter()함수로 체인해야 한다.
* 필터도 다음과 같이 초기화 파라미터릉 사용할 수 있다.
```java
@WebFilter(filterName = "encodingFilter", value = "*.do",
			initParams = @WebInitParam(name = "boardEncoding", value = "UTF-8"))
public class TimeCheckFilter implements Filter {

}
```