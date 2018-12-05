#include<iostream>
#include<string>
#include<vector>
using namespace std;
int P1048() {
	string A, B;
	cin >> A >> B;
	int maxN = (A.size() > B.size()) ? A.size() : B.size();
	vector<int> Astr(maxN, 0), Bstr(maxN, 0);
	vector<char> resStr(maxN, '0');
	int Aindex = 0, Bindex = 0;
	int res = 0;
	for (int i = 0; i < maxN; i++) {
		Aindex = A.size() - 1 - i;
		Bindex = B.size() - 1 - i;
		if (Aindex >= 0)
			Astr[i] = A[Aindex] - '0';
		if (Bindex >= 0)
			Bstr[i] = B[Bindex] - '0';
		if (i % 2 == 0) {
			res = (Astr[i] + Bstr[i]) % 13;
			if (res >= 0 && res <= 9)
				resStr[i] = res + '0';
			else if (res == 10)
				resStr[i] = 'J';
			else if (res == 11)
				resStr[i] = 'Q';
			else if (res == 12)
				resStr[i] = 'K';
		}
		else {
			res = Bstr[i] - Astr[i];
			if (res < 0)
				res += 10;
			resStr[i] = res + '0';
		}
	}
	bool zeroFlag = true;
	for (int i = resStr.size() - 1; i >= 0 ; i--){
		if (resStr[i] == '0' && zeroFlag)
			continue;
		else {
			cout << resStr[i];
			zeroFlag = false;
		}
	}
	return 0;
}