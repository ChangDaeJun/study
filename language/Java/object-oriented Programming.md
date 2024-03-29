### 클래스, 객체, 인스턴스의 차이
* 클래스 : 객체 생성을 위한 청사진(blueprint)
* 객체 : 클래스의 인스턴스, 모든 인스턴스를 대표하는 포괄적 의미
* 인스턴스 : 구체적으로 구현된 실체, 메모리에 적제된 상태(?)

### 변수의 종류
* 클래스 변수 : static 선언, 모든 인스턴스가 공통된 저장공간을 공유, 클래스가 메모리에 적제 시 생성
* 인스턴스 변수 : 일반적인 선언, 각 인스턴스가 독립된 저장공간을 갖음, 인스턴스 생성시 생성
* 지역 변수 : 메서드 내 선언, 메서드 종료 시 소멸, 변수 선언문 실행 시 생성
* 기본형 매개변수 : 변수의 값만 읽을 수 있음
* 참조형 매개변수 : 값을 읽고 변경 가능

### JVM 메모리 구조
* Method Area : 클래스 데이터 저장(클래스 변수도 저장)
* Call stack : 메서드 작업에 필요한 메모리 공간, 지역변수, 매개변수 등 저장
* Heap : 프로그램 실행 중 생성되는 모든 인스턴스 저장

### 오버로딩
* 이름은 같지만, 매개변수의 개수나 타입이 다른 여러개의 메서드를 정의하는 것
* 반환타입은 오버로딩의 조건에 포함되지 않는다. 반환타입이 달라도, 매개변수가 동일하면 오버로딩 되지 않는다. 
* 가변인자는 오버로딩 시 메서드 구분에 혼동이 올 수 있다. 사용에 주의

### 가변인자(args)
* 매개변수의 개수를 동적으로 지정해줄 수 있는 기능
* 매개변수 선언 시 String... args 처럼 선언

### 생성자
* 인스턴스의 생성은 생성자가 아닌 연산자 new 이다.
* 작동 절차 : 연산자 new 는 메모리에 인스턴스 생성 -> 생성자 실행 -> 변수에 주소 저장
* 기본 생성자 : 컴파일 시 클래스에 생성자가 하나도 존재하지 않으면 컴파일러가 자동으로 기본 생성자를 추가하여 컴파일
* 생성자에서 다른 생성자를 호출 : this(a, b, c) 사용, 반드시 첫 줄에서만 호출 가능
* this : 인스턴스 자신을 가리키는 참조변수, 모든 인스턴스에는 지역변수로 숨겨져 있음.
* 생성자는 리턴값을 만들 수 없다.

### 초기화 블럭
* 클래스 초기화 블럭 : static {} 사용
* 인스턴스 초기화 블럭 : {} 사용
* 생성자보다 인스턴스 초기화 블럭이 먼저 수행
* 여러 생성자를 만들 때 코드 중복을 낮출 수 있다.

### 초기화 순서
* 클래스 변수 : 기본값 -> 명시적 초기화 -> 클래스 초기화 블럭
* 인스턴스 변수 : 기본값 -> 명시적 초기화 -> 인스턴스 초기화 블럭 -> 생성자

### 상속
* 생성자와 초기화 블럭은 상속되지 않음.
* 클래스 상속 관계 : is - a // 포함관계 : has - a
* 자바는 단일 상속만 지원
* Oject 클래스는 모든 클래스의 조상이다. 컴파일 단계에서 자동으로 상속하도록 함

### 오버라이딩
* 조상 클래스로부터 상속받은 메서드 내용을 변경하는 것
* 조건1 : 같은 이름, 같은 매개변수, 같은 반환타입
* 조건2 : 접근 제어자는 조상클래스의 메서드보다 좁아질 수 없다.(조상 : public -> 자손 : private 금지)
* 조건3 : 조상 클래스 메서드보다 많은 수의 예외 선언 불가
* 조건4 : 인스턴스 <-> static 변경이 불가

### super
* 부모 클래스의 멤버를 참조하는데 사용되는 참조 변수

### 패키지
* 패키지 : 클래스의 묶음
* 클래스의 전체 이름은 패키지명을 포함한 것이다.
* 하나의 소스파일의 첫 문장에 단 한번 패키지 선언이 가능하다.
* 모든 패키지는 빈드시 하나의 패키지에 속해야 한다.

### import
* 패키지 선언과 클래스 선언 사이에 작성
* 클래스 이름 대신 *을 사용가능, 성능상의 차이 없음
* static import 사용 시 클래스 명 표기 생략가능

### 제어자
* 그 외 : static, final, abstract, native, transient, synchronized, volatile, strictfp
* 제어자는 클래스, 멤버변수, 메서드에 주로 사용, 여러 제어자 조합 가능, 단 접근 제어자는 하나만 사용 가능
* static : 클래스의, 공통적인
* final : 마지막의, 변경될 수 없는
* abstract : 추상의, 미완성의

### 접근 제어자
* public(제힌 없음), protected(같은 패키지, 다른 패키지의 자손 클래스), default(같은 패키지), private(같은 클래스)
* 생성자를 private 하게 하여 인스턴스 생성을 막을 수 있음. -> 싱글톤 기법

### 다형성
* 조상클래스 타입의 참조변수로 자손클래스의 인스턴스를 참조할 수 있다.
* 참조변수가 사용할 수 있는 멤버의 개수는 인스턴스 멤버 변수보다 작거나 같아야 한다.
* 형변환은 참조변수의 타입만을 변화하는 것이기에 인스턴스에 영향 X, 단지, 인스턴스에서 사용할 수 있는 멤버의 범위를 조절
* instanceof : 인스턴스의 실제 타입읠 알아보기 의한 연산자

### 추상클래스
* 추상클래스 : 추상메서드를 가지고 있는 클래스
* 추상메서드 : 선언부만 작성하고, 구현부는 작성하지 않은 메서드, abstract 로 선언

### 인터페이스
* 추상 메서드와 상수만을 갖음.
* 모든 멤버변수는 public static final 이여야 하며 생략 가능
* 모든 메서드는 public abstract 이여야 하며, 생략 가능
* 인터페이스는 다중 상송 가능
* 인터페이스의 구현은 implements

### 내부 클래스
* 내부 클래스에서 외부 클래스 멤버를 쉽게 접근, 코드의 복잡성 감소
* 인스턴스 클래스, 스태틱 클래스, 지역 클래스, 익명 클래스