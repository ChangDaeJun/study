package language.Java.thread;

/**
 * [쓰레드 구현 방법]
 *  1. extends Thread - MyThread1, 그대로 객체 인스턴스 생성 후 start() 사용.
 *  2. implements Runnable - MyThread, Runnable 객체 인스턴스로 생성 후 Thread 클래스에 넣어 start() 사용.
 *
 *  [getName()] : Thread 클래스에 존재
 *  1. Thread를 직접 상속받은 MyThread1는 getName() 사용 가능
 *  2. runnable의 구혀네인 MyThread는 Thread의 static 메서드 currentThread()을 통해 getName() 사용 가능.
 *
 *  [쓰레드 이름 지정]
 *  1. 생성자 지정 : Thread(Runnable r, String threadName), Thread(String threadName)
 *  2. set 메서드 : setName(String threadName)
 *
 *  [쓰레드는 재사용 불가능]
 *  반드시 한번 사용 뒤 다시 생성하여 사용(start)해야 한다.
 */

public class A1GetStart {
    public static void main(String[] args) {
        Runnable runnable = new MyThread();
        Thread thread = new Thread(runnable, "implements runnable language.Java.thread");

        MyThread1 thread1 = new MyThread1("extends Thread");

        thread.start();
        thread1.start();
    }
    static class MyThread implements Runnable{
        @Override
        public void run() {
            for(int i = 0; i < 10; i++){
                System.out.println(Thread.currentThread().getName());
            }
        }
    }

    static class MyThread1 extends Thread{
        public MyThread1(String threadName) {
            super(threadName);
        }

        @Override
        public void run() {
            for(int i = 0; i < 10; i++){
                System.out.println(getName());
            }
        }
    }
}
