#include<iostream>
using namespace std;

int P1056() {
	int N;
	cin >> N;
	int sum = 0;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		sum += num * (N - 1) * 11;
	}
	cout << sum;
	return 0;
}