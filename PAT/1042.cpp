#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int P1042() {
	string in;
	getline(cin, in);
	map<char, int> strNum;
	int maxNum = 0;
	for (auto iter = in.begin(); iter != in.end(); ++iter) {
		if (*iter >= 'A' && *iter <= 'Z') {
			*iter = *iter - 'A' + 'a';
			strNum[*iter]++;
		}
		else if (*iter >= 'a' && *iter <= 'z')
			strNum[*iter]++;;
	}
	auto maxIter = strNum.begin();
	for (auto iter = strNum.begin(); iter != strNum.end(); ++iter) {
		if (iter->second > maxNum) {
			maxNum = iter->second;
			maxIter = iter;
		}
	}
	cout << maxIter->first << " " << maxNum;
	return 0;
}