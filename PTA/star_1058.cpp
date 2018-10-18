#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//不知道错在哪了
struct question {
	question() {}
	question(int qNo, int g, int t, int r, vector<char> opt) :questionNo(qNo+'0'), fullGrade(g), totalNum(t), rightNum(r), options(opt) {}
	
	char questionNo;
	int fullGrade, totalNum, rightNum;
	vector<char> options;
	int errorCount = 0;

};

bool readOneSection(string::iterator &beg, string::iterator &end, vector<question> &allQuestions, const int &questionIndex) {
	int sectionNum = *(++beg) - '0';
	if (sectionNum != allQuestions[questionIndex].rightNum)
		return false;
	int rightIndex = 0;
	for (auto iter = beg + 1; iter != end; iter++) {
		if (*iter >= 'a'&&*iter <= 'e') {
			if (*iter != allQuestions[questionIndex].options[rightIndex++])
				return false;
		}
	}
	return true;
}

int getOneStudentGrade(string &line, vector<question> &allQuestions) {
	int sum = 0;
	int questionIndex = 0;
	auto beg = line.begin();
	auto end = line.begin();
	for (; questionIndex < allQuestions.size(); questionIndex++) {
		beg = find(end, line.end(), '(');
		end = find(beg, line.end(), ')');
		if (readOneSection(beg, end, allQuestions, questionIndex))
			sum += allQuestions[questionIndex].fullGrade;
		else
			allQuestions[questionIndex].errorCount++;
	}
	return sum;
}

int P1058() {
	int N, M;
	cin >> N >> M;
	N = 3; M = 4;
	vector<question> allQuestions(M);
	int totalGrade = 0;

	//输入所有的问题并记录
	char opt;
	int inputGrade, inputTotalNum, inputRightNum;
	for (int i = 0; i < M; i++) {
		vector<char> options;
		cin >> inputGrade >> inputTotalNum >> inputRightNum;
		for (int j = 0; j < inputRightNum; j++) {
			cin >> opt;
			options.push_back(opt);
		}
		allQuestions[i] = question(i + 1, inputGrade, inputTotalNum, inputRightNum, options);
		totalGrade += inputGrade;
	}
	getchar();	//换行
	//输入所有同学的答案
	string line;
	//vector<student> allStudent(N);
	vector<int> grade(N,0);
	//N位同学循环
	for (int i = 0; i < N; i++) {
		std::getline(cin, line);
		grade[i] = getOneStudentGrade(line, allQuestions);
	}

	//输出
	bool soEasy = true;
	for (int i = 0; i < N; i++){
		cout << grade[i] << endl;
		if (grade[i] != totalGrade)
			soEasy = false;
	}
	if (soEasy)
		cout << "Too simple";
	else{
		int maxErrorCount = 0;
		map<int, string> errorCount;
		for (int i = 0; i < M; i++) {
			errorCount[allQuestions[i].errorCount] += ' ';
			errorCount[allQuestions[i].errorCount] += allQuestions[i].questionNo;
			if(allQuestions[i].errorCount> maxErrorCount)
				maxErrorCount = allQuestions[i].errorCount;
		}
		cout << maxErrorCount;
		for (auto iter = errorCount[maxErrorCount].begin(); iter != errorCount[maxErrorCount].end(); ++iter)
			cout << *iter;
		//cout << endl;
	}
	return 0;
}