package Java.thread;

/**
 * [쓰레드 우선순위]
 * 1. 쓰레드의 우선순위에 따라 쓰레드가 얻는 실행 시간이 달라짐. 예 : 파일 전송 < 메시지 전송 이어야 함.
 * 2. 쓰레드의 우선순위는 1~10 사이, 높은 숫자일 수록 높은 우선순위.
 * 3. 쓰레드의 우선순위는 상속됨. main은 우선순위 5이며, main에서 생성된 모든 쓰레드는 자동적으로 5의 우선순위를 갖는다.
 *
 * 책[Java의 정석]의 저자는 높은 우선순위가 반드시 더 많은 실행시간과 실행기회를 갖음을 보장할 수 없다고 한다.(실제로 아래 코드는 우선순위가 높은 Thread1이 늦게 끝나는 경우가 있다. - 50%)
 * 이는 OS마다 다른 스케쥴링 정책과 JVM의 구현이 다르기에 정확하게 알 수 없다고 한다.
 * 이 대신 작업에 우선순를 두고, 우선순위 큐를 사용하는 방법이 더 나을 수 있다고 제안한다.
 */
public class A4ThreadPriority {
    public static void main(String[] args) {
        MyThread thread = new MyThread();
        MyThread1 thread1 = new MyThread1();

        thread1.setPriority(10);

        System.out.println("Priority of Thread : " + thread.getPriority());
        System.out.println("Priority of Thread1 : " + thread1.getPriority());

        thread.start();
        thread1.start();
    }

    static class MyThread extends Thread{
        public void run(){
            print("-");
        }
    }
    static class MyThread1 extends Thread{
        public void run(){
            print("|");
        }
    }
    private static void print(String m){
        for(int i = 0; i < 300; i++){
            System.out.print(m);
            for(int j = 0; j < 100000; j++){
            }
        }
        System.out.println("");
        System.out.println("print '" + m + "' end");
    }
}
