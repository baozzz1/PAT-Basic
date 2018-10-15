#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1047() {
	int N;
	cin >> N;
	getchar();
	vector<int> teams(1001);
	int team, teammate, grade;
	int maxIndex = 1, maxGrade = 0;
	while (N--) {
		scanf_s("%d-%d %d", &team, &teammate, &grade);
		teams[team] += grade;
		if (teams[team] > maxGrade) {
			maxGrade = teams[team];
			maxIndex = team;
		}
	}
	cout << maxIndex << " " << maxGrade;
	return 0;
}