## 우선순위 큐  
일반적인 큐는 FIFO(First-In-First-Out) 구조인 것과 달리 우선순위 큐는 들어온 순서에 상관 없이 우선순위가 높은 데이터가 먼저 나가는 구조이다.  
우선 순위 큐는 내부 데이터들이 항상 정렬된 상태를 유지하기 위하여 힙(Heap) 자료구조로 관리되며 그 이유는 아래와 같다.  
1. 리스트를 사용 시 데이터를 삽입할 때 삽입 위치를 찾기 위해 O(n), 해당 위치에 데이터를 삽입 후 뒤 데이터들을 모두 한 칸씩 뒤로 미루기 위해 O(n) 의 시간복잡도를 갖는다.
2. 데이터들을 뒤로 한 칸씩 미루는 작업을 생략하기 위해 연결리스트를 사용하여도 데이터의 삽입 위치를 찾는 데 O(n) 의 시간복잡도가 생긴다.
3. 힙으로 구현 시 O(logn) 의 시간복잡도로 삽입, 삭제가 가능하다.  


## 사용방법  
queue 헤더파일에 함께 정의되어 있다.  
`#include <queue>`

기본 컨테이너는 vector, 비교함수는 less(내림차순) 이며 초기화 할 때 변경해 줄 수 있다.  
```c++
priority_queue<int> pq; // 기본 컨테이너, 내림차순으로 초기화  
priority_queue<int, vector<int>, greater<int>>  // 오름차순으로 관리되도록 초기화  
```

멤버함수는 queue 와 비슷하다.
|멤버|설명|
|:---|:---|
|push|맨 뒤에 데이터 추가|
|pop|맨 앞의 데이터 제거|
|top|첫 데이터 반환|
|empty|우선순위 큐가 비어있으면 true, 아니면 false 반환|
|size|우선순위 큐의 데이터 개수를 반환|


### compare 함수 작성
compare 함수는 priority queue 의 정렬 방식을 지정해주는 함수이다.
- pair 의 second 를 기준으로 오름차순 정렬
```c++
struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({1, 10});
    pq.push({2, 3});
    pq.push({3, 1});
    cout<<pq.top().first; // 출력 : 3
    cout<<pq.top().second; // 출력 : 1
}
```
