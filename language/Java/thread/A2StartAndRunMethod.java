package language.Java.thread;

/**
 * [start()와 run()의 차이]
 * 1. run() : 단지 클래스에 선언된 함수를 호출
 * 2. start() : 새로운 쓰레드가 작업을 실행하는데 필요한 호출 스택을 생성한 뒤 그 위에 run()을 호출.
 *      - 이유 : 모든 쓰레드는 독립 작업을 위해 자신만의 호출 스택이 필요
 * 3. 아래 코드는 run()에서 예외를 발생시킨 후 printStackTrace()를 통해 예외가 발생한 호출 스택을 출력.
 *    start()는 새로운 호출스택에서 예외가 발생하여 run - throwException이 출력되었고,
 *    run()은 기존의 main 스택에서 예외가 발생하여 main - run - throwException이 출력되었다.
 *
 * [main 쓰레드]
 * main 메서드도 별도의 쓰레드에서 작동한다.
 * 프로그램의 종료는 main의 종료가 아닌, 실행 중인 사용자 쓰레드가 하나도 없을 때 종료된다.
 */

public class A2StartAndRunMethod {
    public static void main(String[] args) {
        MyTread tread = new MyTread();
        tread.start();

        MyTread tread1 = new MyTread();
        tread1.run();
    }
    static class MyTread extends Thread{
        public void run(){
            throwException();
        }

        public void throwException(){
            try {
                throw new RuntimeException();
            } catch (RuntimeException e){
                e.printStackTrace();
            }
        }
    }
}
