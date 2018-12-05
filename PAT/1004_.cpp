#include<iostream>
#include<string>
using namespace std;

int P1004_() {
	int n;
	cin >> n;
	string name, studentNo;
	int grade;
	if (n == 1) {
		cin>> name >> studentNo >> grade;
		cout << name << " " << studentNo << endl;
		cout << name << " " << studentNo << endl;
		return 0;
	}
	cin >> name >> studentNo >> grade;
	int maxGrade = grade, minGrade = grade;
	string maxName = name, maxStudentNo = studentNo;
	string minName = name, minStudentNo = studentNo;
	n--;
	while (n--) {
		cin >> name >> studentNo >> grade;
		if (grade > maxGrade) {
			maxGrade = grade;
			maxStudentNo = studentNo;
			maxName = name;
		}
		else if (grade < minGrade) {
			minGrade = grade;
			minStudentNo = studentNo;
			minName = name;
		}
	}
	cout << maxName << " " << maxStudentNo << endl;
	cout << minName << " " << minStudentNo << endl;

	return 0;
}