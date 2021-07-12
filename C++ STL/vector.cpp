#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> myVector;

    myVector.push_back(3); // 3 추가
    myVector.push_back(5); // 5 추가
    myVector.push_back(10);
    myVector.pop_back(); // 10 삭제
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
