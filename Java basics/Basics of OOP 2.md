# 정보은닉 (Information Hiding) 

## 접근 제어 지시자 (Access modifier) 

- 정보의 오용을 방지 
- private : 같은 클래스 내부에서만 접근 가능 (외부 클래스, 상속 관계의 클래스에서도 접근 불가) 
- protected : 같은 패키지나 상속 관계의 클래스에서만 접근 가능 
- public : 클래스의 외부 어디서나 접근 가능 
- defualt(아무것도 없음) : 같은 패키지 내부에서만 사용 가능 (상속 관계라도 패키지가 다르면 접근 불가) 

## get/set 메서드 

- private 으로 선언된 멤버 변수에 대해 접근, 수정할 수 있는 메서드를 public 으로 제공
- read-only 필드를 만들고 싶으면 get() 메서드만 제공하면 됨

```java
public class BirthDay {
  private int day;
  
  public int getDay () {
      return day;
  }
  
  public void setDay (int day) {
      this.day = day;
  }
}
```

## 캡슐화 (Encapsulation) 

- 꼭 필요한 정보와 기능만 외부에 오픈
- 대부분의 멤버 변수와 메서드를 감추고 외부에 통합된 인터페이스만을 제공하여 일관된 기능을 구현하게 함
- 각각의 메서드나 멤버 변수에 접근함으로서 발생하는 오류를 최소화

```java
public class MakeReport {
    StringBuffer buffer = new StringBuffer ();
    
    private void makeHeader (){ ... }
    private void generateBody (){ ... }
    private void makeFooter (){ ... }
    
    public String getReport (){
        makeHeader ();
        generateBody ();
        makeFooter ();
        return buffer.toString ();
    }
}
```

## this 

- 객체 자신을 가리킴 -> 인스턴스 자신의 메모리를 가리킴

￼![BirthDay day = new BirthDayO;](https://user-images.githubusercontent.com/43959582/125569425-84f953da-c900-466a-bcbe-44a1dd4c5a82.png)

- 생성자에서 또 다른 생성자를 호출할 때 사용
  - 클래스에서 생성자가 여러 개인 경우, this 키워드를 이용하여 생성자에서 다른 생성자를 호출할 수 있음 (이 경우, 인스턴스 생성이 완전하지 않은 상태이므로 this() statement 이전에 다른 statement 를 쓸 수 없음) 

```java
public class Person {
    String name;
    int age;
    
    public Person (){
        this("no name", 1);
    }
    
    public Person (String name, int age){
        this.name = name;
        this.age = age;
    }
}
```

## static 변수 

- 여러 인스턴스에서 공통으로 사용하는 변수 (static 이 없으면 각 인스턴스는 각각의 멤버 변수를 가짐)
- 인스턴스가 생성될 때 만들어지지 않고, 처음 프로그램이 메모리에 로드될 때 메모리에 할당됨 -> 데이터 영역 
- 인스턴스 생성과 상관 없이 사용 가능하며 클래스 이름을 직접 참조 

```java
public class Student {
    private static int serialNum = 1000;   // 인스턴스가 생성될 떄마다 1씩 증가해야 하므로 static 변수로 설정
    private int studentId;
    
    public Student (){
        serialNum++;
        studentId = serialNum;
    }
}
```
- static 메서드에서는 인스턴스 변수를 사용할 수 없음 (인스턴스 생성과 무관하게 호출 될 수 있기 때문)

### 싱글톤 패턴 (Singleton pattern) 

- 인스턴스가 단 하나만 생성되어야 하는 경우 사용하는 디자인 패턴 (날짜 등의 객체)

```java
public class Company {
    private static Company instance = new Company ();   // 하나의 인스턴스를 클래스 내부에서 생성
    
    private Company (){}   // 생성자를 private 으로 정의하여 외부에서 인스턴스 생성이 불가능하게 만듬
    
    public static Company getInstance (){    // static 메서드로 선언하여 외부에서 인스턴스 생성 없이 사용 가능
        return instance;
    }
}
```





