package Exception;

/**
 * [예외 처리]
 * 1. 컴파일 에러: 컴파일 시 발생하는 에러
 * 2. 런타임 에러: 실행 시 발생하는 에러
 * 3. 논리적 에러: 실행은 되지만, 의도와 다르게 동적되는 경우
 * 4. 예외 처리는 프로그램 실행 시 발생할 수 있는 예외에 대비하여 코드를 작성, 비정상 종료를 막기 위함.
 *
 */
public class A1Exception {
    public static void main(String[] args) {
        try {
            aa();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private static void aa () throws Exception{
        throw new RuntimeException();
    }
}
