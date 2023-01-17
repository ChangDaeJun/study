package algorithm.day2;

public class OverloadEx {
    public static int add(int a, int b){
        return a + b;
    }

    public static double add(double a, double b){
        return a + b;
    }
    public static String add(String a, String b){
        return a + b;
    }
    public static int add(int a, int b, int ... c){
        int sum = a + b;
        for(int i = 0; i < c.length; i++){
            sum += c[i];
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(add(1, 2,3, 4, 5, 6, 7, 8, 9, 10));
    }
}
