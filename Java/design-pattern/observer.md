# 관찰자 패턴 (Observer Pattern) 

변화가 일어났을 때, 미리 등록된 다른 클래스에 통보해주는 패턴을 구현한 것으로 event listener 에서 많이 사용된다.

- 이벤트리스너 인터페이스 
```java
public interface IButtonListener {
    void clickEvent(String event);
}
```

- 버튼 
```java
public class Button {
    private String name;
    private IButtonListener buttonListener;

    public Button(String name){
        this.name = name;
    }

    public void click(String clickEvent){
        buttonListener.clickEvent(this.name+", "+clickEvent);    // 버튼이 클릭되면 버튼클릭리스너에게 이벤트 전달
    }

    public void addListener(IButtonListener buttonListener){
        this.buttonListener = buttonListener;
    }
}
```

- 버튼이 클릭되면 리스너를 통해 이벤트 전달 
```java
public class Main {
    public static void main(String[] args){
        Button button = new Button("버튼1");
        
        button.addListener({    // 익명함수
            @Override
            public void clickEvent(String event){
                System.out.println(event);
            }
        });
      
        button.click("메시지 전달 : click 1");
        button.click("메시지 전달 : click 2");
    }
}
```
