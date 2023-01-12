package Collection;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * stack : FILO 구조
 * Queue : FIFO 구조, 데이터를 꺼낼 때마다 맨 앞의 수를 삭제해야 하므로 ArrayList로 구현할 경우 비효율적이다.
 */
public class StackAndQueue {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack();
        Queue<Integer> queue = new LinkedList<>();

        for(int i = 1; i <= 10; i++){
            stack.push(i);
            queue.offer(i);
        }

        System.out.println("---- stack -----");
        for(int i = 1; i <= 10; i++){
            System.out.print(" " + stack.pop());
        }
        System.out.println();
        System.out.println("-----queue------");
        for(int i = 1; i <= 10; i++){
            System.out.print(" " + queue.poll());
        }
    }


}
