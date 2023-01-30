package Java.variable;

public class Variable {
    public static void main(String[] args) {
        //변수의 선언
        int number;

        //변수의 선언 및 초기화
        int number1 = 10;

        /**
         * 변수 명명규칙
         * 1. 대소문자가 구분되며, 길이 제한은 없다.
         * 2. 예약어는 사용 불가.
         * 3. 숫자로 시작 불가.
         * 4. 특수문자는 '_'와 '$'만 사용 가능.
         */

        //대소문자 구분
        int Abc = 10;
        int abc = 11;

        //길이에 제한 없음
        int fsfesfesfuhaefeaiojfoeiasfoiaehroiaewhorifhaeoifhesiofhesiofeiosdjfioedsjgiorhgosrehgoieahioeajiorjeaoijtfoiaesjfioesjgioehgoiioghrsioeio = 10;

        //예약어 사용 불가
        int false = 0;

        //숫자로 시작 불가
        int 10number = 10;

        //특수기호는 _, $ 만 가능
        int _abc$$ = 10;
        int !!!e = 10;
    }
}
