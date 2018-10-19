#include<iostream>
#include<vector>
using namespace std;

// 看清题意！！！题目说输出“重复的差值”，那么只有一次的差值就不要输出的
int P1083() {
	int N;
	cin >> N;
	// 下标是差值数，差值最大为N-1。值为重复次数
	vector<int> res(N,0);
	int diff, unordered;
	for (int i = 0; i < N; i++) {
		cin >> unordered;
		diff = (unordered >= (i + 1)) ? (unordered - (i + 1)) : ((i + 1) - unordered);
		res[diff]++;
	}
	for (int i = res.size() - 1; i >= 0; i--)
		if (res[i] != 0 &&res[i] !=1)
			cout << i << " " << res[i] << endl;
	return 0;
}