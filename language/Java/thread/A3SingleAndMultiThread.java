package language.Java.thread;

/**
 * [싱글 쓰레드, 멀티 쓰레드]
 * 1. 아래 코드 실행 시 멀티쓰레드는 약 52m/s, 싱글쓰레드는 약 54m/s으로 큰 차이를 보이지 않는다.
 * 2. 하나의 print 함수가 약 25m/s 소모되는 것을 보아 멀티쓰레드는 최대 25m/s을 기대할 수 있었으나 그러지 못했다.
 * 3. 이는 두 쓰레드가 동일한 자원을 놓고 경쟁을 하게 된 결과로 보인다.(아마 System.out)
 * 4. 자원 경쟁을 줄이기 위해 멀티쓰레드 cpu 환경에서 n을 20억번 더하는 plus를 통해 확인해보면, 멀티 쓰레드가 약 86m/s, 싱글 쓰레드가 약 350m/s 소요되었다.
 */

public class A3SingleAndMultiThread {
    public static void main(String[] args) {
        //문자열 출력
        singleThread1();
        multiThread1();

        //덧셈 연산
        singleThread2();
        multiThread2();
    }

    public static void singleThread1(){
        System.out.println("singleThread 1 : " + print1());
        System.out.println("singleThread 2 : " + print2());
    }

    public static void multiThread1(){
        MyThread thread = new MyThread();
        thread.start();
        System.out.println("multiThread 2: " + print2());
    }

    public static void singleThread2(){
        System.out.println("singleThread 1 : " + plus(2));
        System.out.println("singleThread 2 : " + plus(3));
    }

    public static void multiThread2(){
        MyThread1 thread = new MyThread1();
        thread.start();
        System.out.println("multiThread 2: " + plus(3));
    }

    private static long print1() {
        long start = System.currentTimeMillis();

        for(int i = 0; i < 10000; i++){
            System.out.printf("%s", new String("-"));
        }

        System.out.println("");
        return System.currentTimeMillis() - start;
    }

    private static long print2() {
        long start = System.currentTimeMillis();

        for(int i = 0; i < 10000; i++){
            System.out.printf("%s", new String("|"));
        }

        System.out.println("");
        return System.currentTimeMillis() - start;
    }

    private static long plus(int n){
        long start = System.currentTimeMillis();

        int num = n;
        for(int i = 0; i < 2000000000; i++){
            num += n;
        }

        System.out.println(num);
        return System.currentTimeMillis() - start;
    }

    static class MyThread extends Thread{
        public void run(){
            System.out.println("multiThread 1: " + print1());
        }
    }
    static class MyThread1 extends Thread{
        public void run(){
            System.out.println("multiThread 1: " + plus(2));
        }
    }
}
