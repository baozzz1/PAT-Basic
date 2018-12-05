#include<iostream>
using namespace std;

void func(const int &n,int &count) {
	if (n == 1)
		return;
	if (n % 2 == 0)
		func(n / 2, ++count);
	else
		func((3 * n + 1) / 2, ++count);
}
int P1001_() {
	int n;
	cin >> n;
	int count = 0;
	func(n,count);
	cout << count;
	return 0;
}