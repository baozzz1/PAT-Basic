#include<iostream>
#include<string>
using namespace std;
int P1017() {
	string A; int B;
	cin >> A >> B;
	int remainNum = 0;
	if (A.size() == 1) {
		cout << (A[0] - '0') / B;
		remainNum = (A[0] - '0') % B;
	}
	else {
		int currNum = A[0] - '0';
		remainNum = currNum % B;
		if (currNum / B)
			cout << currNum / B;
		for (int i = 1; i < A.size(); i++) {
			currNum = A[i] - '0' + remainNum * 10;
			cout << currNum / B;
			remainNum = currNum % B;
		}
	}
	cout << " " << remainNum;
	return 0;
}