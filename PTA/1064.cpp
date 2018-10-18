#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int sumOfEveryNum(int num) {
	int sum = 0;
	while (num) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int P1064() {
	int N;
	cin >> N;
	int num;
	set<int> friendNo;
	vector<int> sorted;
	for (int i = 0; i < N; i++) {
		cin >> num;
		friendNo.insert(sumOfEveryNum(num));
	}
	cout << friendNo.size();
	if (friendNo.size() != 0) {
		cout << endl;
		for (auto iter = friendNo.begin(); iter != friendNo.end(); ++iter)
			sorted.push_back(*iter);
		for (int i = 0; i < sorted.size() - 1; i++)
			cout << sorted[i] << " ";
		cout << sorted[sorted.size() - 1];
	}
	return 0;
}