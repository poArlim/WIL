# 프록시 패턴 (Proxy Pattern)

proxy 는 대리인이라는 뜻으로, Proxy Class 를 통해서 client 에게 대신 전달하는 형태로 설계된다. Cache 의 기능으로도 활용한다.

- html 문서
```java
public Html {
    private String url;
    
    public Html (String url){
        this.url = url;
    }
}
```

- html 을 user 에게 보여주는 브라우져 인터페이스
```java
public interface IBrowser {
    Html show ();
}
```

- proxy 사용하지 않을 경우
```java
public class Browser implements IBrowser {
    private String url;
    
    public Browser (String url){
        this.url = url;
    }
    
    @Override
    public Html show (){
        System.out.println ("Browser loading html from "+url);
        return new Html(url);   // 서버로부터 html 을 받아와서 보여준다.
    }
}
```

- proxy 사용하는 경우
```java
public class BrowserProxy implements IBrowser {
    private String url;
    private Html html;
    
    public BrowserProxy (String url){
        this.url = url;
    }
    
    @Override
    public Html show (){
        if (html == null){
            this.html = new Html (url);   // 처음 한 번만 서버로부터 html 을 받아온다.
            System.out.println ("BrowserProxy loading html from "+url);
        }
        System.out.println("BrowserProxy use cached html"); // 이후부터는 cache 된 html 을 보여준다.
        return html;
    }
}
```

- 결과
```java
IBrowser browser1 = new Browser(url: "www.naver.com");
browser1.show();
browser1.show();
browser1.show();
browser1.show();
// 매번 서버로부터 html 을 로딩하여 보여줌

IBrowser browser2 = new BrowserProxy(url: "www.naver.com");
browser2.show()
browser2.show()
browser2.show()
browser2.show()
// 처음에만 서버로부터 html 을 받아오고 이후부터는 cache 된 html 을 보여줌
```
