#include<iostream>
#include<vector>
#include<map>
using namespace std;

int P1038() {
	int N, K;
	cin >> N;
	map<int,int> grades;
	int grade;
	while (N-- && cin >> grade)
		grades[grade]++;
	cin >> K;
	vector<int> searchs(K);
	for (int j = 0; j < K; j++)
		cin >> searchs[j];
	for (int j = 0; j < K - 1; j++)
		cout << grades[searchs[j]] << " ";
	cout << grades[searchs[K - 1]];
	return 0;
}