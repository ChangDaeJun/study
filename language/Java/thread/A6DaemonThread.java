package language.Java.thread;

/**
 * [데몬쓰레드]
 * 1. 데몬쓰레드는 일반 쓰레드의 작업을 돕는 보조적인 역할을 수행하는 쓰레드. 일반 쓰레드가 종료되면 강제로 종료된다.
 * 2. 가비지 컬렉터, 워드 프로세서의 자동저장과 화면 자동갱신 등이 있다.
 * 3. 데몬 쓰레드는 무한루프와 조건문을 통해 실행 후 대기하도록 작성됨. 쓰레드를 .setDaemon(true)로 설정.
 * 4. 데몬 쓰레드가 생성한 쓰레드는 데몬쓰레드가 된다.
 */
public class A6DaemonThread {
    static boolean autoSave = false;
    public static void main(String[] args) {
        Thread thread = new DaeMonThread();
        thread.setDaemon(true);
        thread.start();

        for(int i = 0; i < 50 ; i ++){
            try {
                Thread.sleep(400);
            } catch (InterruptedException e){}

            System.out.println(i);
            if(i > 10) autoSave = true;
        }
    }

    static class DaeMonThread extends Thread{
        public void run(){
            while (true){
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e){}
                if(autoSave){
                    System.out.println("자동저장되었습니다.");
                }
            }
        }
    }
}
