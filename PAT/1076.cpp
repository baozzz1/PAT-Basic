#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Easy
int P1076() {
	int N;
	cin >> N;
	char section, TorF;
	string res;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> section;
			getchar();
			cin >> TorF;
			if (TorF == 'T') {
				res += section + '1' - 'A';
			}
		}
	}
	cout << res;
	return 0;
}