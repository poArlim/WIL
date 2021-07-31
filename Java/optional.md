# Optional<T>
  
'존재 할 수도 있고 안 할 수도 있는 객체', 즉 'null 이 될 수 있는 객채'를 포장해주는 래퍼 클래스(Wrapper class) 로 null 이 올 수 있는 값을 감싸서 NPE(NullPointerException) 이 발생하지 않도록 도와준다. 

- 구조
```java
public final class Optional<T>{

	// If non-null, the value; if null, indicates no value is present
	private final T value;
	...
}
```
	
	
- 사용 : 만일 어떤 객체가 null 이 올 수 있는 경우에 해당 값을 Optional 로 감싸서 생성하고, orElse, orElseGet 메서드를 이용해서 값이 없는 경우라도 안전하게 값을 가져올 수 있다.
	
```java
// ofNullable : null 인지 아닌지 확신할 수 없는 경우
Optilnal<String> optional = Optional.ofNullable(getName());

// 값이 없다면 "anonymous" 를 리턴
String name = optional.orElse("anonymous");
```
	
- isPresent() : Optional 객체에 값이 존재하는지 확인
- isEmpty() : Optional 객체가 비어있는지 확인
- orElse(T other) : 비어있는 Optional 객체의 경우 넘어온 인자를 반환 (객체가 비어있지 않은 경우에도 함수는 호출된다.)
- orElseGet(Supplier<? extends T> other) : orElse 와 동일한 기능을 수행하지만, 비어있는 객체의 경우에만 함수가 호출된다.
- get() : Optional 객체에 내용물을 반환해주고, 비어있는 경우 NoSuchElementException 을 던진다.
