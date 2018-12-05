#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1061() {
	int N, M;
	cin >> N >> M;
	vector<int> sectionQuestion(M);
	vector<int> sectionQuestionRight(M);
	for (int i = 0; i < M; i++)
		cin >> sectionQuestion[i];
	for (int i = 0; i < M; i++)
		cin >> sectionQuestionRight[i];
	int section;
	vector<int> students(N,0);
	for (int j = 0; j < N; j++) {	//ÐÐÊý
		for (int i = 0; i < M; i++) {
			cin >> section;
			if (section == sectionQuestionRight[i])
				students[j] += sectionQuestion[i];
		}
	}
	for (int j = 0; j < N; j++)
		cout << students[j] << endl;

	return 0;
}