package Algorithm;

import java.util.Scanner;

public class UpDownGame {

    public static void main(String[] args) {
        int computerAnswer = (int)(Math.random() * 100 + 1);
        int userAnswer = 0;
        int chance = 1;

        do {
            userAnswer = getUserAnswer();
            if(userAnswer == computerAnswer){
                System.out.println("정답입니다" + chance +"번 만에 맞췄습니다.");
                return;
            }else{
                hintUpOrDown(userAnswer, computerAnswer);
            }
            chance++;
        }while (chance <= 5);

        System.out.println("맞추지 못했습니다. 정답은 " + computerAnswer +"입니다.");
    }

    private static void hintUpOrDown(int userAnswer, int computerAnswer) {
        if(userAnswer > computerAnswer){
            System.out.println("Down !");
        }
        else if(userAnswer < computerAnswer){
            System.out.println("Up !");
        }
    }

    private static int getUserAnswer() {
        int userAnswer;
        Scanner scanner = new Scanner(System.in);
        System.out.print("수를 입력하세요 : ");
        userAnswer = scanner.nextInt();
        return userAnswer;
    }
}
