package thread.A8ThreadSynchronization;

/**
 * [wait()]
 * 1. 해당 객체의 대기실에서 콜을 기달림
 * 2. Object에 정의되어 있음
 *
 * [notify()]
 * 1. 해당 객체의 대기실에 있는 모든 쓰레드 중 일부 임의 통보, notifyAll()은 전체 통보
 * 2. Object에 정의되어 있음
 *
 */
public class B2WaitAndNotifyMethod {
    public static void main(String[] args) {
        Money money = new Money();
        Son son = new Son(money);
        Father father = new Father(money);

        son.start();
        father.start();

        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.exit(0);
    }

    static class Son extends Thread{
        private Money money;

        public Son(Money money) {
            this.money = money;
        }

        public void run(){
            while(true){
                try {
                    Thread.sleep(100);
                }catch (InterruptedException e){}
                money.getMoney(1000);
                System.out.println("get 1000 won");
            }
        }
    }

    static class Father extends Thread{
        private Money money;

        public Father(Money money) {
            this.money = money;
        }

        public void run(){
            while (true){
                try {
                    Thread.sleep(120);
                }catch (InterruptedException e){}
                money.plus(700);
                System.out.println("input 100 won");
            }
        }
    }

    static class Money{
        private int money;

        public Money() {
            this.money = 10000;
        }

        public synchronized boolean getMoney(int number){
            while (money < number){
                try {
                    wait();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
            money -= number;
            notify();
            return true;
        }

        public synchronized void plus(int number){
            money += number;
        }
    }
}
