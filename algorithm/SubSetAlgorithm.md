## 문제
* n개의 리스트에서 k개의 부분집합을 모두 출력하기
* 실행 코드 : algorithm/codes/ListSubSet.java

### 방법 1. 부분 집합의 크기에 맞춰 중첩 for문을 사용
* 가장 단순한 방법으로 K번 중첩 for문을 사용한 뒤, 아래와 같이 각 for문의 인덱스가 이전 for문보다 1큰 수를 가지면 된다.
```java
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
```
* 시간 복잡도는 n개의 리스트에서 k개의 부분집합의 개수인 $\begin{pmatrix}n\\k\\ \end{pmatrix}$ 이다.
* 단점으로는 k의 크기에 맞춰 매번 함수를 작성해야 한다.

### 방법 2. Queue을 사용하여 index 리스트를 구하기
```java
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
```
* 이 방법은 queue을 사용하여, 중복되지 않는 인덱스 배열을 구하는 방법이다.
* for문의 i가 index 번호를 의미하며, queue에서 만들고 있는 인덱스 배열을 꺼내 배열의 크기가 사이즈를 넘기면, subLindexList로 넘기지 않는다면, i를 넣는 경우와 안넣는 경우 두가지를 큐에 넣는다.
* 시간 복잡도는 방법 1과 동일할 것으로 보이지만, checkFull 이나 새로운 배열을 생성하는 비용 등을 생각하면 동일 조건에서는 방법 1이 더 높은 속도를 보여 줄 것으로 보인다.
* 이 방법은 부분집합의 크기 K에 따라 동적으로 작동한다.

### 방법 3. 재귀함수 활용 (1)
```java
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
```
* 재귀함수와 가변인자를 통해 인덱스 부분집합을 넘겨주는 방식으로 구현했다.
* 다만 인덱스 배열에 적절한 값을 넣는 알고리즘이 과도하게 복잡한 단점이 생겼다.
* 시간복잡도 역시 방법1, 방법2와 동일 할 것으로 보이며, 재귀함수를 통한 방식의 특성 상 속도 저하나 스택오버플로우의 문제를 발생할 수 있다.

### 방법 4. 재귀함수 활용(2)
```java
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
```
* 중첩 for문을 재귀함수로 구현했다.
* start 변수는 각 for문의 index의 시작 번호를 알려주기 위한 변수로, 이전 값이 없으면 1을, 있으면 이전 값 + 1을 사용하도록 했다.
* 방법 1에서 j = i+ 1과 같은 부분이다.
* 시간 복잡도 역시 방법1, 2, 3과 동일하며, 동일한 상황에서는 재귀 호출로 인해 방법 1보다는 느리지만, 동적으로 사용할 수 있는 장점이 있다.
