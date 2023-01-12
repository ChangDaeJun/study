package Collection;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * Comparable 기본 정렬 기준을 구현하기 위해 사용, 즉 객체의 default 정렬을 지정
 * Comparator 기본 정렬 기존 외 다른 기준으로 정렬하기 위해 사용, 그때 그때 필요한 정렬을 사용.
 * 같으면 0, 비교하는 값보다 작으면 음수, 크면 양수 리턴
 */
public class ComparatorAndComparable {
    public static void main(String[] args) {
        List<Point> pointList = getRandomPointList();
        Point[] pointArr = getRandomPointArr();

        Arrays.sort(pointArr);
        print(pointArr);
        pointList.sort(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                int thisLength = o1.getX() * o1.getX() + o1.getY() * o1.getY();
                int otherLength = o2.getX() * o2.getX() + o2.getY() * o2.getY();
                return otherLength - thisLength;
            }
        });
        System.out.println("---------------------");
        print(pointList);
    }
    private static List<Point> getRandomPointList(){
        List<Point> list = new ArrayList<>();
        for(int i = 0; i < 20; i++){
            int x = (int)(Math.random() * 20);
            int y = (int)(Math.random() * 20);
            list.add(new Point(x, y));
        }
        return list;
    }

    private static Point[] getRandomPointArr(){
        Point[] arr = new Point[20];
        for(int i = 0; i < 20; i++){
            int x = (int)(Math.random() * 20);
            int y = (int)(Math.random() * 20);
            arr[i] = new Point(x, y);
        }
        return arr;
    }

    private static void print(Point[] points){
        for(Point point : points){
            System.out.println(point.toString());
        }
    }

    private static void print(List<Point> points){
        for(Point point : points){
            System.out.println(point.toString());
        }
    }

    static class Point implements Comparable<Point>{
        private int x;
        private int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        @Override
        public int compareTo(Point o) {
            int thisLength = this.getX() * this.getX() + this.getY() * this.getY();
            int otherLength = o.getX() * o.getX() + o.getY() * o.getY();
            return thisLength - otherLength; // 같으면 0, 비교하는 대상(other)이 더 크면 음수, 작으면 음수 = 오름차순
        }

        @Override
        public String toString(){
            return "[" + this.getX() +", " + this.getY()+"]";
        }
    }
}
