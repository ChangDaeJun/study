package Algorithm;

public class test1 {
    public static void main(String[] args) {
        int num = 0;

        try {
            num = Integer.parseInt(args[0]);
        }catch (NumberFormatException e){
            System.out.println("정해진 범위를 초과한 수입니다.");
            return;
        }
        if(num % 2 == 0) System.out.println(num + "는 짝수입니다.");
        else System.out.println(num + "는 홀수입니다.");
    }
}
