#include <iostream>
using namespace std;

template <typename T1, typename T2>
T2 multiply(T1 a, T2 b){
	return a * b;
}

int main(){
	int num1 = 3;
	float num2 = 2.4;
	cout<<multiply(num1, num2);

	return 0;
}
