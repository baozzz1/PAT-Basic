#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// 数组复制应该用指针
struct question {
	question() {}
	question(int qNo, int g, int t, int r, vector<char> opt) :questionNo(qNo), fullGrade(g), totalNum(t), rightNum(r), options(opt) {}
	int questionNo;
	int fullGrade, totalNum, rightNum;
	vector<char> options;

};
struct errorQuestion {
	errorQuestion() {}
	errorQuestion(int qNo) :questionNo(qNo) {}
	int questionNo;
	int errorCount = 0;
};
struct student {
	vector<int> questionSectionNum;
};
int P1058() {
	int N, M;
	cin >> N >> M;
	vector<question> allQuestions(M);
	vector<errorQuestion> allErrorquestion(M);
	int inputGrade, inputTotalNum, inputRightNum;
	char opt;
	for (int i = 0; i < M; i++) {
		vector<char> options;
		cin >> inputGrade >> inputTotalNum >> inputRightNum;
		for (int j = 0; j < inputRightNum; j++) {
			cin >> opt;
			options.push_back(opt);
		}
		allQuestions[i] = question(i + 1, inputGrade, inputTotalNum, inputRightNum, options);
	}
	string line;
	vector<student> allStudent(N);
	//N位同学循环
	for (int i = 0; i < N; i++) {
		getline(cin, line);
		auto beg = line.begin();
		auto end = line.end();
		int questionIndex = 0;
		//int lineIndex = 0;
		int sectionIndex = 0;
		//int sectionNum;
		int getGrade = 0;
		//该位同学选择的M道题目循环，questionIndex是题目下标，lineIndex是输入行字符的下标
		while (questionIndex < M && beg != line.end()) {
			bool right = true;
			sectionIndex = 0;
			beg = find(beg, line.end(), '(');
			end = find(beg, line.end(), ')');
			if (*(beg + 1) >= '1' &&*(beg + 1) <= '5') {
				//sectionNum = *(beg + 1) - '0';
				for (auto iter = beg + 1; iter != end; ++iter) {
					if (*iter >= 'a' &&*iter <= 'z') {
						if (*iter != allQuestions[questionIndex].options[sectionIndex])
							right = false;
						sectionIndex++;
					}
				}
			}
			else
				right = false;

			if (right)
				getGrade += allQuestions[questionIndex].fullGrade;
			questionIndex++;
			beg = end + 1;
		}
		cout << getGrade << endl;
	}

	return 0;
}