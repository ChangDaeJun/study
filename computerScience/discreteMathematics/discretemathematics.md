## 집합(set)

### 수학과 컴퓨터에서의 집합(Set in Math and Computer)
| 구분            | 수학(Math)            | 컴퓨터(computer)      |
|---------------|---------------------|--------------------|
| 표기(write)     | N = {1, 2, 3, ...}  | Boolean = {0, 1}   |
| 연산자(operator) | 덧셈(+), 뺄셈(-), 곱셈(*) | AND, OR, NOT |

### JAVA 데이터형의 집합 표현(Represent data type in Java as a set)
| 타입(Type) | 표현                                          |
|---------|---------------------------------------------|
| Boolean | {0, 1}                                      |
| Int     | {–2,147,483,648, ...., 0, 1, 2, ... 2,147,483,647} |
| Char    | {0, 1, 2 , ... , 2^16}                      |
| String  | Char^n의 멱집합(power set of char ^ n)          |
| Float   | Boolean(1bit) X (8bit) X (23bit)            |
| Double  | Boolean(1bit) X (11bit) X (52bit)           |


### 비트열 연산 (bitwise)
* 컴퓨터에서는 집합의 부분집합을 비트열로 표현할 수 있다.
* 예를 들어 U = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}의 짝수 부분집합 A는 다음과 같이 표현된다.
* A = 0101010101 = {2, 4, 6, 8, 10}
* 비트열로 부분집합을 표현할 경우 장점은 차집합, 교집합, 여집합 등을 컴퓨터 연산자(AND, OR, XOR)으로 구할 수 있다.
* 예
```
When U = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, A = {2, 4, 6, 8, 10}, B = {2, 3, 5, 10}
A is 0101010101, B is 0110100001.

A union B (OR)
0101010101
0110100001
----------
0111110101

A Intersection B(AND)
0101010101
0110100001
----------
0100000001

(A Union B) - (A Intersection B) (XOR)
0101010101
0110100001
----------
0011110100

```
* 해당 디렉토리의 Bitwise.java 을 참고. https://github.com/ChangDaeJun/study/blob/main/computerScience/discreteMathematics/Bitwise.java

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
* (개인적 추측) 함수의 측면에서 자바의 메서드는 반드시 하나의 객체만을 받아, 하나의 객체만을 리턴해야 한다.