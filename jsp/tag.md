### 주석문
* JSP에서 사용할 수 있는 주석은 2가지로 HTML에서 사용하는 \<!-- 주석 --> 과 JSP에서 지원하는 <%-- 주석 --%>이다.
```jsp
 <!-- html 주석 예시 -->
 <%-- JSP 주석 예시 --%>
```
* JSP 주석은 JSP가 서블릿으로 변환할때 사라지지만, html 주석은 사라지지 않는다.

### 지시자
* page : JSP가 서블릿으로 변환할 떄 필요한 정보들 성정한다.
```jsp
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" 
    isErrorPage ="true"
    errorPage = "errors/board.jsp"
    import = "java.util.Math"
    session = "true" %>
```
* include : 반복되는 페이지를 여러 조각으로 분리하여 작성할 수 있다.(예 : footer, header)
```jsp
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>

<%@ include file= "../header.jsp" %>

<%@ include file= "../footer.jsp" %>
```

### 수행문
* HTML 태그 중심의 JSP를 동적파일로 만들어주는 태그이다.
* <% %> 태그 사이에 자바 코드를 입력할 수 있다.
```jsp
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ page import= "java.util.*" %>

<% 
    List<String> list = new ArrayList<>();
    list.add(1);
    list.add(2);
%>
```

### 표현식
* 변수에 저장된 값이나 메소드가 리턴한 값을 브라우저의 특정 위치에 출력할 수 있다.
```jsp
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ page import= "java.util.*" %>

<% 
    List<String> list = new ArrayList<>();
    list.add(1);
    list.add(2);
%>

<h1><%= list.toString() %></h1>
```

### 선언문
* JSP 파일이 서블릿으로 변환되면서 멤버 변수나 메소드를 선언할 때 사용한다.