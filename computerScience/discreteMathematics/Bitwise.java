package computerScience.discreteMathematics;

import java.util.*;

public class Bitwise {
    public static void main(String[] args) {
        //전체 집합을 생성.
        UniversalSet<String> universalSet = getUniversalSet();

        //부분집합 생성
        Set<String> subSet1 = new HashSet<>();
        Set<String> subSet2 = new HashSet<>();
        subSet1.add("111");
        subSet1.add("333");
        subSet2.add("222");
        subSet2.add("333");

        //부분집합을 bit으로 반환받음. 만약 전체 집합의 부분집합이 아니라면, bit = 0이 리턴된다.
        long bit1 = universalSet.getBit(subSet1);
        long bit2 = universalSet.getBit(subSet2);

        //비트 논리 연산.
        long bit1AndBit2 = bit1 & bit2;
        long bit1OrBit2 = bit1 | bit2;

        System.out.println("교집합" + universalSet.getSet(bit1AndBit2).toString());
        System.out.println("합집합" + universalSet.getSet(bit1OrBit2).toString());
    }

    private static UniversalSet<String> getUniversalSet(){
        Set<String> set = new HashSet<>();
        set.add("111");
        set.add("222");
        set.add("333");
        set.add("444");
        UniversalSet<String> universalSet = null;
        try {
            universalSet = new UniversalSet<>(set);
        }catch (Exception e){
        }
        return universalSet;
    }
}
class UniversalSet<T>{
    Map<T, Integer> integerMap;
    Map<Integer, T> objectMap;

    public UniversalSet(Set<T> set) throws Exception{
        if(set.size() > 64) throw new Exception();
        integerMap = new HashMap<>();
        objectMap = new HashMap<>();
        int i = 0;
        for(T object : set){
            integerMap.put(object, i);
            objectMap.put(i, object);
            i++;
        }
    }

    public long getBit(Set<T> set){
        if(set.size() > 64) return 0;
        long bit = 0;
        for(T object : set){
            if(!integerMap.containsKey(object)) return 0;
            int index = integerMap.get(object);
            bit += getBit(index);
        }
        return bit;
    }

    private long getBit(int index){
        long bit = 1;
        bit = bit << index;
        return bit;
    }

    public Set<T> getSet(long bit){
        Set<T> set = new HashSet<>();
        for(int i = 0; i < 64; i++){
            if((bit & 1) == 1){
                set.add(this.objectMap.get(i));
            }
            bit = bit >> 1;
        }
        return set;
    }
}
