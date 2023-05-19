## 함수(Function)

### 컴퓨터와 함수(Function in computer)
* 프로그래밍에서 메서드는 함수와 매우 유사하다.
```java
int function(int num){}
```
* 위 메서드는 정의역이 int이고, 치역이 int 인 함수와 동일하다.
* 만약, 내가 제작한 메서드의 정의역이 {0, 2, 4, 6, 8}이고, 치역이 {0, 1, 2, 3, ...}이라면, 이를 객체로 나타낼 필요가 있어 보인다.
```java

public Range fuction(Domain d){
    return d / 2;
}

class Range{
    private int num;
    public Range(int num){
        if(num < 0) throw Exception;
        this.num = num;
    }
}

class Domain{
    private int num;
    public Domain(int num){
        if(num % 2 != 0 || num < 0) throw Exception;
        this.num = num;
    }
}
```
* (아마도) 함수의 측면에서 자바의 메서드는 반드시 하나의 객체만을 받아, 하나의 객체만을 리턴해야 한다.