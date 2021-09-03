# 람다(Lambda) 의 구성
<img width="674" alt="스크린샷 2021-09-03 오후 1 11 06" src="https://user-images.githubusercontent.com/43959582/131949377-11b84b94-8de4-4cde-ac8c-9a55daedf84a.png">

- 개시자 (introducer capture) : 람다식 내부에서 사용할 외부 변수를 지정
- 인자 (parameters)
- 반환 타입 (return type)
- 그리고 함수의 몸통 (statement)

## 게시자
람다식 내부에서 외부 변수를 가져다가 쓰고 싶은 경우 인자로 받아서 쓸 수도 있지만, 이 경우 인자가 맞지 않아 C++ 의 여러 STL 을 사용하는 데 어려움이 생긴다. 이를 방지하기 위해 게시자를 제공한다. 캡쳐하고자 하는 내용은 [] 안에 들어오게 되는데, 대표적으로 아래의 4가지 형태가 있다.
1. [&] : 외부의 모든 변수들을 레퍼런스로 가져온다. (call-by-reference)
2. [=] : 외부의 모든 변수들을 값으로 가져온다. (call-by-value)
3. [=, &x, &y] : 외부의 모든 변수들을 값으로 가져오되, x와 y만 레퍼런스로 가져온다.
4. [x, &y, &z] : x 는 값으로 y, z 는 레퍼런스로 가져온다.




- 람다식으로 표현한 재귀함수 예시
```c++
std::function<int(int)> fact;
fact = [&fact](int n) -> int {
  if (n == 0) {
    return 1;
  } else {
    return (n * fact(n - 1));
  }
};
cout << "factorial(4) : " << fact(4) << endl;
```




