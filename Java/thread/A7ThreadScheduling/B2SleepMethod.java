package Java.thread.A7ThreadScheduling;

/**
 *  * [static void sleep()]
 *  * 1. sleep()은 쓰레드를 일정 시간 일시정지 시킬 수 있다. 일정 시간 이후, 또는 인터럽트가 발생 시 [RUNNABLE] 상태가 된다.
 *  * 2. 인터럽트 발생을 처리하기 위해 sleep()은 try - catch 로 감싸줘야 함.
 *  * 3. sleep()은 현재 실행 중인 쓰레드에 작동하기에, Thread.sleep()으로 호출하자.(static 인 이유다.)
 *
 *  useVar() -> main 쓰레드에서 sleep이 작동하여 main쓰레드가 가장 늦게 끝남.
 *  useStatic() -> Thread1 에서 sleep이 작동하여 Thread1이 가장 마지막에 끝나고, main쓰레드는 가장 먼저 끝남.
 *
 */
public class B2SleepMethod {
    public static void main(String[] args) {
        //useVar();
        useStatic();
    }

    public static void useStatic(){
        MyThread thread1 = new MyThread("one");
        MyThread thread2 = new MyThread("two");

        thread1.start();
        thread2.start();

        thread1.sleep2000();

        System.out.println("main close");
    }

    public static void useVar(){
        MyThread thread1 = new MyThread("one");
        MyThread thread2 = new MyThread("two");

        thread1.start();
        thread2.start();

        try {
            thread1.sleep(2000);
        }catch (InterruptedException e){};

        System.out.println("main close");
    }

    static class MyThread extends Thread{
        private final String name;
        private boolean sleepNow = false;
        public MyThread(String name) {
            this.name = name;
        }

        public void run(){
            for(int i = 0; i < 1000; i++){
                System.out.print("=");
            }
            if(sleepNow){
                try {
                    Thread.sleep(2000);
                }catch (InterruptedException e){};
            }
            System.out.println("");
            System.out.println(name + " is close");
        }

        public void sleep2000(){
            sleepNow = true;
        }
    }
}
