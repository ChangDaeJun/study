package algorithm.day2.lotto;

import java.util.*;

public class Lotto {
    public static int LOTTO_NUM_CNT = 6;

    private Lotto() {
    }

    public static int[] generateLottoNumbers(){
        Set<Integer> numbers = new HashSet<>();

        while(numbers.size() < LOTTO_NUM_CNT){
            int number = getRandomNumber();
            numbers.add(number);
        }

        Iterator<Integer> iterator = numbers.iterator();
        int[] lottoNumbers = new int[LOTTO_NUM_CNT];
        for(int i = 0; i < lottoNumbers.length; i++){
            lottoNumbers[i] = iterator.next();
        }

        return lottoNumbers;
    }

    public static void displayLottoNumbers(int[] lottoNumbers){
        System.out.println("<< Lotto >>");
        for(int num : lottoNumbers){
            System.out.print(num + " ");
        }
    }

    public static void sortLottoNumbers(int[] lottoNumbers){
        Arrays.sort(lottoNumbers);
    }

    private static int getRandomNumber(){
        Random random = new Random();
        return random.nextInt(45) + 1;
    }
}
