#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;


struct studentCheck {
	string name;
	vector<int> banned;
};
//Easy Question
int P1072() {
	int N, M;
	cin >> N >> M;
	vector<int> bannedThings(M);
	vector<studentCheck> students(N);
	for (int i = 0; i < M; i++)
		cin >> bannedThings[i];
	string name;
	int K;
	int things;
	for (int i = 0; i < N; i++) {
		cin >> name >> K;
		students[i].name = name;
		for (int j = 0; j < K; j++) {
			cin >> things;
			if (find(bannedThings.begin(), bannedThings.end(), things) != bannedThings.end())
				students[i].banned.push_back(things);
		}
	}
	int findPeopleCount = 0, findThingsCount = 0;
	for (int i = 0; i < students.size(); i++) {
		auto num = students[i].banned.size();
		if (num != 0) {
			cout << students[i].name << ": ";
			for (int j = 0; j < num - 1; j++)
				cout << setw(4) << setfill('0') << students[i].banned[j] << " ";
			cout << setw(4) << setfill('0') << students[i].banned[num - 1] << endl;
			findPeopleCount++;
			findThingsCount += num;
		}
	}
	cout << findPeopleCount << " " << findThingsCount;
	return 0;
}