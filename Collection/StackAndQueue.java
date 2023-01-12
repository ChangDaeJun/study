package Collection;

import java.util.*;

/**
 * stack : FILO 구조
 * Queue : FIFO 구조, 데이터를 꺼낼 때마다 맨 앞의 수를 삭제해야 하므로 ArrayList로 구현할 경우 비효율적이다.
 * PriorityQueue : 사전에 정한 우선순위에 따라 출력됨
 * Deque : 양쪽 끝에서 추가 삭제가 가능
 */
public class StackAndQueue {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack();
        Queue<Integer> queue = new LinkedList<>();
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        Deque<Integer> deque = new LinkedList<>();

        System.out.println("다음 숫자가 랜덤으로 입력됩니다. Deque는 입력되는 수가 짝수면 앞에, 홀수면 뒤에 넣습니다.");
        for(int i = 1; i <= 10; i++){
            int random = (int)(Math.random() * 10);
            System.out.print(random + " ");
            stack.push(random);
            queue.offer(random);
            priorityQueue.offer(random);
            if(random % 2 == 0){
                deque.offerFirst(random);
            }
            else{
                deque.offerLast(random);
            }
        }
        System.out.println();
        System.out.println("---- stack -----");
        for(int i = 1; i <= 10; i++){
            System.out.print(" " + stack.pop());
        }

        System.out.println();
        System.out.println("-----queue------");
        for(int i = 1; i <= 10; i++){
            System.out.print(" " + queue.poll());
        }

        System.out.println();
        System.out.println("-----priorityQueue------");
        for(int i = 1; i <= 10; i++){
            System.out.print(" " + priorityQueue.poll());
        }

        System.out.println();
        System.out.println("-----deque------");
        for(int i = 1; i <= 10; i++){
            System.out.print(" " + deque.poll());
        }
    }


}
