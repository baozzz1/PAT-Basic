#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1043() {
	char c;
	vector<int> PATest(6);
	while (cin >> c) {
		if (c == 'P')
			PATest[0]++;
		else if (c == 'A')
			PATest[1]++;
		else if (c == 'T')
			PATest[2]++;
		else if (c == 'e')
			PATest[3]++;
		else if (c == 's')
			PATest[4]++;
		else if (c == 't')
			PATest[5]++;
	}
	while (PATest[0] || PATest[1] || PATest[2] || PATest[3] || PATest[4] || PATest[5]) {
		if (PATest[0] != 0) {
			cout << 'P';
			PATest[0]--;
		}
		if (PATest[1] != 0) {
			cout << 'A';
			PATest[1]--;
		}
		if (PATest[2] != 0) {
			cout << 'T';
			PATest[2]--;
		}
		if (PATest[3] != 0) {
			cout << 'e';
			PATest[3]--;
		}
		if (PATest[4] != 0) {
			cout << 's';
			PATest[4]--;
		}
		if (PATest[5] != 0) {
			cout << 't';
			PATest[5]--;
		}
	}

	return 0;
}