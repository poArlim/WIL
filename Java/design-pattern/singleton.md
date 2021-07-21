# 싱글톤 패턴(Singleton Pattern) 

어떤 클래스(객체)가 유일하게 한 개만 존재하여야 할 때 사용한다. 주로 서로 자원을 공유할 때 사용하는데, 실물 세계의 프린터, 프로그래밍의 TCP Socket 에서 connect 객체에 주로 사용한다. 

- 기본 생성자를 private 으로 선언하여 외부에서 선언할 수 없도록 막아준다.
- 클래스 내부에서 객체를 하나 선언
- getInstance() 메서드로 인스턴스를 외부에서 사용할 수 있도록 해준다.
```java
public class SocketClient {
    private static SocketClient socketClient = null;
    
    private SocketClient (){};    // default 생성자 막기
    
    public static SocketClient getInstance (){
        if (socketClient == null){
            socketClient = new SocketClient ();
        }
        return socketClient;
    }
    
    public void connet (){
        System.out.println ("socket");
    }
}
```
```java
public class AClazz {
    private SocketClient socketClient;
    
    public AClazz (){
        this.socketClient = SocketClient.getInstance ();
    }
    
    public SocketClient getSocketClient (){
        return socketClient;
    }
    
    public void setSocketClient (SocketClient socketClient){
        this.socketClient = socketClient;
    }
}
```
```java
AClazz aClazz = new AClazz ();
BClazz bClazz = new BClazz ();

SocketClient aClient = aClazz.getSocketClient ();
SocketClient bClient = bClazz.getSocketClient ();

// aClient.equals(bClient) == true
```
