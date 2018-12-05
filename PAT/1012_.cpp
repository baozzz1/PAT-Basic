#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int N;
	int n;
	cin >> N;
	int carry = 0;
	int flag1 = 1;
	vector<bool> flag(5,false);
	vector<int> a(5, 0);
	int totalNumber3 = 0;
	while (N--) {
		cin >> n;
		carry = n % 5;
		switch (carry) {
		case 0:
			if (n % 2 == 0) {
				a[0] += n;
				flag[0] = true;
			}
			break;
		case 1:
			a[1] += flag1 * n;
			flag1 = -flag1;
			flag[1] = true;
			break;
		case 2:
			a[2]++;
			flag[2] = true;
			break;
		case 3:
			a[3] += n;
			totalNumber3++;
			flag[3] = true;
			break;
		case 4:
			if (n > a[4]) {
				a[4] = n;
				flag[4] = true;
			}
			break;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (flag[i]) {
			if (i != 3)
				cout << a[i] << " ";
			else
				printf("%.1f ", a[3] / (double)totalNumber3);
		}
		else
			cout << "N ";
	}
	if (flag[4])
		cout << a[4];
	else
		cout<<"N";

	return 0;
}