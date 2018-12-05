#include<iostream>
#include<string>
using namespace std;

int P1057() {
	string s;
	getline(cin, s);			//关键：字符串中可能有空格
	int numSum = 0;
	for (auto iter = s.begin(); iter != s.end(); ++iter) {
		if (*iter >= 'a' && *iter <= 'z')
			numSum += *iter - 'a' + 1;
		else if(*iter >= 'A' && *iter <= 'Z')
			numSum += *iter - 'A' + 1;
	}
	unsigned oneSum = 0;
	unsigned zeroSum = 0;
	/*if (numSum == 0)
		zeroSum = 1;*/
	while (numSum) {
		if (numSum & 1)
			oneSum++;
		else
			zeroSum++;
		numSum >>= 1;
	}
	cout << zeroSum << " " << oneSum;
	return 0;
}