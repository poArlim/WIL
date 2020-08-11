## 해시 맵의 특징  
해시 맵은 list, vector, deque 등의 시퀀스 컨테이너와는 다른 연관 컨테이너로 자료를 Key 와 연관지어서 저장합니다. 이러한 구조로 인하여 대량의 자료에서도 빠른 검색 속도를 유지할 수 있는 것이 특징입니다.  
이름에서 알 수 있듯이 해시 맵(Hash Map)은 해시 테이블을 사용하는 자료 구조입니다.  
여기서 Hash 란 어떤 key 값이 주어졌을 때 이 값을 특정 함수에 넣어서 결과 값을 얻는 방법으로 이 때 사용되는 함수를 hash function 이라고 하며, 이 과정을 hashing 이라고 합니다. hash function 은 입력에 대하여 항상 같은 출력이 나와야 하며 그 결과 값은 데이터가 저장되는 메모리 공간(버킷)의 각 인덱스로 매칭됩니다.  
해시 테이블은 위와 같은 방식을 사용하여 데이터를 저장하는 자료구조로 key 값을 hash function 에 넣어서 나온 번호의 버킷에 매칭되는 value 를 저장합니다. 따라서 key 값을 넣었을 때 아무리 데이터의 양이 많아도 검색하는 데 걸리는 시간은 O(1) 을 지행하며 거의 일정합니다.  
하지만 데이터의 삽입, 삭제 등은 시퀀스 컨테이너보다 속도가 느리기 때문에 자료의 크기가 별로 크지 않거나 삽입, 삭제 등의 작업이 빈번하게 이루어 지는 경우에는 사용을 지양하는 것이 좋습니다.

## 해시 맵의 사용방법

한 가지 주의할 점은 해시 맵은 STL 표준에 포함되지 않고 대신 STL 표준에 포함되어 있는 unordered_map 을 사용하기를 권장합니다. 사용 방법은 hash_map 과 거의 동일합니다.  

우선적으로 헤더 파일을 포함해야 합니다.  
`#include <unordered_map>`

선언은 unordered_map<key_type, value_type> 변수이름 으로 할 수 있으며 new 를 사용한 동적 할당도 가능합니다.

```c++
unordered_map<int, float> newMap;
unordered_map<int, float> *newMap2 = new unordered_map<int, float>;
```

해시 맵은 시퀀스 컨테이너 처럼 앞, 뒤에서 자료를 추가해야 할 필요가 없습니다. 따라서 주로 많이 사용하는 기능은 insert(추가), erase(삭제), find(검색) 이고 자주 사용하는 멤버함수는 아래와 같습니다. 
|멤버|설명|
|:---|:---|
|insert|데이터 쌍 삽입|
|erase|특정한 위치의 원소 혹은 지정한 위치의 원소들을 삭제|
|find|키에 연관된 위치의 반복자 반환|
|begin|첫번째 위치의 반복자 반환|
|end|마지막 다음 위치의 반복자 반환|
|rbegin|역방향으로 첫번재 위치의 반복자 반환|
|rend|역방향으로 마지막 다음 위치의 반복자 반환|
|clear|모든 데이터 삭제|
|empty|덱이 비어 있으면 true, 아니면 false 반환|
|size|데이터의 개수를 반환|


각 멤버함수의 사용방법은 아래 코드를 참고하세요.
```c++
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    unordered_map<int, float> scoreMap;
    int stdNum = 1;
    float score;

    // 학생 10 명의 시험성적 입력
    for(stdNum = 1; stdNum <= 10; stdNum++){
        cout<<stdNum<<" 번 학생의 점수를 입력하세요 : ";
        cin>>score;
        scoreMap.insert(make_pair(stdNum, score));
    }

    // 한 명 더 입력
    scoreMap.insert(pair<int, float>(stdNum++, 60)); // 이렇게도 사용 가능

    // 마지막 한 명 더 입력
    scoreMap[stdNum] = 100; // 이렇게도 가능

    // 출력
    unordered_map<int, float>::iterator scoIt = scoreMap.begin();
    for(scoIt = scoreMap.begin(); scoIt != scoreMap.end(); scoIt++){
        stdNum = scoIt->first;
        score = scoIt->second;
        cout<<stdNum<<" 번 학생의 점수는 "<<score<<" 점 입니다."<<endl;
    }

    // 검색
    cout<<"8번 학생의 점수는 "<<scoreMap.find(8)->second<<"점 입니다."<<endl;

    // 삭제
    cout<<"8번 학생의 데이터 삭제"<<endl;
    scoreMap.erase(8);

    cout<<"앞에 다섯 학생의 데이터 삭제"<<endl;
    scoIt = scoreMap.begin();
    for(int i = 0; i < 4; i++){
        scoIt++;
    }
    scoreMap.erase(scoreMap.begin(), scoIt);

    // 출력
    for(scoIt = scoreMap.begin(); scoIt != scoreMap.end(); scoIt++){
        stdNum = scoIt->first;
        score = scoIt->second;
        cout<<stdNum<<" 번 학생의 점수는 "<<score<<" 점 입니다."<<endl;
    }

    cout<<scoreMap.size()<<endl;

    cout<<scoreMap.empty()<<endl;

    return 0;
}
```

