package computerScience.algorithm.codes;

import java.util.*;

public class ListSubSet {
    public static void main(String[] args) {
        int[] numberList = {1, 3, 5, 6, 2, 10, 24, 3, 3, 23, 35, 3, 100, 45, 9, 59, 45};
        int size = 3;

        printLogic1(numberList, size);
        printLogic2(numberList, size);
        printLogic3(numberList, size);
        int[] arr = new int[size];
        printLogic4(numberList, size, 1, arr);
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

    public static void printLogic3(int[] list, int size){
        System.out.println("출력 시작");

        int[] index = new int[size];
        for(int i = 0; i < index.length; i++) index[i] = i + 1;
        print(list, index);

        System.out.println("출력 끝");
    }

    private static void print(int[] list, int... index){
        System.out.println(changeIndexToDigits1(index, list));//해당 인덱스 출력
        int[] next = getNextIndex(index, list.length);
        if(next[0] == 0) return;
        print(list, next);
    }

    private static int[] getNextIndex(int[] before, int size){
        //마지막 자리가 size를 넘기지 않으면 1 추가해서 리턴
        if(before[before.length - 1] < size) before[before.length - 1]++;
        else{
            //마지막 자리가 size와 같으면, 마지막 자리 앞 자리를 탐색한다. 자신과 2이상 초과하는 경우를 찾는다.
            int moveIndex = before.length - 1;
            boolean change = false;
            for(int i = before.length - 1; i >= 0; i--){
                if(before[i] + 1 < before[moveIndex]){
                    moveIndex = i;
                    change = true;
                    break;
                }else{
                    moveIndex = i;
                }
            }
            // 을 1늘리고, 마지막 자리는 앞자리 +1을 한 뒤 리턴
            if(change){
                int a = before[moveIndex] + 1;
                for(int i = moveIndex; i < before.length; i++){
                    before[i] = a;
                    a++;
                }
            }
            else{
                before[0] = 0;
            }
        }

        return before;
    }

    public static void printLogic4(int[] list, int size, int cur, int... index){
        int start = 1;
        if(cur > 1) start = index[cur - 2] + 1;

        for(int i = start; i <= list.length; i++){
            index[cur - 1] = i;
            if(cur < size) printLogic4(list, size,cur + 1, index);
            else {
                System.out.println(changeIndexToDigits1(index, list));
            }
        }
    }
}

