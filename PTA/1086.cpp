#include<iostream>
#include<vector>
using namespace std;

//翻转的数，注意高位的0不要输出
int P1086() {
	int a,b;
	cin >> a>>b;
	int res = a * b;
	vector<int> result;
	if (res == 0) {
		cout << 0;
		return 0;
	}
	while (res) {
		result.push_back(res % 10);
		res /= 10;
	}
	bool firstNotZero = false;
	for (int i = 0; i < result.size(); i++) {
		if (!firstNotZero &&result[i] == 0)
			continue;
		else
			firstNotZero = true;
		cout << result[i];
	}
	return 0;
}