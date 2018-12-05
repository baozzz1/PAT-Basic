#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

set<int> coveredNum = set<int>();

void func(int n) {
	if (n == 1)
		return;
	if (n % 2 == 0) {
		n /= 2;
		if (coveredNum.find(n) != coveredNum.end())
			return;
		coveredNum.insert(n);
		func(n);
	}
	else {
		n = (3 * n + 1) / 2;
		if (coveredNum.find(n) != coveredNum.end())
			return;
		coveredNum.insert(n);
		func(n);
	}
}
int P1005_() {
	int K,n;
	cin >> K;
	vector<int> nums = vector<int>();
	while (K--) {
		cin >> n;
		nums.push_back(n);
		func(n);
	}
	vector<int> res;
	for (auto num : nums) {
		if (coveredNum.find(num) == coveredNum.end())
			res.push_back(num);
	}
	sort(res.begin(), res.end(), [](int a, int b) {return a > b; });
	if (res.empty())
		return 0;
	cout << res[0];
	for (int i = 1; i < res.size(); i++)
		cout << " " << res[i];
	return 0;
}