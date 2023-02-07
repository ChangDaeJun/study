### 애너테이션이란?
* 애너테이션은 주석처럼 프로그래밍 언어에 영향을 미치지 않으면서 다른 프로그램에게 유용한 정보를 제공

### 표준 애너테이션
* @Override : 메서드 앞에만 붙이며, 조상의 메서드를 오버라이딩하는 것을 컴파일러에게 알려줌 -> 컴파일 시 잘못된 오버로딩인 경우 컴파일러가 확인할 수 있음. 애너테이션 없이 오버로딩 시 실행은 가능하지만, 에러메시지를 알려주지 않는다.
* @Deprecated : 이 애너테이션이 붙은 대상은 다른 것으로 대체되었으니 더이상 사용하디 않을 것을 의미(예 : java.util.Date)
* @FunctionalInterface : 함수형 인터페이스 선언시 붙임. 오버라이딩 처럼 에러 메시지 보내줌.
* @SuppressWarnings : 경고 메시지 억제해줌. @SuppressWarnings({"deprecation", "unchecked"}) 와 같이 사용
* @SafeVarargs : static, final 메서드와 생성자에 붙임. 메서드의 가변인자 타입이 non-reifiable 인 경우 발생하는 unchecked 경고를 억제해줌.
* @Target : 애너테이션이 적용할 수 있는 대상을 지정하기 위한 애너테이션
* @Retention : 애너테이션이 유지되는 기간 지정
* @Documented : 애너테이션에 대한 정보가 javadoc으로 작성한 문서에 포함되도록 함, @Override, @SuppressWarnings을 제외한 모든 애너테이션에 붙어 있다.
* @Inherited : 애너테이션이 자손클래스에 상속되도록 함
* @Repeatable : 해당 애너테이션을 여러번 붙일 수 있도록 함
* @Native : 네이티브 메서드에 의해 참조되는 상수필드에 붙이는 애너테이션

### 애너테이션 타입 정의

```java
@interface Info {
    Date date();
    int count();
    Type type(); // enum Type{aaaa, bbbbb}
}
```
* 기본값을 설정할 수 있으며, 따로 설정하지 않으면, 요소가 가진 기본값을 사용
* 모든 애너테이션의 조상은 java.lang.annotation.Annotation이며, 상속은 불가능, 이를 통해 equals(), hashCode(), toString() 사용 가능
* 요소가 없는 애너테이션 : 마커 애너테이션(Marker Annotation)

### 애너테이션 요소 규칙
* 타입 : String, enum, 애너테이션, Class 만 사용
* 매개변수 선언 불가
* 예외 선언 불가
* 요소를 타입 매개변수로 정의 불가
