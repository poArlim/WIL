# 큐의 특징 
큐는 FIFO(First-In-First-Out) 원칙을 지키는 자료구조이다.

# 사용방법
`#include <queue>` 

### 추가 및 삭제
- `push(element)` : 큐에 원소를 추가 (뒤에)
- `pop()` : 큐에서 원소를 삭제 (앞에서)

### 조회
- `front()` : 큐 제일 앞에 있는 원소를 반환
- `back()` : 큐 제일 뒤에 있는 원소를 반환

### 기타
- `empty()` : 큐가 비어있으면 `true` 아니면 `false` 를 반환
- `size()` : 큐 사이즈를 반환


### 구현코드
```c++
#include <iostream>
#include <queue>
using namespace std;

int main(){
    // 큐 생성
    queue<int> q;

    // push
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // pop
    q.pop();
    q.pop();
    q.pop();

    // front
    cout << "front element: " << q.front() << '\n';

    // back
    cout << "back element: " << q.back() << '\n';

    // size
    cout << "queue size: " << q.size() << '\n';

    // empty
    cout << "Is it empty?: " << (q.empty() ? "Yes" : "No") << '\n';

    return 0;
}
```
