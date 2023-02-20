### Cookie
* 상태 정보를 브라우저가 설치된 컴퓨터에 저장하는 기술이다.(즉, 클라이언트에 저장)
* 쿠키는 클라이언트에 저장되기에, 임의로 정보를 보거나 조작이 가능하다.
* 쿠키 생성 : new Cookie("name", value)으로 생성하여, response에 넣는다.
```java
    Cookie userId = new Cookie("userId", user.getId());
    response.addCookie(userId);
```

* 쿠키 검증 : request을 통해 쿠키 배열을 받아, 배열에서 필요한 쿠키를 찾는다.
```java
    Cookie[] cookies = request.getCookies();
    if (cookies == null){
        response.sendRedirect("login.html");
    }else {
        String userId = null;
        for(Cookie cookie : cookies){
            if(cookie.getName().equals("userId")){
                userId = cookie.getValue();
            }
        }
        if(userId == null){
            response.sendRedirect("login.html");
        }
    }
```
* setDomain() : 다른 도메인으로 등록된 서버에 요청할 때도 쿠키 정보를 전송할 수 있다.
* setPath() : 특정 경로에 대한 요청에만 쿠키를 보낼 수 있도록 설정한다. 하위 경로에는 모두 포함된다.
* setMaxAge() : 쿠키의 유효시간을 설정할 수 있다. 기본값은 -1로써 브라우저가 열려있는 동안 유지된다.


### Session
* 상태 정보를 서버에 저장하는 기술이다. 클라이언트에는 세션 ID를 넘겨주게 된다.
* 브라우저마다 하나의 세션만 존재하게 된다.
* 세션 생성 : request.getSession을 통해 세션을 받은 뒤, session.setAttribute(키, 값)으로 설정한다.
```java
    HttpSession session = request.getSession();
    session.setAttribute("userId", user.getId());
```
* 세션 검증 : request에서 세션을 얻은 뒤, session.getAttribute(키)로 얻는다.
```java
    HttpSession session = request.getSession();
    String userId = (String) session.getAttribute("userId");
    if (userId == null){
    response.sendRedirect("/");
    }
```
* 세션은 기본적으로 브라우저가 종료될 때까지 유지된다.
* setMaxInactiveInterval(int second) : 세션 만료시간을 설정할 수 있다.
* invalidate() : 특정 시점에 브라우저와 매핑된 세션을 강제종료시킨다.
```java
@WebServlet(name = "LogoutServlet", value = "/LogoutServlet")
public class LogoutServlet extends HttpServlet {

    private static final long serialVersionUID = 1L;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.invalidate();

        response.sendRedirect("/");
    }
}
```