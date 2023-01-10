package thread.A7ThreadScheduling;

/**
 *  * [suspend()] & [resume()] & [stop()] - deprecated! 된 함수(데드락 발생 가능성을 높임)
 *  * 1. suspend(): 쓰레드를 멈춤.
 *  * 2. resume(): 멈춘 쓰레드를 실행.
 *  * 3. stop(): 쓰레드 즉시 종료.
 */
public class B4SuspendResumeStopMethod {
    public static void main(String[] args) {
        //쓰레드 만들기 & sleep -> 5초
        B3InterruptMethod.MyThread1 thread1 = new B3InterruptMethod.MyThread1();
        thread1.start();

        thread1.suspend();
        System.out.println("쓰레드 멈춤");
        try {
            Thread.sleep(3000);
        }catch (InterruptedException e){};
        thread1.resume();
        System.out.println("쓰레드 다시 시작");
        try {
            Thread.sleep(5000);
        }catch (InterruptedException e){};
        thread1.stop();

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
