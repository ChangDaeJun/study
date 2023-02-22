### 시작하기
* .jsp 확장자를 사용하는 파일을 생성한다.
```jsp
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>JSP - Hello World</title>
</head>
<body>
<h1><%= "Hello "+request.getSession().getAttribute("userId")+" World!" %>
</h1>
<br/>
<a href="hello-servlet">Hello Servlet</a>
<a href="insertUser.html">insert USER</a>
<a href="getBoardList.do">board List</a>
</body>
</html>
```

### JSP 이해
* 서블릿에서 자바코드을 이용하여 HTML 작성의 어려움을 극복하고자, HTML에서 자바코드를 작성할 수 있도록 지원하는 것. 
* 서버는 JSP 파일을 서블릿 클래스로 변환한 뒤 변환된 클래스를 서블릿 컨테이너에 의해 생성되고 관리된다.
* 즉, jsp는 서블릿 클래스로 변환되어 사용되기에, 통신 과정이 서블릿과 동일하다.