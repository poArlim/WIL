# 어뎁터 패턴 (Adapter Pattern) 

어뎁터 패턴은 호환성이 없는 기존 클래스의 인터페이스를 변환하여 재사용 할 수 있도록 만들어준다. 실생활에서 110v 를 220v 로 변경해주거나, 그 반대로 해주는 변환기 등이 어뎁터이다. 

- 110v 인터페이스
```java
public interface Electronic110V {
    public void powerOn ();
}
```

- 220v 인터페이스
```java
public interface Electronic220V {
    public void connect ();
}
```

- 110V 헤어드라이어, 220V 청소기
```java
public class HairDryer implements Electronic110V {
    @Override
    public void powerOn (){ ... }
}

public class Cleaner implements Electronic220V {
    @Override
    public void connect (){ ... }
}
```

- 어뎁터
```java
public class Adapter implements Electronic110V {
    public Electronic220V electronic220V;
    
    public Adapter (Electronic220V electronic220V){
        this.electronic220V = electronic220V;
    }
    
    @Override
    publci void powerOn (){
        electronic220V.connect ();
    }
}
```

- main
```java
// 콘센트 (110V 제품만 연결 가능)
public static void connect (Electronic110V electronic110V) {
    electronic110V.powerOn ();
}

public static void main (String[] args){
    Cleaner cleaner = new Cleaner ();
    Electronic110V adapter = new Adapter (cleaner);
    connect(adapter)
}
```
