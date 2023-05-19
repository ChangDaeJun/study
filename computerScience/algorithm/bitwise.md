### 문제
* long 배열에서 중복을 허용하지 않고, 임의의 두 수 쌍을 뽑은 뒤, 각 수의 비트에서 1의 개수의 합이 M이 되는 경우의 수를 구하시오.

### Map을 사용하는 방법
* 전체 경우의 수를 구할 경우 시간 복잡도는 n^2가 된다. (정확히는 n(n - 1)/2)
* 이를 n 수준으로 내리기 위해 Map을 활용한다.
* 먼저 배열을 돌며, 모든 수의 비트 1 개수를 구하여, map에 넣는다. 넣을 때에는 1의 개수를 키 값으로 넣고, 밸류 값으로는 키 값이 같은 수의 개수를 넣는다.
* 그 다음, map의 키 값을 돌며, M - 키 값 과 일치하는 키 값이 있는지 map에서 탐색한다.
* 없으면, 넘어가고 있으면 두 키값의 value를 곱한다.

```java
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
```