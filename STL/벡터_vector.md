## 벡터의 특징
벡터는 배열과 비슷하게 index 와 그에 해당하는 데이터로 이루어진 자료구조이며, 배열과 다른 점은 배열은 그 크기가 고정되어 있지만 벡터는 동적으로 변한다는 점입니다.  
따라서 배열의 특징을 거의 동일하게 가져오며 정리하면 아래와 같습니다.
1. 데이터를 순차적으로 저장하므로, 중간에 데이터의 삽입이나 삭제는 시간이 오래 걸린다.
2. 위와 같은 이유로 데이터의 크기가 클 때 검색 속도는 빠르지 않다. 검색을 자주한다면, map, set, hash_map 을 이용하는 것이 실행 속도를 줄일 수 있다.
3. 데이터의 랜덤 접근이 가능하다.

## 벡터의 사용방법
우선적으로 벡터 헤더 파일을 포함해야 합니다.  
`#include <vector>`

선언은 vector<자료type> 변수이름 으로 할 수 있으며 new 를 사용한 동적 할당도 가능합니다.
```c++
vector<int> newVec;
vector<int> *newVec2 = new vector<int>;
```

벡터에서 자주 사용되는 멤버함수는 아래와 같습니다.
|멤버|설명|
|:---|:---|
|push_back|마지막에 데이터를 하나 추가|
|pop_back|마지막 데이터 하나 삭제|
|front|첫번째 원소의 참조값 반환|
|back|마지막 원소의 참조값 반환|
|begin|첫번째 위치의 반복자 반환|
|end|마지막 다음 위치의 반복자 반환|
|rbegin|역방향으로 첫번재 위치의 반복자 반환|
|rend|역방향으로 마지막 다음 위치의 반복자 반환|
|at|특정 위치 원소의 참조값 반환(배열식으로 접근도 가능)|
|clear|모든 데이터 삭제|
|empty|벡터가 비어 있으면 true, 아니면 false 반환|
|insert|특정 위치에 원소 삽입|
|size|데이터의 개수를 반환|
|swap|두 개의 벡터를 서로 맞바꿈|
|erase|특정한 위치의 원소 혹은 지정한 위치의 원소들을 삭제|
|assign|특정 데이터로 벡터를 채움, 벡터에 데이터가 이미 있다면 모두 삭제되고 새로 채워짐|

각각의 멤버의 사용 방법은 아래와 같습니다.
```c++
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> myVector;

    myVector.push_back(3); // 3 추가
    myVector.push_back(5); // 5 추가
    myVector.push_back(10);
    myVector.pup_back(); // 10 삭제
    cout<<myVector.front()<<endl; // 3 출력
    cout<<myVector.back()<<endl; // 5 출력
    cout<<*myVector.begin()<<endl; // 3 출력

    for(vector<int>::iterator myIter = myVector.begin(); myIter != myVector.end(); myIter++){
        cout<<*myIter<<endl;
    }

    cout<<myVector.at(0)<<endl; // 3 출력
    cout<<myVector[0]<<endl; // 배열 식으로도 접근 가능. 3 출력

    myVector.clear(); // 데이터 모두 삭제
    cout<<myVector.empty()<<endl; // true 반환

    vector<int>::iterator iterPos = myVector.begin();
    myVector.insert(iterPos, 100); // 특정 위치에 100 하나 삽입
    myVector.insert(iterPos, 2, 200); // 특정 위치에 2 개의 200 삽입

    cout<<myVector.size()<<endl; // 저장된 데이터의 개수 출력

    iterPos = myVector.begin();
    myVector.erase(myVector.begin()); // 첫 번째 데이터 삭제
    myVector.erase(myVector.begin(), myVector.end()); // 첫번째부터 마지막까지 데이터 삭제

    myVector.insert(myVector.begin(), 3, 100); // 100 100 100
    vector<int> yourVector;
    yourVector.assign(3, 200); // 200 200 200

    myVector.swap(yourVector); // myVector 와 yourVector 를 바꿈

    for(vector<int>::iterator myIter = myVector.begin(); myIter != myVector.end(); myIter++){
        cout<<*myIter<<endl;
    }

    myVector.assign(yourVector.begin(),  yourVector.end()); // 지정한 위치의 데이터로 벡터를 채움

        for(vector<int>::iterator myIter = myVector.begin(); myIter != myVector.end(); myIter++){
        cout<<*myIter<<endl;
    }

    return 0;
}
```
