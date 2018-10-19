#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindromic(const string &num) {
	for (int i = 0; i < num.size()/2; i++) {
		if (num[i] != num[num.size() - 1 - i])
			return false;
	}
	return true;
}

string reverse(const string &num) {
	string res;
	for (int i = num.size()-1; i >=0; i--)
		res += num[i];
	return  res;
}

string addPalindromic(const string &num1, const string &num2) {
	//两个互为逆转数的数相加，从最高位开始加也是一样的
	string res;
	int carryBit = 0;
	int temp;
	for (int i = 0; i < num1.size(); i++) {
		temp = (num1[i] - '0') + (num2[i] - '0') + carryBit;
		if (temp / 10) {
			carryBit = 1;
			temp %= 10;
		}
		else 
			carryBit = 0;
		res.push_back(temp + '0');
	}
	if (carryBit)
		res.push_back('1');
	return reverse(res);
}

int P1079() {
	string num1;
	cin >> num1;
	if (isPalindromic(num1)) {
		cout << num1 << " is a palindromic number.";
		return 0;
	}
	string num2;
	string sum;
	int i = 0;
	for (; i < 10; i++) {
		num2 = reverse(num1);
		sum = addPalindromic(num1,num2);
		cout << num1 << " + " << num2 << " = " << sum << endl;
		if (isPalindromic(sum))
			break;
		num1 = sum;
	}
	if (i == 10)
		cout << "Not found in 10 iterations.";
	else
		cout << sum << " is a palindromic number.";

	return 0;
}