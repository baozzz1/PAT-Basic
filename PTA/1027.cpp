#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1027() {
	int N;
	char C;
	cin >> N >> C;

	int odd_count = 0;
	int total_num = 0;
	int odd_num = 0;
	while (N - total_num >= (odd_num + 2) * 2 || odd_count == 0) {
		odd_num = odd_count * 2 + 1;	//1,3,5,7...
		total_num += (odd_num == 1 ? 1 : 2)*odd_num;
		odd_count++;
	}
	for (int i = odd_count; i > 0; i--) {
		for (int j = 0; j < odd_count - i; j++)
			cout << ' ';
		for (int j = 0; j < i * 2 - 1; j++)
			cout << C;
		cout << endl;
	}
	for (int i = 2; i <= odd_count; i++) {
		for (int j = 0; j < odd_count - i; j++)
			cout << ' ';
		for (int j = 0; j < i * 2 - 1; j++)
			cout << C;
		cout << endl;
	}
	cout << N - total_num;
	return 0;
}
