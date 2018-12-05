#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int P1063() {
	int N;
	cin >> N;
	int left, right;
	double maxM = 0;
	double m;
	for (int i = 0; i < N; i++) {
		cin >> left >> right;
		m = sqrt(left*left + right * right);
		if (m > maxM)
			maxM = m;
	}
	printf("%.2f", maxM);
	return 0;
}