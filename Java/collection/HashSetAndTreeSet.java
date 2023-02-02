package Java.collection;

import java.util.Arrays;
import java.util.HashSet;

/**
 * HashSet은 이미 저장된 요소나 중복된 요소를 저장할 시 false 반환, 순서를 유지하지 않기에 필요하다면 LinkedHashSet 사용.
 * 또한 HashSet은 저장공간의 75%가 넘어가면 용량이 2배 증가한다. 이 비중을 조절하는 값이 loadFactor.
 * 두 객체가 동일한지 판단하기 위해서는 Object에 존재하는 equals와 hashcode 함수를 오버라이딩하여 단서를 제공해주어야 한다.
 *
 * Hash Map의 구현은 HashMap을 통해 구현되어 있다.
 * map의 put은 키, 값으로 데이터를 넣는데, 만약 같은 키로 기존에 데이터가 있었다면 데이터를 리턴해주고, 없으면 null을 리턴해준다.
 * hashMap은 입력 받은 객체를 키로 두고 빈 Object를 value로 두어 map.put을 한다.
 * 이때 null이 발생하면 true를, null이 아니면 false를 반환한다.
 *
 * HashMap은 각 객체에 있는 hashcode() 함수를 해쉬 함수로 사용한다. Object의 경우 객체의 주소를 이용한다.
 * 예
 * Long - (int)(value ^ (value >>> 32))
 * Integer - value
 * Double - Long.hashcode(double to Long bit value); 등
 * 그렇다면, 반환값이 int임은 해쉬맵이 최대 44억 이상을 가질 수 없음을 의미하는 것일까?
 * long으로 구현하면 안되는 것일까?
 *
 * 가장 큰 이유로는 자바에서 배열의 최대 길이가 int의 최대값과 동일하기 때문으로 보인다.
 * hashMap의 내부 구조도 배열로 구현되어 있는 만큼, 아무리 hashCode가 long 값을 가져도 이를 활용할 수 없을 것이다.
 *
 * 혹여나 추후 배열의 최대값이 늘어날 지도 모르겟다. 그때면 hashCode도 long 값이 반환 될 것으로 보인다.
 */
public class HashSetAndTreeSet {

    public static void main(String[] args) {
        lotto();
    }

    private static void lotto(){
        HashSet<Integer> hashSet = new HashSet<>(7, 1f); // 초기 용량 6, 사용 용량의 95%가 될 때 용량을 2배 늘린다.

        //HashSet은 중복을 허용하지 않기에 다음과 같이 곂치지 않는 숫자를 얻을 수 있다.
        while (hashSet.size() < 6){
            hashSet.add((int)(Math.random() * 45 + 1));
        }
        Arrays.sort(hashSet.toArray());
        System.out.println(hashSet.toString());
    }
}
