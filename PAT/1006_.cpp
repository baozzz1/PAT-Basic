#include<iostream>
using namespace std;

int P1006_() {
	int n;
	cin >> n;
	int carry = 0;
	if (n >= 100) {
		carry = n / 100;
		for (int i = 0; i < carry; i++)
			cout << 'B';
		n -= carry * 100;
	}
	if (n >= 10) {
		carry = n / 10;
		for (int i = 0; i < carry; i++)
			cout << 'S';
		n -= carry * 10;
	}
	for (int i = 1; i <= n; i++)
		cout << i;
	return 0;
}