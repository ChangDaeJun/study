### 열거형(enum)
* 서로 관련된 상수를 편리하게 선언하기 위한 것으로 여러 산수를 정의할 때 사용하면 유용

```java
class Card{
    static final int CLOVER = 0;
    static final int HEART = 1;
    static final int DIAMOND = 2;
    static final int SPADE = 3;
    
    static final int TWO = 0;
    static final int THREE = 1;
    static final int FOUR = 2;
}
```
->
```java
class Card{
    enum Kind {CLOVER, HEART, DIAMOND, SPADE}
    enum Value {TWO, THREE, FOUR}
    
    final Kind kind;
    final Value value;
}
```
* 자바의 열거형은 타입에 안전한 열거형 -> 상수값이 같아도 타입이 다르다면, 컴파일 에러 발생
* 선언 : enum 열거형이름 {상수1, 상수2, 상수3 ...};
* 사용 : 열거형이름.상수명
* 모든 열거형은 java.lang.Enum의 자손
* 열거형 상수값 지정 : 상수명(10) 와 같이 숫자 표기

### 열거형의 추상메서드
* 추상메서드를 선언 후 각 상수별로 메서드를 구현할 수 있다.
```java
enum Transportation{
    BUS(1500) {int fare(int distance){ return distance*BASIC_FARE;}},
    TRAIN(1300) {int fare(int distance){ return distance*BASIC_FARE;}},
    SHIP(10000) {int fare(int distance){ return distance*BASIC_FARE;}},
    AIRPORT(99000) {int fare(int distance){ return distance*BASIC_FARE;}};
    
    protected final int BASIC_FARE;
    
    Transportation(int basicFare){
        BASIC_FARE = basicFare;
    }
    
    abstract int fare(int distance);
}
```

### 열거형의 이해 / 열거형의 구현
* 열거형은 내부적으로 추상클래스, Comparable 구현.