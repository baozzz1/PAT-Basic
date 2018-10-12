#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
void str2Int(int &int_temp, const string &string_temp)
{
	stringstream stream(string_temp);
	stream >> int_temp;
}
int find_Max_common_divisor(const int &num1, const int &num2) {
	int t = (num1 > num2) ? num2 : num1;
	while (!(num1%t == 0 && num2 % t == 0))
		t--;
	return t;
}

// 待会修改：分别返回符号、整数、分子、分母，再根据情况判断；
// 用类的思想
void add(const int &numerator1, const int &denominator1, const int &numerator2, const int &denominator2) {
	bool isNeg = false;
	int numerator_res, denominator_res, interg_res;
	int Max_common_divisor = find_Max_common_divisor(denominator1, denominator2);
	int numerator_total = numerator1 * denominator2 / Max_common_divisor + numerator2 * denominator1 / Max_common_divisor;
	int denominator_total = denominator1 * denominator2 / Max_common_divisor;
	if (numerator_total < 0) {
		isNeg = true;
		numerator_total = abs(numerator_total);
		cout << "(-";
	}
	if (numerator_total == 0)
		cout << "0";
	else if (numerator_total >= denominator_total) {
		interg_res = numerator_total / denominator_total;
		cout << interg_res;
		numerator_total -= denominator_total * interg_res;
	}
	if (numerator_total != 0) {
		if (interg_res != 0)
			cout << " ";
		cout << numerator_total << '/' << denominator_total;
		int Max_common_divisor_res = find_Max_common_divisor(numerator_total, denominator_total);
		if (Max_common_divisor_res != 1) {
			numerator_total /= Max_common_divisor_res;
			denominator_total /= Max_common_divisor_res;
		}
		cout << numerator_total << '/' << denominator_total;
	}
	if (isNeg)
		cout << ")";
	cout << endl;
}

int P1034() {
	vector<string> num(2);
	cin >> num[0] >> num[1];
	vector<string> numerator(2), denominator(2);
	vector<int> numerator_int(2), denominator_int(2);
	for (int i = 0; i < 2; i++) {
		auto iter = num[i].begin();
		for (; iter != num[i].end() && *iter != '/'; ++iter)
			numerator[i].push_back(*iter);
		++iter;
		for (; iter != num[i].end(); ++iter)
			denominator[i].push_back(*iter);

		str2Int(numerator_int[i], numerator[i]);
		str2Int(denominator_int[i], denominator[i]);
	}
	add(numerator_int[0], denominator_int[0], numerator_int[1], denominator_int[1]);



	return 0;
}