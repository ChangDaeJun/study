package algorithm.day1;

public class GooGooDanPrint {
    public static void main(String[] args) {
        for(int back = 1; back <= 9; back++){
            for(int front = 2; front <= 9; front++){
                //System.out.print(front + " X " + back + " = " + (front * back) + "\t");
                System.out.printf("%d X %d = %2d\t", front, back, (front * back));
            }
            System.out.println("");
        }
    }
}
