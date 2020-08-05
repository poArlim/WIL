#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b){
	return a > b ? a : b;
}

int main(){
	int sec1 = 1;
	int sec2 = 2;
	cout<<Max(sec1, sec2)<<endl;

	float score1 = 97.5;
	float score2 = 50.8;
	cout<<Max(score1, score2)<<endl;
	return 0;
}
