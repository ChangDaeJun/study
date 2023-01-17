package algorithm.day2;

import java.util.Scanner;

public class Involution {
    public static void main(String[] args) {
        int num;
        Scanner scanner = new Scanner(System.in);
        while (true){
            System.out.print("입력: ");
            num = scanner.nextInt();

            if(num == 0) break;
            if(isTwoInvolution(num)){
                System.out.println("출력 : OK");
            }
            else{
                System.out.println("출력 : NO");
            }
        }//while end

        scanner.close();
    }

    private static boolean isTwoInvolution(int num){
        while (num > 1){
            if(num % 2 != 0) return false;
            num /= 2;
        }

        return true;
    }
}
