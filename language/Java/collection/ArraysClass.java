package language.Java.collection;

import java.util.Arrays;

/**
 * [배열 복사]
 * 1. for을 통한 복사와 Arrays.copyOf는 큰 차이를 보이지 않는다.
 * 2. Arrays.copyOf는 내부적으로 System.arraycopy를 사용하므로, 이를 가져다 사용해도 될 것 같다.
 *
 * [배열 채우기]
 * 1. fill(arr, num), setAll(arr, function : int index -> return int) 함수를 사용할 수 있다.
 * 2. 두 함수 모두 내부적으로 for 문을 사용한다. 코드 중복성을 생각한다면 가져다 사용하는 것이 좋아보인다.
 *
 *[배열 정렬 및 검색]
 * 1. 정렬 : sort(). 내부적으로 여러 정렬 알고리즘을 사용한다.
 * 2. 검색 : binarySearch 정렬된 배열에서 주어진 값을 이진 검색한다.
 *
 * [배열 -> list 변환]
 * ArrayList<>()를 바로 반환한다. 따라서 ArrayList의 매개변수로 들어갈 수 있는 Collection 타입만 들어갈 수 있다.
 */
public class ArraysClass {
    public static void main(String[] args) {
        arrayCopy(100_000_000);
    }

    private static void arrayCopy(int length){
        int[] arr = getRandomArray(length);

        long before = System.currentTimeMillis();
        int[] copy1 = copyArrayByFor(arr);
        System.out.println("for 문 복사: " + (System.currentTimeMillis() - before));

        before = System.currentTimeMillis();
        int[] copy2 = copyArrayByArraysMethod(arr);
        System.out.println("Arrays copyOf() 복사: " + (System.currentTimeMillis() - before));

    }

    private static int[] copyArrayByFor(int[] arr){
        int[] copy = new int[arr.length];
        for(int i = 0; i < copy.length; i++){
            copy[i] = arr[i];
        }
        return copy;
    }

    private static int[] copyArrayByArraysMethod(int[] arr){
        int[] copy = Arrays.copyOf(arr, arr.length);
        return copy;
    }

    private static int[] getRandomArray(int length){
        int[] arr = new int[length];
        Arrays.setAll(arr, (x) -> (int)(Math.random() * 15 + 1)); // x : 배열의 인덱스
        return arr;
    }
}
