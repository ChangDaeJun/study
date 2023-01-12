package Collection;

import java.util.ArrayList;
import java.util.LinkedList;

/**
 * ArrayList는 크기 10 배열을 기본값으로 갖으며, 입력받은 수가 배열의 크기를 넘을 때 기존 배열의 1.5배 크기의 새 배열을 만들어 복사한다. * Vector는 2배
 * LinkedLust는 node를 통해 비순차적인 데이터를 연결하는 자료구조이다.
 *
 * [add]
 * ArrayList는 초기 capacity 값을 정해 줄 경우, 그렇지 않은 경우 보다 2 ~ 3배 정도 더 빠른 것을 확인할 수 있다.
 * LinkedList는 node 생성 시간으로 인해 가장 느린 add 시간을 보였다.
 *
 * [get]
 * ArrayList는 내부적으로 배열을 사용하기에 데이터 접근에 O(1)만큼 소요 된다.
 * LinkedList는 n번째 데이터 접근에 n번 node를 돌아야 하기에 O(n)만큼 소요된다.
 *
 * [delete]
 * ArrayList는 list의 맨 앞을 삭제하는 경우 전체 배열을 다시 앞으로 땡겨야 하기에 O(n)만큼의 시간이 걸린다.
 * 반면, 맨 뒤에서 부터 삭제하는 경우 배열을 옮기지 않기 때문에 O(1)만큼의 시간이 걸린다.
 * LinkedList는 노드 간의 연결을 끊기만 하면 되기에 삭제에 O(1)만큼의 시간이 걸린다.
 *
 * [비교]
 * ArrayList는 미리 배열을 생성하기에 비효율적인 메모리 사용이 일어난다. 반면 읽기 속도가 빠르다는 장점이 있다.
 * LinkedList는 노드를 이용하여 빠른 추가(배열 중간)와 삭제가 가능하지만, 읽기 속도가 느리다는 단점이 있다.
 *
 */
public class ArrayListAndLinkedList {
    public static void main(String[] args) {
        checkAddTime(20_000_000);
        checkGetTime(20_000_000);
        checkDeleteTime(20_000_000);
    }
    private static void checkDeleteTime(int capacity){
        System.out.println("-------------- Delete -------------------------------------");
        ArrayList<Integer> list1_start = new ArrayList<>(capacity);
        ArrayList<Integer> list1_end = new ArrayList<>(capacity);
        LinkedList<Integer> list2_start = new LinkedList<>();
        LinkedList<Integer> list2_end = new LinkedList<>();

        for(int i = 0; i < capacity; i++){
            list1_start.add(i);
            list1_end.add(i);
            list2_start.add(i);
            list2_end.add(i);
        }

        long before = System.currentTimeMillis();
        for(int i = 0; i < 1000; i++){
            list1_start.remove(0);
        }
        System.out.println("ArrayList index 0 삭제 시간 : " + (System.currentTimeMillis() - before)+" (시간 관계 상 1000개 delete)");

        before = System.currentTimeMillis();
        for(int i = 0; i < capacity; i++){
            list1_end.remove(list1_end.size() -1 );
        }
        System.out.println("ArrayList index end 삭제 시간 : " + (System.currentTimeMillis() - before));

        before = System.currentTimeMillis();
        for(int i = 0; i < capacity; i++){
            list2_start.remove(0);
        }
        System.out.println("LinkedList index 0 시간 : " + (System.currentTimeMillis() - before));

        before = System.currentTimeMillis();
        for(int i = 0; i < capacity; i++){
            list2_end.remove(list2_end.size() - 1);
        }
        System.out.println("LinkedList index end 시간 : " + (System.currentTimeMillis() - before));

        System.out.println("----------------------------------------------------------");
    }

    private static void checkGetTime(int capacity){
        System.out.println("-------------- Get -------------------------------------");
        Integer[] list = new Integer[capacity];
        ArrayList<Integer> list1 = new ArrayList<>(capacity);
        LinkedList<Integer> list2 = new LinkedList<>();

        for(int i = 0; i < capacity; i++){
            list[i] = i;
            list1.add(i);
            list2.add(i);
        }

        long before = System.currentTimeMillis();
        for(int i = 0; i < capacity; i++){
            Integer x = list[i];
        }
        System.out.println("Integer 배열 시간 : " + (System.currentTimeMillis() - before));

        before = System.currentTimeMillis();
        for(int i = 0; i < capacity; i++){
            Integer x = list1.get(i);
        }
        System.out.println("ArrayList 시간 : " + (System.currentTimeMillis() - before));

        before = System.currentTimeMillis();
        //capacity까지 계산 시 시간 초과
        for(int i = 0; i < 100000; i++){
            Integer x = list2.get(i);
        }
        System.out.println("LinkedList 시간 : " + (System.currentTimeMillis() - before) + " (시간 관계상 10만개만 get)");

        System.out.println("----------------------------------------------------------");
    }

    private static void checkAddTime(int capacity){
        System.out.println("-------------- Add -------------------------------------");
        Integer[] list = new Integer[capacity];
        ArrayList<Integer> list1 = new ArrayList<>();
        ArrayList<Integer> list2 = new ArrayList<>(capacity);
        LinkedList<Integer> list3 = new LinkedList<>();

        long before = System.currentTimeMillis();
        for(int i = 0; i < capacity; i++){
            list[i] = i;
        }
        System.out.println("Integer 배열 시간 : " + (System.currentTimeMillis() - before));

        before = System.currentTimeMillis();
        for(int i = 0; i < capacity; i++){
            list1.add(i);
        }
        System.out.println("ArrayList Default(10) 시간 : " + (System.currentTimeMillis() - before));

        before = System.currentTimeMillis();
        for(int i = 0; i < capacity; i++){
            list2.add(i);
        }
        System.out.println("Arraylist capacity: " + capacity+ " 시간 : " + (System.currentTimeMillis() - before));

        before = System.currentTimeMillis();
        for(int i = 0; i < capacity; i++){
            list3.add(i);
        }
        System.out.println("LinkedList 시간 : " + (System.currentTimeMillis() - before));
        System.out.println("----------------------------------------------------------");
    }
}
