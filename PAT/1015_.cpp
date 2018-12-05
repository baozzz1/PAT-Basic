#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct studentts {
	studentts(int a, int b, int c) :stNo(a), degrade(b), caigrade(c) {
		totalGrade = b + c;
	}
	int stNo;
	int degrade, caigrade;
	int totalGrade;
};

bool cmp(const studentts &s1, const studentts &s2) {
	if (s1.totalGrade == s2.totalGrade) {
		if (s1.degrade == s2.degrade)
			return s1.stNo < s2.stNo;
		else
			return s1.degrade > s2.degrade;
	}
	else
		return s1.totalGrade > s2.totalGrade;
}
int P1015_() {
	int N, L, H;
	int stNo;
	int degrade, caigrade;
	cin >> N >> L >> H;
	vector<vector<studentts>> sts(4);
	for (int i = 0; i < N; i++) {
		cin >> stNo >> degrade >> caigrade;
		if (degrade >= H) {
			if (caigrade >= H)
				sts[0].push_back(studentts(stNo, degrade, caigrade));
			else if(caigrade>=L)
				sts[1].push_back(studentts(stNo, degrade, caigrade));
		}
		else if (degrade >= L && caigrade >= L) {
			if(degrade>=caigrade)
				sts[2].push_back(studentts(stNo, degrade, caigrade));
			else
				sts[3].push_back(studentts(stNo, degrade, caigrade));
		}
	}
	int M = 0;
	for (int i = 0; i < 4; i++){
		sort(sts[i].begin(), sts[i].end(), cmp);
		M += sts[i].size();
	}
	cout << M << endl;
	for(int i=0;i<4;i++)
		for (int j = 0; j < sts[i].size(); j++) {
			cout << sts[i][j].stNo << " " << sts[i][j].degrade << " " << sts[i][j].caigrade << endl;
		}
	return 0;
}