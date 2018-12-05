#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1040() {
	long res = 0;
	char c;
	long countP = 0;
	//当前这个A前有多少个P
	long nPBeforeA = 0;
	while (cin >> c) {
		if (c == 'P') {
			countP++;
		}
		else if (c == 'A') {
			nPBeforeA += countP;
		}
		else if (c == 'T') {
			res += nPBeforeA;
			if (res % 1000000007)
				res %= 1000000007;
		}
	}
	cout << res % 1000000007;

	return 0;
}