package language.Java.thread.A7ThreadScheduling;

/**
 * [yield()]
 * 자신에게 주어진 실행시간을 다음 쓰레드에게 양보. static.
 *
 * [join()]
 * 하던 작업을 잠시 멈추고, 지정 시간동안 다른 쓰레드가 작업 수행할 수 있게 해줌.
 */
public class B5YieldJoinMethod {
    public static void main(String[] args) {
        MyThread1 thread1 = new MyThread1();
        MyThread2 thread2 = new MyThread2();

        thread1.start();
        thread2.start();

    }

    static class MyThread1 extends Thread{
        public void run(){
            Thread.yield();
            for(int i = 0; i < 10000; i++){
                Thread.yield();
                System.out.print("*");
            }
            System.out.println("");
            System.out.println("language.Java.thread 1 end");
        }
    }

    static class MyThread2 extends Thread{
        public void run(){
            for(int i = 0; i < 10000; i++){
                System.out.print("+");
            }
            System.out.println("");
            System.out.println("language.Java.thread 2 end");
        }
    }
}
