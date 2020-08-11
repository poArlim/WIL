## 셋의 특징  
셋(Set) 은 트리를 사용하여 자료를 저장하는 연관 컨테이너로 맵과 구조나 사용방법이 거의 동일하지만, 한 가지 차이점은 셋은 key 만을 저장한다는 것입니다. 
맵과 동일하게 key 는 중복될 수 없으며 사용하는 상황은 맵을 사용하는 상황과 유사하지만 key 값이 존재하는지 아닌지만 알면 되는 경우에 사용합니다.

## 셋의 사용방법

우선적으로 헤더 파일을 포함해야 합니다.  
`#include <set>`

선언은 set<key_type> 변수이름 으로 key_type 만을 사용합니다. 역시 new 를 사용한 동적 할당도 가능합니다.

```c++
set<int> newSet;
set<int> *newSet2 = new set<int>;
```

셋도 기본적으로 오름차순으로 정렬되며 내림차순으로 정렬하고 싶을 시에는 greater 와 같은 비교함수를 사용하면 됩니다.

멤버함수와 다른 내용들은 맵과 동일하니 한 가지 사용 예만 들고 끝내도록 하겠습니다.  
셋에서 삽입의 성공, 실패의 리턴값은 pair<set::iterator, bool> 로 나옵니다.

```c++
set<int> mySet;
mySet.insert(1);

set::iterator setIt = mySet.begin();
cout<<"성공 여부 : "<<mySet.second<<endl;
```
