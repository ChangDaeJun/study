package Algorithm.day2.matrix;

public class ArrayTest {

    public static void main(String[] args) {
        Array array1 = new Array("첫 번째 Array", 3, 4);
        Array array2 = new Array("두 번째 Array", 3, 4);
        array1.makeArrayData();
        array2.makeArrayData();

        System.out.println("## 첫번째 Array 출력");
        array1.printArray();

        System.out.println("## 두번째 Array 출력");
        array2.printArray();

        Array.findMatchNumber(array1,array2);
    }
}
