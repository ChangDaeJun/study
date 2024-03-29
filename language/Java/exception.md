### 에러와 예외
* 에러 : 프로그램 코드에 의해 수습할 수 없는 오류 -> 컴파일 에러, 메모리 에러, 논리적 에러
* 예외 : 프로그램 코드에 의해 수습될 수 있는 오류 -> I/O 예외, 런타임 예외

### 예외 처리하기
* 예외를 처리하지 않으면, 프로그램은 비정상적을로 종료되며, JVM 의 예외 처리기가 받아서 원인을 화면에 출력
* 예외를 처리하는 방법 : try - catch 사용
* catch의 괄호에는 처리하고자 하는 예외의 참조변수를 하나 이상 선언해야 한다.
* 예외 발생 당시의 호출 스택에 있는 메서드 정보와 예외 메서지 출력 : printStackTrace()
* 예외 메세지 얻기 : getMessage()
* 멀티 catch 블록 : |을 사용하여 여러 예외에 대해 하나의 참조변수 지정이 가능하다. 다만, 두 예외가 상속관계어서는 안된다.
* 예외 처리의 결과와 상관없이 실행되어야 하는 코드 작성 : finally블럭 사용
* 자동 자원 반환 : try-with-resources

### 예외 발생시키기
* 발생 : throw new Exception("예외 메시지")
* 메서드에 예외 선언 : throws Exception

### 사용자 정의 예외
* extends Exception, RuntimeException 사용, 생성자 매개변수로 msg 보내야 함

### 예외 던지기
* try-catch문을 통해 예외를 처리 한 후 다른 처리가 필요한 경우 catch 문에서 throw로 예외를 다시 날릴 수 있다.
* 연결된 예외 : 한 예외가 다른 예외를 발생. : initCause(e);