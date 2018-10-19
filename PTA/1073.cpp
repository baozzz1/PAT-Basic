#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<int, vector<pair<int, char>>> maxError;

struct Question {
	int questionNo;
	int fullGrade, sectionNum, rightNum;
	vector<char> rightSections;
	map<char, int> errorSectionCount;
};

double readOneSectionP1073(string::iterator &beg, string::iterator &end, Question &question) {
	vector<char> rightSections(question.rightSections);
	bool allRight = true;
	int sectionNum = *(++beg) - '0';
	//if (sectionNum == 0)
	//	return 0.0;
	++beg;
	for (; beg != end; beg++) {
		if (*beg == ' ')
			continue;
		// 选择了错误答案的情况
		auto iter = find(rightSections.begin(), rightSections.end(), *beg);
		if (iter == rightSections.end()) {
			question.errorSectionCount[*beg]++;
			maxError[question.errorSectionCount[*beg]].push_back(make_pair(question.questionNo, *beg));
			allRight = false;
		}
		else
			rightSections.erase(iter);
	}

	//正确答案未被选完时:
	if (rightSections.size() != 0) {
		for (auto iter = rightSections.begin(); iter != rightSections.end(); ++iter) {
			question.errorSectionCount[*iter]++;
			maxError[question.errorSectionCount[*iter]].push_back(make_pair(question.questionNo, *iter));
		}
		//没有选择错误的答案
		if (allRight)
			return 0.5;
		else
			return 0.0;
	}
	else {
		//正确答案全被选完，且没选择错误的答案
		if (allRight)
			return 1.0;
		//正确答案全被选完，但是有错误的答案
		else
			return 0.0;
	}
}

double getOneStudentGradeP1073(string &line, vector<Question> &allQuestions) {
	double sum = 0;
	int questionIndex = 0;
	auto beg = line.begin();
	auto end = line.begin();
	for (; questionIndex < allQuestions.size(); questionIndex++) {
		beg = find(end, line.end(), '(');
		end = find(beg, line.end(), ')');
		sum += readOneSectionP1073(beg, end, allQuestions[questionIndex])* (double)allQuestions[questionIndex].fullGrade;
	}
	return sum;
}

bool sortWay(const pair<int, char> res1, const pair<int, char> res2) {
	if (res1.first == res2.first)
		return res1.second < res2.second;
	else
		return res1.first < res2.first;
}

int P1073() {
	int N, M;
	cin >> N >> M;
	vector<Question> allQuestions(M);

	//输入题目和答案
	//int fullGrade, sectionNum, rightNum;
	char rightSection;
	for (int i = 0; i < M; i++) {
		cin >> allQuestions[i].fullGrade >> allQuestions[i].sectionNum >> allQuestions[i].rightNum;
		allQuestions[i].questionNo = i + 1;
		for (int j = 0; j < allQuestions[i].rightNum; j++) {
			cin >> rightSection;
			allQuestions[i].rightSections.push_back(rightSection);
		}
	}
	getchar();	//换行

	//输入所有同学的答案
	string line;
	vector<double> grade(N, 0);
	//N位同学循环
	for (int i = 0; i < N; i++) {
		std::getline(cin, line);
		grade[i] = getOneStudentGradeP1073(line, allQuestions);
	}

	//输出
	for (int i = 0; i < N; i++)
		printf("%.1f\n", grade[i]);
	int maxErrorCount = 0;
	if (maxError.size() != 0) {
		for (auto iter = maxError.begin(); iter != maxError.end(); ++iter)
			if (maxErrorCount < iter->first)
				maxErrorCount = iter->first;
		//map<int,char> 题目编号，对应选项
		vector<pair<int, char>> res;
		for (auto iter = maxError[maxErrorCount].begin(); iter != maxError[maxErrorCount].end(); ++iter)
			res.push_back(make_pair(iter->first, iter->second));
		sort(res.begin(),res.end(), sortWay);
		for(auto iter = res.begin(); iter != res.end(); ++iter)
			cout << maxErrorCount << " " << iter->first << "-" << iter->second << endl;
	}
	else
		cout << "Too simple";
	return 0;
}