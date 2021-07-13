# 객체 지향 기초 

## 객체 지향 프로그래밍

- 객체(Object) : 구체적, 추상적 데이터의 단위 (고객, 주문, 물품 등) 

- 각 객체를 정의 -> 각 객체가 제공하는 기능들을 구현 -> 각 객체간의 협력을 구현 


## 클래스

- 클래스(Class) : 객체를 추상화하여 코드로 나타낸 것 

- 멤버 변수(Member variable) : 객체의 속성을 나타냄 

- 메서드 (Method) : 객체의 기능(역할)을 구현, 멤버 함수(Member function) 라고도 함 

```java
public class Student {
    int studentNumber;
    String studentName;
    String major;
}
```
- public : 외부에서 접근 가능함을 나타냄. 하나의 java 파일 안에 public 클래스는 단 하나여야 하고 파일명과 클래스명은 동일해야 한다. 


## 인스턴스

- 클래스를 기반으로 실제 메모리 공간을 차지하도록 생성된 객체를 인스턴스라고 함 

- new 키워드를 사용하여 인스턴스 생성 

- 동적 메모리영역(heap 영역) 에 할당됨 

```java
Student studentLee = new Student()
```

## 생성자(Constructor) 

- new 키워드와 함께 객체를 생성하기 위해 사용됨 

- 객체가 생성될 때 변수나 상수를 초기화 하거나 다른 초기화 기능을 수행하는 메서드 호출

- 반환값이 없고, 클래스의 이름과 동일하게 정의 

- 모든 클래스에는 반드시 하나 이상의 생성자가 존재해야 함 -> 따로 정의해주지 않으면 컴파일러가 기본 생성자 코드를 생성한다.(매개변수, 구현부 없음) 

- 생성자 오버로딩을 통해 여러 생성자를 정의할 수 있음 
-- 오버로딩(Overloading) : 이름은 같고 매개변수만 다른 메서드를 작성하여 각각 사용할 수 있는 기술 

```java
public class Student {
    public int studentNumber;
    
    public Student (int studentNumber) {
        this.studentNumber = studentNumber;
    }
}
```

- this : 지역변수가 아닌 멤버변수를 나타냄
