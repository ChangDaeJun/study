package algorithm.day3;

class Parent4{
    public Parent4(String name) {
    }
}

//부모의 생성자가 기본 생성자가 아닐 경우 그 자식은 부모의 생성자를 적절히 처리해 주어야 한다.
//JDK의 자동생성자는 기본생성자를 생성하면서 동시에 부모 클래스의 super()를 호출하게 되는데, 부모 생성자에 기본생성자가 없기에 오류가 발생한다.
//이를 처리하기 위해서 부모 클래스가 기본 생성자를 정의하거나, 자식클래스가 부모클래스 생정자를 명시적으로 호출.
class Child4 extends Parent4{
    public Child4(String name) {
        super(name);
    }
}

public class ExtendsEx {
}
