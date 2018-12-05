#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct PATschool {
	int getGrade() { return (int)totalGrade; }
	string school;
	int studentsCount = 0;
	double totalGrade = 0.0;

};
void print(const int &rankLevel,PATschool &p) {
	cout << rankLevel << " " << p.school << " " << p.getGrade() << " " << p.studentsCount << endl;
}
bool comparePAT(PATschool &p1, PATschool &p2) {
	if (p1.getGrade() == p2.getGrade())
		if (p1.studentsCount == p2.studentsCount)
			return p1.school < p2.school;
		else
			return p1.studentsCount < p2.studentsCount;
	else
		return p1.getGrade() > p2.getGrade();
}

void toLower(string &s) {
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 'a' - 'A';
}
int P1085() {
	int N;
	cin >> N;
	string No, school;
	int grade;
	double factor;
	map<string, PATschool> rank;
	for (int i = 0; i < N; i++) {
		cin >> No >> grade >> school;
		toLower(school);
		switch (No[0]){
		case 'B':
			factor = 1 / 1.5;
			break;
		case 'A':
			factor = 1;
			break;
		case 'T':
			factor = 1.5;
			break;
		}
		rank[school].school =school;
		rank[school].totalGrade += factor * (double)grade;
		rank[school].studentsCount++;
	}
	cout << rank.size() << endl;
	vector< PATschool> orderedSchool;
	for (auto iter = rank.begin(); iter != rank.end(); ++iter)
		orderedSchool.push_back(iter->second);
	sort(orderedSchool.begin(), orderedSchool.end(), comparePAT);
	int lastGrade = orderedSchool[0].getGrade();
	int rankLevel = 1;
	print(rankLevel,orderedSchool[0]);
	for (int i = 1; i < orderedSchool.size(); i++) {
		if (orderedSchool[i].getGrade() != lastGrade) {
			rankLevel = i + 1;
			lastGrade = orderedSchool[i].getGrade();
		}
		print(rankLevel,orderedSchool[i]);
	}
	return 0;
}