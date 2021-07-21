# 전략 패턴 (Strategy Pattern) 

유사한 행위들을 캡슐화하여 각각의 전략으로 만들고 사용자는 행위를 바꾸고 싶은 경우 전략만 변경하게 하여 유연한 확장을 가능하게 하는 패턴으로 아래 세 가지 요소가 필요하다.
- 전략 메서드를 가진 전략 객체 (ex. Normal Strategy, Base64 Strategy)
- 전략 객체를 사용하는 컨텍스트 (ex. Encoder)
- 전략 객체를 생성해 컨텍스트에 주입하는 클라이언트

String 을 받아서 여러 인코딩 방식에 따라 인코딩한 후 출력해주는 프로그램을 예시로 보면, normal or base64 중 어떤 인코딩 방식을 사용할지에 대한 **전략객체**, 이 전략을 사용하여 기능을 수행하는 인코더가 **컨텍스트**, 인코딩된 결과물을 출력해주는 메인 함수가 **클라이언트** 이다. 


- 인코딩전략 인터페이스 
```java
public interface EncodingStrategy {
    String encoding(String message);
}
```

- Normal 인코딩 전략
```java
public class NormalStrategy implements EncodingStrategy{
    @Override
    public String encoding(String message) {
        return message;
    }
}
```

- Base64 인코딩 전략
```java
public class Base64Strategy implements EncodingStrategy{
    @Override
    public String encoding(String message) {
        return Base64.getEncoder().encodeToString(message.getBytes());
    }
}
```

- 인코더
```java
public class Encoder {
    private EncodingStrategy encodingStrategy;

    public String getMessage(String message){
        return encodingStrategy.encoding(message);
    }

    public void setEncodingStrategy(EncodingStrategy encodingStrategy){
        this.encodingStrategy = encodingStrategy;
    }
}
```

- 클라이언트
```java
Encoder base64Encoder = new Encoder();
base64Encoder.setEncodingStrategy(new Base64Strategy());    // Base64 전략 세팅
System.out.println(base64Encoder.getMessage("message"));

Encoder normalEncoder = new Encoder();
normalEncoder.setEncodingStrategy(new NormalStrategy());    // Normal 전략 세팅
System.out.println(normalEncoder.getMessage("message"));
```
