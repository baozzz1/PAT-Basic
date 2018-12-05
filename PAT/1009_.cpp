#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1009_() {
	vector<string> get;
	string s;
	while (cin >> s)
		get.push_back(s);
	if (get.empty())
		return 0;
	else if (get.size() == 1) {
		cout << get[0];
		return 0;
	}
	cout << get[get.size()-1];
	for (int i = get.size() - 2; i >= 0; i--)
		cout << " " << get[i];
	return 0;
}