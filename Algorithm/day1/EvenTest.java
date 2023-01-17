package Algorithm.day1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class EvenTest {
    public static void main(String[] args) {
        int num = 10;
        List<String> list = new ArrayList<>();
        list.add("aaaaa");

        if(num % 2 == 0) System.out.println(num + "는 짝수입니다.");
        else System.out.println(num + "는 홀수입니다.");
    }
}
