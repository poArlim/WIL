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
