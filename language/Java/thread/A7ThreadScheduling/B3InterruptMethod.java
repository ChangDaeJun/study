package language.Java.thread.A7ThreadScheduling;

/**
 *  * [void interrupt()] & [static boolean interrupted()]
 *  * 1. interrupt()는 쓰레드의 interrupted 상태를 바꾸는 함수. 강제 종료의 의미가 아님.
 *  * 2. interrupted()는 현재 쓰레드 inteerupted를 반환 후, false로 변경
 */
public class B3InterruptMethod {
    public static void main(String[] args) {
        //쓰레드 만들기 & sleep -> 5초
        MyThread1 thread1 = new MyThread1();
        thread1.start();
        System.out.println("thread1 : " + thread1.isInterrupted());
        //main 도 2초 슬립 후 기존 쓰레드 깨우기
        try {
            Thread.sleep(2000);
        }catch (InterruptedException e){};

        thread1.interrupt();
        System.out.println("thread1 : " + thread1.isInterrupted());

        System.out.println("main end");
    }

    static class MyThread1 extends Thread{
        public void run(){
            try {
                Thread.sleep(5000);
            }catch (InterruptedException e){};
            for(int i = 0; i < 2000; i++){
                System.out.print("-");
            }
            System.out.println("");
            System.out.println("쓰레드1 종료");
        }
    }
}
