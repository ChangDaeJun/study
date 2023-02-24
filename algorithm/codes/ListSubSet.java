package algorithm.codes;

import java.util.*;

public class ListSubSet {
    public static void main(String[] args) {
        int[] numberList = {1, 3, 5, 6, 2, 10, 24, 3, 3, 23, 35, 3, 100, 45, 9, 59, 45};
        int size = 3;

        printLogic1(numberList, size);
        printLogic2(numberList, size);
    }

    private static void printLogic1(int[] list, int size){
        List<int[]> subIndexList = new LinkedList<>();

        for(int i = 0; i < list.length; i++){
            for(int j = i + 1; j < list.length; j++){
                for(int k = j + 1; k < list.length; k++){
                    System.out.println(list[i]+ ", " + list[j] + ", " + list[k]);
                }
            }
        }
    }

    private static void printLogic2(int[] list, int size){
        Queue<int[]> queue = new LinkedList<>();
        List<int[]> subIndexList = new ArrayList<>();
        queue.add(new int[size]);

        for(int i = 1; i <= list.length; i++){
            int queueSize = queue.size();
            System.out.println(i +"번 째는 : " + queueSize);
            for(int j = 0; j < queueSize; j++){
                int[] arr = queue.poll();

                if(checkFull(arr)){
                    subIndexList.add(arr);
                    continue;
                }

                int[] nextArr = inputNumber(arr, i);
                queue.add(nextArr);
                queue.add(arr);
            }
        }

        while (!queue.isEmpty()){
            int[] arr = queue.poll();
            if(checkFull(arr)){
                subIndexList.add(arr);
            }
        }

        System.out.println(subIndexList.size() + "개의 부분집합이 존재합니다.");
        for(int[] arr : subIndexList){
            System.out.println(changeIndexToDigits1(arr, list));
        }
    }

    private static String changeIndexToDigits1(int[] arr, int[] list){
        int[] result = new int[arr.length];
        for(int i = 0; i < result.length; i++){
            result[i] = list[arr[i] - 1];
        }
        return Arrays.toString(result);
    }

    private static int[] inputNumber(int[] arr, int nextIndex){
        int[] result = Arrays.copyOf(arr, arr.length);

        for(int i = 0; i < result.length; i++){
            if(result[i] == 0){
                result[i] = nextIndex;
                break;
            }
        }

        return result;
    }

    private static boolean checkFull(int[] arr){
        if(arr[arr.length - 1] == 0) return false;
        return true;
    }

    private static void printLogic3(int[] list, int size){
        List<int[]> indexList = new ArrayList<>();
        indexList.add(new int[size]);
        getIndexList(indexList,list.length, size, 1);
    }

    private static void getIndexList(List<int[]> indexList ,int scope, int size, int cnt){
        if(size == cnt) return;
        for(int[] arr : indexList){
            
        }
    }
}
