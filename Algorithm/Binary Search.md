# 이분 탐색(Binary Search) 

데이터 탐색 시 전체 범위를 두 부분으로 나누는 과정을 반복하여 탐색하는 기법으로 O(logn) 의 시간복잡도를 가지기 때문에 범위가 매우 큰 경우의 탐색에서 주로 사용된다. 

```C++
int binarySearch(vector<int> numbers, int dest){
    int left, right, mid;

    left = 0;
    right = numbers.size() - 1;
    
    while(left <= right){
        mid = (left + right) / 2
        
        if(numbers[mid] == dest) return mid;
        else if(numbers[mid] > dest) right = mid - 1;
        else left = mid + 1;
    }

    return -1;	// 탐색 실패
}
```
