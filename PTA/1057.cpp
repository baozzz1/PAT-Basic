#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	int numSum = 0;
	for (auto iter = s.begin(); iter != s.end(); ++iter) {
		if (*iter >= 'a' && *iter <= 'z')
			numSum += *iter - 'a' + 1;
		else if(*iter >= 'A' && *iter <= 'Z')
			numSum += *iter - 'A' + 1;
	}
	int oneTarget = numSum, zeroTarget = ~numSum;
	int oneSum = 0;
	while (oneTarget) {
		oneTarget &= oneTarget - 1;
		oneSum++;
	}
	int zeroSum = 0;
	while (zeroTarget) {
		zeroTarget &= zeroTarget - 1;
		zeroSum++;
	}
	cout << zeroSum << " " << oneSum;
	return 0;
}