package Java.thread.A8ThreadSynchronization;

/**
 * [쓰레드 동기화]
 * 한 쓰레드가 진행 중인 작업을 다른 쓰레드가 간섭하지 못하도록 막는 것
 *
 * [synchronized]
 * 1. 메서드 선언 시 pubilc synchronized void 와 같은 방식으로 선언. 메서드가 포함된 객체에 lock을 얻어 수행
 * 2. synchronized(객체 참조변수) { }을 통해 선언. 객체 참조변수에 lock을 하고 싶은 객체를 참조
 * 3. 주의. 객체에 대한 lock을 얻는 것이기에, 객체 함수에 synchronized를 선언해야 한다.
 * 4. 예를 들어 지역변수를 변화시키는 함수를 서로 다른 객체를 통해 생성하여 각기 다른 쓰레드로 실행시키면 동기화가 되지 않는다.
 */
public class B1Synchronized {
    public static void main(String[] args) {
        Account1 account1 = new Account1();
        Account2 account2 = new Account2();

        notSync(account1);

        doSync(account2);
    }

    static void notSync(Account1 account1){
        MyThread1 thread1 = new MyThread1(account1);
        MyThread1 thread2 = new MyThread1(account1);

        thread1.start();
        thread2.start();

        while(thread1.isAlive() || thread2.isAlive()){

        }

        if(!thread1.isAlive() && !thread2.isAlive()) System.out.println(account1.getMoney());
    }

    static void doSync(Account2 account2){
        MyThread2 thread1 = new MyThread2(account2);
        MyThread2 thread2 = new MyThread2(account2);

        thread1.start();
        thread2.start();

        while(thread1.isAlive() || thread2.isAlive()){

        }
        if(!thread1.isAlive() && !thread2.isAlive())  System.out.println(account2.getMoney());
    }
    static class Account1{
        private int money = 0;

        public int getMoney() {
            return money;
        }

        public void plus(){
            for(int i = 0; i < 100000; i++){
                money++;
            }
        }
    }

    static class Account2{
        private int money = 0;

        public int getMoney() {
            return money;
        }

        public synchronized void plus(){
            for(int i = 0; i < 100000;i++){
                money++;
            }
        }
    }
    static class MyThread1 extends Thread{
        private Account1 account1;
        public MyThread1(Account1 account1) {
            this.account1 = account1;
        }

        public void run(){
            account1.plus();
        }
    }

    static class MyThread2 extends Thread{
        private Account2 account2;
        public MyThread2(Account2 account2) {
            this.account2 = account2;
        }

        public void run(){
            account2.plus();
        }
    }
}
