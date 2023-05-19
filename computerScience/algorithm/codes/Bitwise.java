package computerScience.algorithm.codes;

import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Bitwise {

    public static void main(String[] args) {
        int size = 1000000;
        long[] arr = getRandomArr(size);
        int sumTarget = 100;

        //각 숫자의 비트 개수를 센 뒤, 비트 개수를 key로 저장한다. value을 통해 비트 개수가 동일한 수의 개수를 센다.
        Map<Integer, Integer> map = new HashMap<>();
        for(long num : arr){
            int n = Long.bitCount(num);
            if(map.containsKey(n)){
                map.put(n, map.get(n) + 1);
            }
            else{
                map.put(n, 1);
            }
        }

        //타겟 값에서 맵에서 꺼낸 키값을 뺀 값이 맵에 존재해야 한다.(a + b = target -> target - a = b)
        //존재하지 않으면, 넘어가고 존재한다면 각 키값을 만족하는 수의 개수를 곱하여, 전체 경우의 수를 구한다.
        //만약 a, b가 동일하다면, 동일한 값을 꺼내오기 때문에 if 문으로 중복을 제거하였다. 이 경우는 target이 짝수인 경우 단 한번 발생한다.
        int cnt = 0;
        for(Integer num : map.keySet()){
            if(!map.containsKey(sumTarget - num)) continue;

            int a = map.get(num);
            int b = map.get(sumTarget - num);

            if(num == sumTarget - num){
                cnt += (a * (b - 1)) / 2;
            }else {
                cnt += a * b;
            }
        }

        System.out.println(cnt);
    }

    private static long[] getRandomArr(int size){
        long[] arr = new long[size];
        Random random = new Random();

        for(int i = 0; i < arr.length; i++){
            arr[i] = random.nextLong();
        }

        return arr;
    }
}
