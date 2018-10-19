#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int P1077() {
	int N, M;
	cin >> N >> M;
	int teacher, otherGroup, sum;
	double avg;
	vector<int> groupGrades;
	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		cin >> teacher;
		sum = 0;
		groupGrades.clear();
		for (int j = 1; j < N; j++) {
			cin >> otherGroup;
			if (otherGroup > M || otherGroup < 0)
				continue;
			groupGrades.push_back(otherGroup);
		}
		sort(groupGrades.begin(), groupGrades.end());
		for (int j = 1; j < groupGrades.size() - 1; j++)
			sum += groupGrades[j];
		avg = ((double)sum / (double)(groupGrades.size() - 2) + teacher) / 2.0;
		res[i] = ((int)(avg * 10) % 10 < 5) ? avg : (avg + 1);

	}
	for (int i = 0; i < N; i++)
		cout << res[i] << endl;
	return 0;
}