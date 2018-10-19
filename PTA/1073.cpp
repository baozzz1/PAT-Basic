#include<iostream>
#include<string>
#include<vector>
using namespace std;


struct Question {
	int fullGrade, sectionNum, rightNum;
	string rightSections;
};

bool readOneSectionP1073(string::iterator &beg, string::iterator &end, vector<Question> &allQuestions, const int &questionIndex) {
	int sectionNum = *(++beg) - '0';

	/*if (sectionNum != allQuestions[questionIndex].rightNum)
		return false;
	int rightIndex = 0;
	for (auto iter = beg + 1; iter != end; iter++) {
		if (*iter >= 'a'&&*iter <= 'e') {
			if (*iter != allQuestions[questionIndex].rightSections[rightIndex++])
				return false;
		}
	}*/
	return true;
}

int getOneStudentGradeP1073(string &line, vector<Question> &allQuestions) {
	int sum = 0;
	int questionIndex = 0;
	auto beg = line.begin();
	auto end = line.begin();
	for (; questionIndex < allQuestions.size(); questionIndex++) {
		beg = find(end, line.end(), '(');
		end = find(beg, line.end(), ')');
		if (readOneSectionP1073(beg, end, allQuestions, questionIndex))
			sum += allQuestions[questionIndex].fullGrade;
	}
	return sum;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<Question> allQuestions(M);

	//输入题目和答案
	int fullGrade, sectionNum, rightNum;
	char rightSection;
	for (int i = 0; i < M; i++) {
		cin >> allQuestions[i].fullGrade >> allQuestions[i].sectionNum >> allQuestions[i].rightNum;
		for (int j = 0; j < allQuestions[i].rightNum; j++) {
			cin >> rightSection;
			allQuestions[i].rightSections.push_back(rightSection);
		}
	}
	getchar();	//换行

	//输入所有同学的答案
	string line;
	vector<int> grade(N, 0);
	//N位同学循环
	for (int i = 0; i < N; i++) {
		std::getline(cin, line);
		grade[i] = getOneStudentGradeP1073(line, allQuestions);
	}
	return 0;
}