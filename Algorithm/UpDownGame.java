package Algorithm;

import java.util.Scanner;

public class UpDownGame {
    private static int userAnswer = 0;
    private static int usedChance = 1;
    private static int computerAnswer = (int)(Math.random() * 100 + 1);

    public static void main(String[] args) {
        if (playGame()) {
            System.out.println("정답입니다" + usedChance +"번 만에 맞췄습니다.");
        }
        else {
            System.out.println("맞추지 못했습니다. 정답은 " + computerAnswer +"입니다.");
        }
    }

    private static boolean playGame() {
        do {
            userAnswer = getUserAnswer();
            if(userAnswer == computerAnswer) return true;
            else{
                hintUpOrDown(userAnswer, computerAnswer);
                usedChance++;
            }
        }while (usedChance <= 5);

        return false;
    }

    private static void hintUpOrDown(int userAnswer, int computerAnswer) {
        if(userAnswer > computerAnswer)System.out.println("Down !");
        else System.out.println("Up !");
    }

    private static int getUserAnswer() {
        int userAnswer;
        Scanner scanner = new Scanner(System.in);
        System.out.print("수를 입력하세요 : ");
        userAnswer = scanner.nextInt();
        return userAnswer;
    }
}
