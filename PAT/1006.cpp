#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printB(string &s, int num) {
	for (int i = 1; i <= num; i++)
		s += 'B';
}
void printS(string &s, int num) {
	for (int i = 1; i <= num; i++)
		s += 'S';
}
void printN(string &s, int num) {
	for (int i = 1; i <= num; i++)
		s += i + '0';
}
void P1006() {
	unsigned num;
	if (cin >> num && num > 0 && num < 1000) {
		vector<int> vec;
		while (num) {
			vec.push_back(num % 10);
			num /= 10;
		}
		string res;
		for (auto i = vec.size(); i > 0; i--) {
			auto str = vec[i - 1];
			switch (i) {
			case 3:
				printB(res, str);
				break;
			case 2:
				printS(res, str);
				break;
			case 1:
				printN(res, str);
				break;
			}
		}
		cout << res;
	}
}