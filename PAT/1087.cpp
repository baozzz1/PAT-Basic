#include<iostream>
#include<set>
using namespace std;

int variableCount(const int &num) {
	set<int> res;
	for (int i = 1; i <= num; i++)
		res.insert(i / 2 + i / 3 + i / 5);
	return res.size();
}

int P1087() {
	int N;
	cin >> N;
	cout << variableCount(N);
	return 0;
}