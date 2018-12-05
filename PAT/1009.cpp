#include<iostream>
#include<vector>
#include<string>
using namespace std;
void P1009() {
	string s;
	vector<string> vec;
	while (cin >> s)
		vec.push_back(s);
	string res;
	for (auto riter = vec.crbegin(); riter != vec.crend(); ++riter) {
		res += *riter + " ";
	}
	res.pop_back();
	cout << res;
}