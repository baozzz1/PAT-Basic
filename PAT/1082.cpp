#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int P1082() {
	int N;
	cin >> N;
	int maxGrade = 0;
	int maxID, minID;
	int minGrade = 2e4 + 1;
	int ID, x, y, grade;
	for (int i = 0; i < N; i++) {
		cin >> ID >> x >> y;
		grade = x * x + y * y;
		if (grade > maxGrade) {
			maxGrade = grade;
			maxID = ID;
		}
		if (grade < minGrade) {
			minGrade = grade;
			minID = ID;
		}
	}
	cout << setw(4) << setfill('0') << minID << " ";
	cout << setw(4) << setfill('0') << maxID;
	return 0;
}