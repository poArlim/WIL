# 스트림 (Stream) 

## 스트림이란? 

- 자료의 대상과 관계없이 동일한 연산을 수행 (배열, 컬렉션을 대상으로 연산을 수행 함)
- 일관성 있는 연산으로 자료의 처리를 쉽고 간단하게 함
- 자료 처리에 대한 추상화가 구현되었다고 함

- 스트림을 생성하면 스트림을 위한 메모리 공간이 별도로 생성 -> 기존 자료를 변경하지 않음
- 한 번 생성하고 사용한 스트림은 소모되어 재사용이 불가 -> 다른 연산을 수행하기 위해서는 재생성 해야 한다.

## 생성 및 사용 

- 중간연산 : 조건에 맞는 요소를 추출(filter) 하거나 변환(map) 함. 최종연산이 수행되기 전까지 중간연산에 대한 수행은 미루어진다. (지연연산)
  - ex. filter(), map(), sorted() 등
- 최종연산 : 스트림이 관리하는 자료를 하나씩 소모해가며 연산이 수행 됨. 최종 연산 후에 스트림은 소모되어 재사용이 불가함
  - ex. forEach(), count(), sum() 등
- 중간 연산과 최종 연산에 대한 구현은 람다식을 활용

```java
// 문자열 리스트에서 문자열의 길이가 5 이상인 요소만 출력
sList.stream().filter(s->s.length() >= 5).forEach(s->System.out.println(s));
```

```java
// 고객 클래스 배열에서 고객 이름만 가져오기
customerList.stream().map(c->c.getName()).forEach(s->System.out.println(s));
```

## reduce() 연산 

- 정의된 연산이 아닌 직접 구현한 연산을 적용

```
T reduce (T identify, BinaryOperator<T> accumulator)
```

- ex. 배열의 모든 요소의 합을 구하는 reduce() 연산 (첫 번째 파라미터 : 초기화 값, 두 번째 파라미터 : 람다식)

```
Arrays.stream(arr).reduce(0, (a,b)->a+b));
```

- 람다식을 직접 구현하거나 람다식이 긴 경우 BinaryOperator 를 구현한 클래스를 사용
- ex. 여러 문자열 중 길이가 가장 긴 문자열 찾기 

```java
class CompareString implements BinaryOperator<String>{
    @Override
    public String apply(String s1, String s2) {
        if (s1.getBytes().length >= s2.getBytes().length) return s1;
        else return s2;
    }
}

public class ReduceTest {
    public static void main(String[] args) {
        String[] greetings = {"안녕하세요", "hello", "Good morning", "반갑습니다"};
        
        // 방법 1
        System.out.println(Arrays.stream(greetings).reduce("", (s1, s2)-> {
            if (s1.getBytes().length >= s2.getBytes().length) 
                return s1;
            else return s2;
            })); 

        // 방법 2
        String str = Arrays.stream(greetings).reduce(new CompareString()).get(); //BinaryOperator를 구현한 클래스 이용
        System.out.println(str);

    }
}
```
