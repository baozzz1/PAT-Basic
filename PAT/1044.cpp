#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
using namespace std;

vector<string> thirteenPlace = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
vector<string> onePlace = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string Earth2Mars(const string &s) {
	string res;
	int num = 0;
	for (int i = 0; i < s.size(); i++)
		num = num * 10 + s[i] - '0';
	if (num / 13) {
		res = thirteenPlace[num / 13 - 1];
		if (num % 13 != 0)
			res += " " + onePlace[num % 13];
	}
	else {
		res = onePlace[num];
	}
	return res;

}
string Mars2Earth(const string &s) {
	int num = 0;
	string res;
	if (s.size() <= 4) {
		for (int i = 0; i < onePlace.size(); i++)
			if (onePlace[i] == s)
				res = to_string(i);
		if (res.size() == 0)
			for (int i = 0; i < thirteenPlace.size(); i++)
				if (thirteenPlace[i] == s)
					res = to_string((i + 1) * 13);
	}
	else {
		for (int i = 0; i < thirteenPlace.size(); i++)
			if (thirteenPlace[i] == s.substr(0, 3))
				num = (i + 1) * 13;
		if (onePlace[0] == s.substr(4, 4))
			num += 0;
		else
			for (int i = 1; i < onePlace.size(); i++)
				if (onePlace[i] == s.substr(4, 3))
					num += i;
		res = to_string(num);
	}
	return res;
}

int P1044() {
	int N;
	cin >> N;
	getchar();
	int n = N;
	string s;
	vector<string> trans;
	while (n--) {
		getline(cin, s);
		if (s[0]>='0' && s[0]<='9')
			trans.push_back(Earth2Mars(s));
		else
			trans.push_back(Mars2Earth(s));
	}
	for (int i = 0; i < trans.size(); i++)
		cout << trans[i] << endl;
	return 0;
}