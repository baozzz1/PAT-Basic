#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<int, vector<pair<int, char>>> maxErrorP1058;

struct question {
	int questionNo;
	int fullGrade, sectionNum, rightNum;
	vector<char> rightSections;
	int errorCount = 0;
};

bool readOneSectionP1058(string::iterator &beg, string::iterator &end, question &question) {
	vector<char> rightSections(question.rightSections);
	bool allRight = true;
	int sectionNum = *(++beg) - '0';
	++beg;
	for (; beg != end; beg++) {
		if (*beg == ' ')
			continue;
		// ѡ���˴���𰸵����
		auto iter = find(rightSections.begin(), rightSections.end(), *beg);
		if (iter == rightSections.end()) {
			//question.errorCount++;
			allRight = false;
			break;
		}
		else
			rightSections.erase(iter);
	}

	//��ȷ��δ��ѡ��ʱ:
	if (rightSections.size() != 0) {
		allRight = false;
	}

	//��ȷ��ȫ��ѡ�꣬��ûѡ�����Ĵ�
	if (allRight)
		return true;
	//��ȷ��ȫ��ѡ�꣬�����д���Ĵ�
	else {
		question.errorCount++;
		return false;
	}
}

double getOneStudentGradeP1058(string &line, vector<question> &allQuestions) {
	int sum = 0;
	int questionIndex = 0;
	auto beg = line.begin();
	auto end = line.begin();
	for (; questionIndex < allQuestions.size(); questionIndex++) {
		beg = find(end, line.end(), '(');
		end = find(beg, line.end(), ')');
		if (readOneSectionP1058(beg, end, allQuestions[questionIndex]))
			sum += allQuestions[questionIndex].fullGrade;
	}
	return sum;
}

// ��Ӧ��P1073
int P1058() {
	int N, M;
	cin >> N >> M;
	vector<question> allQuestions(M);

	//������Ŀ�ʹ�
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
	getchar();	//����

	//��������ͬѧ�Ĵ�
	string line;
	vector<double> grade(N, 0);
	//Nλͬѧѭ��
	for (int i = 0; i < N; i++) {
		std::getline(cin, line);
		grade[i] = getOneStudentGradeP1058(line, allQuestions);
	}

	//���
	for (int i = 0; i < N; i++)
		cout << grade[i] << endl;
	int errorCount = 0;
	for (int i = 0; i < M; i++)
		if (errorCount < allQuestions[i].errorCount)
			errorCount = allQuestions[i].errorCount;
	if (errorCount != 0) {
		cout << errorCount;
		for (int i = 0; i < M; i++) {
			if (allQuestions[i].errorCount == errorCount)
				cout << " " << i + 1;
		}
	}
	else
		cout << "Too simple";
	return 0;
}