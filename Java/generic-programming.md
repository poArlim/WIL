# 제네릭(Generic) 프로그래밍 

## 제네릭 자료형 

- 무엇이든 담을 수 있는 데이터 타입 
- 클래스에서 사용하는 변수의 자료형이 여러 개일 수 있고, 그 기능(메서드)은 동일한 경우 클래스의 자료형을 특정하지 않고 추후 사용할 때 지정할 수 있도록 선언

```java
public class GenericPrinter<T> {    // 자료형 매개변수(Type parameter) T
    
    private T material;
    
    public T getMaterial (){
        return material;
    }
    
    public void setMaterial (T material){
        this.material = material;
    }
}

public class GenericPrinterTest {
    
    public class void main (String[] args){
        GenericPrinter<Powder> powderPrinter = new GenericPrinter<>();
        powderPrinter.setMaterial (new Powder ());
        
        GenericPrinter<Plastic> powderPrinter = new GenericPrinter<>();
        powderPrinter.setMaterial (new Plastic ());
    }
}
```

## 범위 제한 

- T 자료형의 범위를 제한할 수 있음

```java
public abstract class Material { ... }

public class GenericPrinter<T extends Material> { ... } // Material 클래스를 상속받은 클래스만 T 에 들어갈 수 있다.

public class Powder extends Material{ ... }
public class Plastic extends Material{ ... }
```


## 제네릭 메서드 

- 자료형 매개변수를 매개변수나 반환 값으로 가지는 메서드 
- 자료형 매개변수가 하나 이상인 경우도 가능 
- 제네릭 클래스가 아니어도 내부에서 제네릭 메서드는 구현하여 사용 가능

```java
public class Point<T, V>{
    T x;
    V y;
    
    Point (T x, V y){   
        this.x = x;
        this.y = y;
    }
    
    public T getX (){   
        return x;
    }
    
    public V getY (){   
        return y;
    }
}

/* main */
public class GenericMethod {
    
    public static <T, V> double makeRectangle(Point<T, V> p1, Point<T, V> p2) { ... };  // Generic Method
    
    public static void main (String[] args) {
        Point<Integer, Double> p1 = new Point<>(0, 0.0);
        Point<Integer, Double> p2 = new Point<>(10, 10.0);
        
        double rect = GenericMethod.<Integer, Double>makeRectangle(p1, p2);
    }
}

```











