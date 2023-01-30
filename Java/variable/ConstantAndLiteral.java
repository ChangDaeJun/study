package Java.variable;

public class ConstantAndLiteral {
    public static void main(String[] args) {
        //상수는 값이 변하지 않는 수, final 사용, 변수명은 대문자
        final int MAX = 10;

        //리터럴은 수가 가진 그 값 자체를 의미, 예 : 변수 a의 리터럴은 10이다.
        int a = 10;

        //long, float의 접미사
        long b = 1L;
        float w = 2f;

        //2진수 ~ 16진수의 접두사
        long b2 = 0b0101;
        long b8 = 072043;
        long b16 = 0x13553;

        //문자 사이에 구분자 사용 가능
        int num = 100_000_000;

        float c = 3.14e3f; // == 3140.0f
    }
}
