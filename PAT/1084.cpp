#include<iostream>
#include<string>
#include<vector>
using namespace std;

//注意题意：序列的第N项是对第n-1项的描述，因此循环次数是N-1
int P1084() {
	int  N;
	string n, res;
	cin >> n >> N;
	for (int i = 0; i < N - 1; i++) {
		res.clear();
		int tempCount = 1;
		char lastChar = n[0];
		for (int j = 1; j < n.size(); j++) {
			if (n[j] == lastChar) {
				tempCount++;
			}
			else {
				res += lastChar;
				res += to_string(tempCount);
				lastChar = n[j];
				tempCount = 1;
			}
		}
		res += lastChar;
		res += to_string(tempCount);
		n = res;
	}
	cout << n;
	return 0;
}