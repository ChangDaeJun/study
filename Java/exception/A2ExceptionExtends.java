package Java.exception;

public class A2ExceptionExtends {
    public static void main(String[] args) {
        throw new AA("상속받아 새로 만든 예외");
    }

    static class AA extends RuntimeException{
        public AA(String message) {
            super(message);
        }
    }
}

