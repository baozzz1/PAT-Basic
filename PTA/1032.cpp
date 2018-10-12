#include<iostream>
#include<map>
using namespace std;

int P1032() {
	int N;
	cin >> N;
	int school, score;
	int maxScore = 0;
	int maxSchool = 0;
	map<int,int> data;
	while (N--) {
		cin >> school >> score;
		data[school] += score;
		if(data[school]>= maxScore){
			maxScore = data[school];
			maxSchool = school;
		}
	}
	cout << maxSchool << ' ' << maxScore;
	return 0;
}