#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int P1045() {
	int N;
	cin >> N;
	vector<int> vec(N), boolVec(N, true);
	vector<int> leftVec;
	vector<int> rightVec;
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	int leftMax = vec[0];
	for (int i = 0; i < N; i++) {
		if (leftMax <= vec[i])
			leftMax = vec[i];
		else
			boolVec[i] = false;
	}
	int rightMin = vec[N - 1];
	for (int i = N - 1; i >= 0; i--) {
		if (rightMin >= vec[i])
			rightMin = vec[i];
		else
			boolVec[i] = false;
	}
	vector<int> res;
	for (int i = 0; i < boolVec.size(); i++)
		if (boolVec[i])
			res.push_back(vec[i]);
	cout << res.size() << endl;
	sort(res.begin(), res.end());
	if (res.size() != 0) {
		int i = 0;
		for (; i < res.size() - 1; i++)
			cout << res[i] << " ";
		cout << res[res.size() - 1];
	}
	cout << endl;
	return 0;
}