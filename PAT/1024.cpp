#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct number {
	number(const string &s) {
		this->sign = *s.cbegin();

		this->integ = *(s.cbegin() + 1);

		auto iter_point_end = find(s.begin(), s.end(), '.');
		iter_point_end++;
		auto iter_expon = find(s.begin(), s.end(), 'E');
		this->points.resize(iter_expon - iter_point_end);
		copy(iter_point_end, iter_expon, this->points.begin());

		this->expon_sign = *(iter_expon + 1);

		this->expon.resize(s.end() -( iter_expon + 2));
		copy(iter_expon + 2, s.end(), this->expon.begin());
	}
	char sign;
	char integ;
	string points;
	char expon_sign;
	string expon;
};
int str2int(const string &s) {
	int res = 0;
	for (auto i = 0; i < s.size(); i++) {
		res = res * 10 + s[i] - '0';
	}
	return res;
}
void print(const number &num) {
	if (num.sign == '-')
		cout << '-';
	int expon = str2int(num.expon);
	if (num.expon_sign == '-') {
		cout << "0.";
		for (int i = 0; i < expon -1; i++) {
			cout << '0';
		}
		cout << num.integ << num.points;
	}
	else {
		cout << num.integ;
		if (expon == 0)
			cout << '.' << num.points;
		else if (expon > num.points.size()) {
			cout<< num.points;
			for (int i = num.points.size(); i < expon; i++)
				cout << '0';
		}
		else if (expon < num.points.size()) {
			for (int i = 0; i < expon; i++)
				cout << num.points[i];
			cout << '.';
			for (int i = expon; i < num.points.size(); i++)
				cout << num.points[i];
		}
		else if (expon == num.points.size()) {
			for (int i = 0; i < expon; i++)
				cout << num.points[i];
		}
	}

}
int P1024() {
	string s;
	cin >> s;

	number currNum(s);
	print(currNum);
	return 0;
}