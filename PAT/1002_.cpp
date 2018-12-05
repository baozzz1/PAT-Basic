#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> num2text = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
int P1002_() {
	string n;
	cin >> n;
	int sum = 0;
	for (char c : n)
		sum += c - '0';
	if (sum == 0) {
		cout << num2text[0];
		return 0;
	}
	vector<int> res = vector<int>();
	while (sum != 0) {
		res.push_back(sum % 10);
		sum /= 10;
	}
	for (auto riter = res.rbegin(); riter != res.rend(); riter++) {
		cout << num2text[*riter];
		if (riter != res.rend() - 1)
			cout << " ";
	}
	return 0;
}