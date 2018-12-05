#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct MOOCstudent {
	string studentNo;
	int gradeP = -1, gradeMidTerm = -1, gradeFinal = -1;
	int totalGrade = 0;
	bool isPassed() {
		double total = 0.0;
		if (gradeP < 200)
			return false;
		if (gradeMidTerm > gradeFinal)
			total = 0.4*(double)gradeMidTerm + 0.6*(double)gradeFinal;
		else
			total = gradeFinal;
		totalGrade = ((int)(total * 10) % 10 < 5) ? total : total + 1;
		if (totalGrade < 60)
			return false;
		return true;
	}
	void print() {
		cout << studentNo << " "
			<< gradeP << " "
			<< gradeMidTerm << " "
			<< gradeFinal << " "
			<< totalGrade << endl;
	}
};

bool compareMOOC(const MOOCstudent &ms1, const MOOCstudent &ms2) {
	if (ms1.totalGrade == ms2.totalGrade)
		return ms1.studentNo < ms2.studentNo;
	else
		return ms1.totalGrade > ms2.totalGrade;
}

int P1080() {
	int P, M, N;
	cin >> P >> M >> N;

	map<string, MOOCstudent> allStudents;

	//Input
	int grade;
	string No;
	for (int i = 0; i < P; i++) {
		cin >> No >> grade;
		allStudents[No].gradeP = grade;
		allStudents[No].studentNo = No;
	}
	for (int i = 0; i < M; i++) {
		cin >> No >> grade;
		allStudents[No].gradeMidTerm = grade;
		allStudents[No].studentNo = No;
	}
	for (int i = 0; i < N; i++) {
		cin >> No >> grade;
		allStudents[No].gradeFinal = grade;
		allStudents[No].studentNo = No;
	}

	vector<MOOCstudent> passedStudents;
	for (auto iter = allStudents.begin(); iter != allStudents.end(); ++iter)
		if (iter->second.isPassed())
			passedStudents.push_back(iter->second);

	sort(passedStudents.begin(), passedStudents.end(), compareMOOC);
	for (int i = 0; i < passedStudents.size(); ++i) {
		passedStudents[i].print();
	}

	return 0;
}