package algorithm.day1;

import java.util.Scanner;

public class ScoreProcess {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int score = -1;

        while(score < 0 || score > 100) {
            System.out.print("점수를 입력해주세요 : ");
            score = sc.nextInt();
            if(score < 0 || score > 100) System.out.println("범위를 벗어났습니다.");
        }

        int num = score / 10;
        switch(num){
            case 10 :
                System.out.println("A입니다.");
                break;
            case 9:
                System.out.println("A입니다.");
                break;
            case 8:
                System.out.println("B입니다.");
                break;
            case 7:
                System.out.println("C입니다.");
                break;
            case 6:
                System.out.println("D입니다.");
                break;
            default:
                System.out.println("F입니다.");
                break;
        }

    }
}
