#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1066() {
	int N; char c;
	cin >> N >> c;
	int cols = N;
	int rows = (cols / 2 * 2 == cols) ? cols / 2 : cols / 2 + 1;
	//µÚÒ»ÐÐ
	for (int i = 0; i < cols; i++)
			cout << c;
	cout << endl;
	for (int j = 1; j < rows - 1; j++) {
			cout << c;
			for (int i = 1; i < cols - 1; i++)
				cout << ' ';
			cout << c;
		cout << endl;
	}
	for (int i = 0; i < cols; i++)
		cout << c;
	cout << endl;

	return 0;
}