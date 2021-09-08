## sort 함수
컨테이너의 원소들을 정렬하는 데 쓰이는 함수로 `#include <algorithm>` 안에 정의되어 있다.

### 사용방법
- 원형
```c++
template <typename T>
void sort(T start, T end, Compare comp);
```
comp 는 생략될 수 있으며 생략 시 default 로 오름차순(less) 정렬된다.

- `sort(arr, arr+n)`
- `sort(v.begin(), v.end())`
- `sort(v.begin(), v.end(), greater<int>())`
- `sort(v.begin(), v.end(), compare)`


### Compare
이 정리를 작성하는 이유로, 정렬의 규칙을 직접 사용자 정의함수로 만들 수 있다.  
`bool` 타입으로 정의하며, 비교 대상 2개의 인자를 받고, **return 값이 true 이면 그대로, false 이면 swap 이 일어난다.**  
- pair 의 두 번째 요소를 기준으로 오름차순 정렬
```c++
bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
```
```c++
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second < b.second) return true;
    else return false;
}
```
