# 객체지향 핵심 

## 클래스 상속 (Class Inheritance)

- 새로운 클래스를 정의할 때 이미 구현된 클래스를 상속받아서 속성이나 기능을 확장하여 클래스를 구현
- 이미 구현된 클래스보다 더 구체적인 기능을 가진 클래스를 구현해야 할 때 기존 클래스를 상속
- 자바는 단일 상속만을 지원함 
- extends 키워드 사용 


![class Mammal{](https://user-images.githubusercontent.com/43959582/125709324-c70d350f-d147-46ae-b6a6-5395a462befb.png)

## 상속의 과정 

- 하위 클래스의 생성자 호출 시 상위 클래스의 생성자가 먼저 호출됨 (따로 명시해주지 않으면 컴파일러가 default 생성자(super() )를 넣어줌 
- super 는 생성된 상위 클래스 인스턴스의 참조 값을 가지므로 super 키워드를 이용하여 상위 클래스의 메서드나 멤버 변수에 접근할 수 있음 

```java
public class VIPCustomer extends Customer {
    public VIPCustomer (int customerId, String customerName){
        super (customerId, customerName);   // 없을 시 super() 를 호출
    }
}
```

## 오버라이딩 (Overriding) 

- 오버라이딩 : 상위 클래스에 정의된 메서드의 구현 내용이 하위 클래스에서 구현할 내용과 맞지 않는 경우 하위 클래스에서 재정의 하는 것 
- 메서드 이름, 매개변수는 동일하게 작성
- `Customer vc = new VIPCustomer ();` 에서 vc 의 변수타입은 Customer 이지만, 인스턴스 타입은 VIPCustomer 로 오버라이딩된 메서드 호출 시 VIPCustomer 의 메서드가 호출됨 

## 다형성 (Polymorphism) 

- 하나의 객체가 여러 타입을 가질 수 있음 
- 같은 코드에서 여러 다른 실행 결과가 나올 수 있음
- 상속과 메서드 재정의를 활용하여 확장성 있는 프로그램을 만들 수 있음
- 여러 클래스를 하나의 타입(상위 클래스)으로 핸들링 할 수 있음

```java
class Human extends Animal { ... }
class Tiger extends Animal { ... }
class Eagle extends Animal { ... }

public class AnimalTest {
    public static void main (String[] args){
        Animal hAnimal = new Human ();
        Animal tAnimal = new Tiger ();
        Animal eAnimal = new Eagle ();
        
        AnimalTest test = new AnimalTest ();
        test.moveAnimal (hAnimal);    // 각각 Human, Tiger, Eagle 클래스의 move() 메서드가 실행됨
        test.moveAnimal (tAnimal);
        test.moveAnimal (eAnimal);
    }
    
    public void moveAnimal (Animal animal){
        animal.move();
    }
}
```

## 추상 클래스 (Abstract Class) 

- 구현 코드 없이 메서드의 선언만 있는 추상 메서드(Abstract method) 를 포함한 클래스
- abstract 예약어 사용
- 추상 클래스는 인스턴스화(new) 할 수 없음 - 추상 메서드를 가지고 있지 않은 클래스라도 abstract 로 선언되면 추상 클래스로 인스턴스화 할 수 없음
- 추상 메서드는 하위 클래스가 상속하여 구현


### 템플릿 메서드 패턴 

- 틀을 가진 메서드로 추상 메서드나 구현 된 메서드를 활용하여 코드의 흐름(시나리오)를 정의하는 메서드
- final 로 선언하여 하위 클래스에서 재정의 할 수 없게 함 (class 에 final 키워드가 쓰이면 상속이 불가능하다. 변수에 쓰이면 변경 불가능한 상수가 된다.)
- 추상 클래스로 선언된 상위 클래스에서 템플릿 메서드를 활용하여 전체적인 흐름을 정의하고 하위 클래스에서 다르게 구현되어야 하는 부분을 구현함
- 프레임워크를 만들 떄 주로 쓰임 
  - 라이브러리 : 전체적인 프로그램의 주도권(흐름) 을 라이브러리를 가져다 쓰는 프로그래머가 가짐
  - 프레임워크 : 전반적인 주도권(흐름) 이 정해져 있고, 세부적인 부분을 프로그래머가 채움

```java
public abstract class Car {
    public abstract void drive ();  // 추상 메서드로 하위 클래스에서 상속받아 각각의 속성에 맞게 구현
    public abstract void stop ();
    
    public void startCar (){ ... };
    public void turnOff (){ ... };
    
    final public void run (){   // 순서(시나리오) 가 정해져 있음. 변경 불가능.
        startCar ();
        drive ();
        stop ();
        turnOff ();
    }
}
```

## 인터페이스 (Interface) 

- 모든 메서드가 추상 메서드로 선언됨 (public abstract)
- 모든 변수는 상수로 선언됨 (public static final)
- 클래스나 프로그램이 제공하는 기능을 클라이언트에게 명시적으로 선언해줌 -> 일종의 명세(specification)
- 클라이언트 프로그램은 인터페이스에 선언된 메서드 명세만 보고 구현부를 모르는 채로 사용할 수 있음
- 클래스 상속과는 달리 하나의 클래스에서 여러 인터페이스를 구현할 수 있다. (ex. `public class Customer implements Buy, Sell { ... }`) - 구현부가 없기 때문에 모호성이 없음
- 인터페이스 간의 상속도 가능

```java
public interface UserInfoDao {                        // 클라이언트 프로그램은 사용자 DB 만 설정해주면 인터페이스의 메서드만으로 각 DB 에 맞는 메서드를 사용할 수 있음
    void insertUserInfo (UserInfo userInfo);
    void updateUserInfo (UserInfo userInfo);
    void deleteUserInfo (UserInfo userInfo);
}

public class UserInfoMySqlDao implements UserInfo {   // MySql 을 사용하는 프로그램에 맞게 구현
    void insertUserInfo (UserInfo userInfo){ … };
    void updateUserInfo (UserInfo userInfo){ … };
    void deleteUserInfo (UserInfo userInfo){ … };
}

public class UserInfoOracleDao implements UserInfo {  // Oracle 을 사용하는 프로그램에 맞게 구현
    void insertUserInfo (UserInfo userInfo){ … };
    void updateUserInfo (UserInfo userInfo){ … };
    void deleteUserInfo (UserInfo userInfo){ … };
}
```

### 예외
- 디폴트 메서드 : 인터페이스에서 예외적으로 구현부를 가지는 메서드. 인터페이스를 구현하는 클래스들에서 공통으로 사용할 수 있는 기본 메서드로 default 키워드 사용
- 정적 메서드 : 인스턴스 생성과 상관 없이 인터페이스 타입으로 사용할 수 있는 메서드 
- private 메서드 : 인터페이스 내부에서만 사용하기 위해 구현하는 메서드로 default 메서드 혹은 static 메서드에서 사용





