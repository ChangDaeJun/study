package Algorithm;

public class GooGooDanPrint {
    public static void main(String[] args) {
        for(int back = 1; back <= 9; back++){
            for(int front = 2; front <= 9; front++){
                System.out.print(front + " X " + back + " = " + (front * back) + "\t");
            }
            System.out.println("");
        }
    }
}
