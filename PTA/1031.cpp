#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<char> Z2M = { '1','0', 'X', '9', '8', '7', '6', '5','4', '3', '2' };
vector<int> facter = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
int P1031() {
	int N;
	cin >> N;
	vector<char> number(18);
	vector<vector<char>> res;
	while (N--) {
		int sum = 0;
		for (int i = 0; i < 17; i++) {
			cin >> number[i];
			sum += (number[i] - '0') * facter[i];
		}
		cin >> number[17];
		if (Z2M[sum % 11] != number[17]) {
			res.push_back(number);
		}
	}
	if (res.size() == 0)
		cout << "All passed";
	else
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j];
			cout << endl;
		}

	return 0;
}
