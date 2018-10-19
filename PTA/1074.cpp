#include<iostream>
#include<stack>
using namespace std;

//用栈的思想去实现顺序逆序
int P1074() {
	stack<int> STANDARD, num1, num2, res;
	int temp;
	int carryBit = 0;
	while ((temp = cin.get()) != '\n') {
		if (temp == '0')	temp = 10;
		else temp -= '0';
		STANDARD.push(temp);
	}
	while ((temp = cin.get()) != '\n')
		num1.push(temp - '0');
	while ((temp = cin.get()) != '\n')
		num2.push(temp - '0');
	while (num1.size() != 0 && num2.size() != 0) {
		temp = num1.top() + num2.top() + carryBit;
		res.push(temp%STANDARD.top());
		carryBit = temp / STANDARD.top();
		num1.pop();
		num2.pop();
		STANDARD.pop();
	}
	while (num1.size() != 0) {
		temp = num1.top() + carryBit;
		res.push(temp%STANDARD.top());
		carryBit = temp / STANDARD.top();
		num1.pop();
		STANDARD.pop();
	}
	while (num2.size() != 0) {
		temp = num2.top() + carryBit;
		res.push(temp%STANDARD.top());
		carryBit = temp / STANDARD.top();
		num2.pop();
		STANDARD.pop();
	}
	res.push(carryBit);
	while (res.size() > 1 && res.top() == 0)
		res.pop();
	while (!res.empty())
	{
		cout << res.top();
		res.pop();
	}

	return 0;
}