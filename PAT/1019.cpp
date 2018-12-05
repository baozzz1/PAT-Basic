#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
int sortNum(int num, const int &pos) {
	vector<int> vec;
	for (int i = 0; i < 4; i++) {
		vec.push_back(num % 10);
		num /= 10;
	}
	if (pos == 1)
		sort(vec.begin(), vec.end(), [](const int &it1, const int &it2) {return it1 > it2; });
	else if (pos == 2)
		sort(vec.begin(), vec.end(), [](const int &it1, const int &it2) {return it1 < it2; });
	int res = 0;
	for (int i = 0; i < 4; i++) {
		res = res * 10 + vec[i];
	}
	return res;
}
int P1019func(int num) {
	int firstNum = sortNum(num, 1);
	int secondNum = sortNum(num, 2);
	int res = firstNum - secondNum;
	cout << setw(4) << setfill('0') << firstNum << " - ";
	cout << setw(4) << setfill('0') << secondNum << " = ";
	cout << setw(4) << setfill('0') << res;
	if (res != 6174)
		cout << endl;
	return res;
}
bool isSame(int num) {
	vector<int> vec;
	for (int i = 0; i < 4; i++) {
		vec.push_back(num % 10);
		num /= 10;
	}
	if (vec[0] == vec[1] && vec[0] == vec[2] && vec[0] == vec[3])
		return true;
	else return false;
}
int P1019() {
	int num;
	cin >> num;
	do {
		num = P1019func(num);
	} while (num != 6174 && num != 0);
	return 0;
}