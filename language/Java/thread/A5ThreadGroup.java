package language.Java.thread;

/**
 * [쓰레드 그룹 클래스 : https://docs.oracle.com/en/java/javase/18/docs/api/java.base/java/lang/ThreadGroup.html]
 * 1. 쓰레드를 그룹으로 묶어 관리할 수 있고, 쓰레드 그룹을 다른 쓰레드 그룹에 포함시키는 것도 가능.
 * 2. 쓰레드 그룹은 보안을 위해 고안. 쓰레드는 자신이 속한 쓰레드 그룹이나 하위 쓰레드 그룹만을 변경할 수 있다.
 * 3. 모든 쓰레드는 만드시 쓰레드 그룹에 포함되어야 한다. 생성 시 생성한 쓰레드와 같은 그룹에 속해진다.
 * 4. JVM은 main과 system 쓰레드 그룹을 만들고, 필요한 쓰레드를 이 두 그룹에 포함시킨다.
 * 5. 예를 들어 main에는 main()을 실행시키는 main쓰레드, 가비지컬렉션을 수행하는 Finalizer 쓰레드는 system에 속한다.
 */
public class A5ThreadGroup {
    public static void main(String[] args) {
        ThreadGroup main = Thread.currentThread().getThreadGroup();
        ThreadGroup group1 = new ThreadGroup("Group1");
        ThreadGroup group2 = new ThreadGroup("Group2");

        ThreadGroup subGroupOfGroup1 = new ThreadGroup(group1, "subGroup1");

        group1.setMaxPriority(3);

        Runnable r = getRunnable();
        new Thread(group1, r, "th1").start();
        new Thread(subGroupOfGroup1, r, "th2").start();
        new Thread(group2, r, "th3").start();

        System.out.println(">> List of ThreadGroup: " + main.getName() +
                            ", Active ThreadGroup: " + main.activeGroupCount() +
                            ", Active Thread: " + main.activeCount());

        // 해당 쓰레드 그룹에 속한 모든 쓰레드 그룹과 쓰레드 출력, Thread[이름, 우선순위, 그룹명]
        main.list();
    }

    private static Runnable getRunnable(){
        return new Runnable() {
            @Override
            public void run() {
                try {
                    Thread.sleep(1000);
                }catch (InterruptedException e){}
            }
        };
    }
}
