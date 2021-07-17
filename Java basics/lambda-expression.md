# 람다식 (Lambda Expression)

## 함수형 프로그래밍 (Functional Programming, FP) 

- 함수형 프로그래밍 방식을 람다식이라고 함
- FP 는 선언형 프로그래밍 방식
  - 명령형 프로그래밍 : 어떻게 풀어내는지 (how to solve) 에 집중
  - 선언형 프로그래밍 : 무엇을 풀어내는지 (what to solve) 에 집중
  - ex. 최종 목표가 '물을 마시기' 일 때
    - (명령형) 어떻게(how) 할 것인지를 설명
      1. 자리에서 일어난다.
      2. 부엌으로 이동한다.
      3. 컵과 물을 찾는다.
      4. 컵에 물을 부어 마신다.

    - (선언형) 무엇(what) 을 할 것인지를 설명
      1. 물을 마셔보자.


- 순수함수들의 조합으로 이루어진 식이다.
  - 순수함수란 매개변수만을 사용하여 만드는 함수 
  - 함수의 출력(return) 은 오로지 입력(input) 에만 의존하며, 동일한 입력에는 항상 같은 값을 반환한다.
  - 함수의 실행은 프로그램의 실행에 영향을 미치지 않는다. -> side effect 가 없다.
  - 입력 외의 외부 자료를 사용하지 않기 때문에 여러 자료가 동시에 수행되는 병렬처리가 가능하다.
  - 이러한 특징들로 인해 함수형 프로그램으로 이루어진 코드는 예상치 못한 Output 이 나왔을 때 Input 만 점검하면 된다.

## 람다식 문법 

- 익명 함수 만들기
- 매개 변수와 매개 변수를 이용한 실행문 (매개변수) -> {실행문;}

```java
(int x, int y) -> {retur x+y;}
```

- 매개 변수가 하나인 경우 자료형과 괄호 생략 가능
```java
str -> {System.out.println(str);}
```

- 실행문이 한 문장인 경우 중괄호 생략 가능
```java
str -> System.out.println(str);
```

- 실행문이 한 문장이라도 return문(반환문)은 중괄호를 생략할 수 없음
```java
str -> return str.length(); // 오류
```

- 실행문이 한 문장인 반환문인 경우엔 return과 중괄호를 모두 생략 가능
```java
(x, y) -> x+y;
str -> str.length;
```

## 함수형 인터페이스

- 람다식을 선언하기 위한 인터페이스 
- 익명 함수와 매개 변수만으로 구현되므로 인터페이스는 단 하나의 메서드만을 선언해야함
- @FunctionalInterface 애노테이션


```java
public interface MyNumber {
    int getMax (int num1, int num2);
}

public class TestMyNumber {
    public static void main (String[] args){
        MyNumber max = (x, y)->(x >=y) ? x : y; // 람다식을 인터페이스 자료형 max 변수에 대입
        
        System.out.println (max.getMax (10, 20));
    }
}
```
