#include <iostream>
#include <list>
using namespace std;

int main(){
	list<int> myList;
	
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
	myList.push_back(10);
	myList.push_back(11);
	myList.push_back(12);

	for(list<int>::iterator iter = myList.begin(); iter != myList.end(); iter++){
		cout<<"List 의 데이터 : "<<*iter<<endl;
	}

	cout<<"첫 번째 데이터 : "<<myList.front()<<endl;
	cout<<"마지막 데이터 : "<<myList.back()<<endl;
	cout<<"데이터의 개수 : "<<myList.size()<<endl;

	myList.pop_front();
	cout<<"첫 번째 데이터 : "<<myList.front()<<endl;
	myList.pop_back();
	cout<<"마지막 데이터 : "<<myList.back()<<endl;
	cout<<"데이터의 개수 : "<<myList.size()<<endl;

	myList.insert(myList.begin(), 2); // myList 의 첫번째 위치에 2 삽입
	myList.insert(myList.end(), 2, 100); // myList 의 마지막 위치에 100을 2개 삽입
	for(list<int>::iterator iter = myList.begin(); iter != myList.end(); iter++){
		cout<<"List 의 데이터 : "<<*iter<<endl;
	}

	list<int>::iterator frontIter = myList.begin();
	for(int i = 0; i < 3; i++) frontIter++;

	myList.erase(frontIter, myList.end());
	cout<<"4번쨰부터 마지막 데이터 삭제"<<endl;

	for(list<int>::iterator iter = myList.begin(); iter != myList.end(); iter++){
		cout<<"List 의 데이터 : "<<*iter<<endl;
	}

	myList.remove(3);
	cout<<myList.back()<<endl;

	myList.clear();
	cout<<myList.size()<<endl;
	cout<<myList.empty()<<endl;

	return 0;
}
