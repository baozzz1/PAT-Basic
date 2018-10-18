#include<iostream>
#include<string>
#include<vector>
using namespace std;

int Max_common_divisor(const int &num1, const int &num2) {
	int t = (num1 > num2) ? num2 : num1;
	while (!(num1%t == 0 && num2 % t == 0))
		t--;
	return t;
}
int P1062() {
	int K;
	int N1, N2, M1, M2;
	scanf_s("%d/%d", &N1, &M1);
	scanf_s("%d/%d", &N2, &M2);
	if (N1*M2 > N2*M1) {		//关键：数1不一定比数2小
		int temp = N1;
		int temp2 = M1;
		N1 = N2; M1 = M2;
		N2 = temp; M2 = temp2;
	}
	cin >> K;
	double n1 = double(K) *double(N1) / double(M1);
	double n2 = double(K) *double(N2) / double(M2);
	int i = n1 + 1;
	vector<int> res;
	for (; i < n2; i++) {
		if (Max_common_divisor(i, K) == 1)
			res.push_back(i);
	}
	if (res.size() == 1) {
		cout << res[0] << "/" << K;
		return 0;
	}
	i = 0;
	for (; i < res.size() - 1; i++)
		cout << res[i] << "/" << K << " ";
	cout << res[i] << "/" << K;

	return 0;
}