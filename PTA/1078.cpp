#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print(const char &thisChar, char &lastChar, int &tempCount, string &res) {
	if (lastChar != thisChar) {
		if (tempCount == 1)
			res += lastChar;
		else {
			res += to_string(tempCount);
			res += lastChar;
			tempCount = 1;
		}
		lastChar = thisChar;
	}
	else
		tempCount++;
}

int P1078() {
	char c;
	cin >> c;
	getchar();
	string s, res;
	getline(cin, s);
	char lastChar;
	if (c == 'C') {
		lastChar = s[0];
		int tempCount = 1;
		int i = 1;
		for (; i < s.size(); i++) {
			print(s[i], lastChar, tempCount, res);
		}
		print('1', lastChar, tempCount, res);
	}
	else if (c == 'D') {
		int sum = 0;
		bool isNum = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				sum = sum * 10 + s[i] - '0';
				isNum = true;
			}
			else{
				if (isNum)
					for (int k = 0; k < sum; k++)
						res += s[i];
				else
					res += s[i];
				isNum = false;
				sum = 0;
			}
		}
	}
	cout << res;
	return 0;
}