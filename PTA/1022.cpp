#include<iostream>
#include<string>
#include<vector>
using namespace std;
void P1022func(long num,const int &D) {
	vector<int> trans;
	do {
		trans.push_back(num%D);
		num /= D;
	} while (num != 0);
	for (auto iter = trans.crbegin(); iter != trans.crend(); iter++) {
		cout << *iter;
	}
}
int P1022() {
	long A, B;
	cin >> A >> B;
	int D;
	cin >> D;
	P1022func(A + B, D);

	return 0;
}