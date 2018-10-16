#include<iostream>
using namespace std;

int P1053() {
	int N, D;
	double e;
	cin >> N >> e >> D;
	int K;
	double ek;
	int count;
	double mayEmptyCount = 0, isEmptyCount = 0;
	for (int n = 0; n < N; n++) {
		cin >> K;
		count = 0;
		for (int i = 0; i < K; i++) {
			cin >> ek;
			if (ek < e)
				count++;
		}
		if (count * 2 > K) {
			mayEmptyCount++;
			if (K > D)
				isEmptyCount++;
		}
	}
	double isEmpty = (double)isEmptyCount / (double)N;
	double mayEmpty = (double)mayEmptyCount / (double)N - isEmpty;
	printf("%.1f%% %.1f%%", mayEmpty * 100, isEmpty * 100);

	return 0;
}