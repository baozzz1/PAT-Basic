#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int P1033() {
	string broken_key, input;
	getline(cin,broken_key);
	getline(cin, input);
	vector<bool> trans(128, false);
	string res;
	for (auto iter = broken_key.cbegin(); iter != broken_key.cend(); ++iter)
		trans[*iter] = true;
	for (auto iter = input.cbegin(); iter != input.cend(); ++iter) {
		if (*iter >= 'A' && *iter <= 'Z') {
			if (!trans[*iter] && !trans['+'])
				cout << *iter;
		}
		else if (*iter >= 'a' && *iter <= 'z') {
			if (!trans[*iter - 32])
				cout << *iter;
		}
		else if (((*iter >= '0' && *iter <= '9')) || *iter == ',' || *iter == '.' || *iter == '-' || *iter == '_' || *iter == '+') {
			if (!trans[*iter])
				cout << *iter;
		}
		else
			cout << *iter;
	}
	cout << endl;

	return 0;
}