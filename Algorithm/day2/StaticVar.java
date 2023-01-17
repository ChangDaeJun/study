package Algorithm.day2;

public class StaticVar {

    public static int num = 3;


    public static void main(String[] args) {
        System.out.println(num);
        StaticVar staticVar = new StaticVar();
        staticVar.num *= 3;
        System.out.println(num);
    }
}
