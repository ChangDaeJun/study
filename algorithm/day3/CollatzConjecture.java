package algorithm.day3;

public class CollatzConjecture {
    public static void main(String[] args) {
        System.out.println("Number  |  Length of chain");
        System.out.println("---------------------------");

        int over100Cnt = 0;
        for(int i = 1; i < 100; i++){
            int chainCnt = getChainCnt(i);
            if(chainCnt > 100){
                System.out.printf("  %d    |       %d \n", i, chainCnt);
                over100Cnt++;
            }
        }

        System.out.println("---------------------------");
        System.out.println("Total number: " + over100Cnt);

    }

    public static int getChainCnt(int number){
        int chainCnt = 0;

        while(number != 4){
            if(number % 2 == 0) number /= 2;
            else number = 3 * number + 1;

            chainCnt++;
        }

        return chainCnt;
    }
}
