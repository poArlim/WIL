# 데코레이터 패턴 (Decorator Pattern) 

기존 뼈대(클래스)는 유지하되, 이후 필요한 형태로 꾸밀 때 사용한다. 확장이 필요한 경우 상속의 대안으로도 활용한다. 예를들어, 커피를 만들 때 기존 뼈대인 에스프레소에 우유, 시럽, 물 등 어떤 재료를 추가하는지에 따라 다른 형태로 확장이 되는 것을 데코레이터 패턴으로 볼 수 있다.

- 커피 추상 클래스
```java
public abstract class Coffee {
    public abstract void brewing();
}
```

- 기본 에스프레소
```java
public class Espresso extends Coffee{
    @Override
    public void brewing(){
        // Brewing Here
    }
}
```

- 데코레이터 - 혼자서는 생성될 수 없고 기존 클래스(에스프레소) 혹은 다른 보조 클래스(다른 커피)들을 매개변수로 받아서 새로운 형태로 확장한다.
```java
public abstract class Decorator extends Coffee {
    Coffee coffee;
    
    public Decorator(Coffee coffee){
        this.coffee = coffee;
    }
    
    @Override
    public void brewing(){
        coffee.brewing();
    }
}
```

- 커피에 우유 첨가 -> 라떼
```java
public class Latte extends Decorator{
    public Latte(Coffee coffee){
        super(coffee);
    }
    
    public void brewing(){
        super.brewing();
        // Adding Milk Here
    }
}
```

- 커피에 모카 시럽 첨가 -> 모카 커피
```java
public class Mocha extends Decorator{
    public Mocha(Coffee coffee){
        super(coffee);
    }
    
    public void brewing(){
        super.brewing();
        // Adding Mocha Syrup Here
    }
}
```

- 커피에 휘핑 크림 첨가 -> 휘핑 크림이 올라간 커피
```java
public class WhippedCream extends Decorator{
    public WhippedCream(Coffee coffee){
        super(coffee);
    }
    
    public void brewing(){
        super.brewing();
        // Adding WhippedCream Here
    }
}
```

- 커피 제조 
```java
public class CoffeeTest{
    public static void main(String[] args){
        Coffee espresso = new Espresso();
        espresso.brewing();    // 에스프레소 제조
        
        Coffee latte = new Latte(espresso);
        latte.brewing();        // 에스프레소 + 우유 = 라떼 제조
        
        Coffee mochaLatte = new Mocha(latte);
        //Coffee mochaLatte = new Mocha(new Latte(new Espresso());    -> 새로운 라떼를 만들어서 사용할 수도 있음
        mochaLatte.brewing();   // 라떼 + 모카시럽 = 모카라떼
        
        Coffee whippedCreamMochaLatte = new WhippedCream(mochaLatte);
        whippedCreamMochaLatte.brewing();    // 휘핑크림이 올라간 모카라떼
    }
}
```
