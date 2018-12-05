#include<iostream>
using namespace std;

int P1049() {
	int N;
	cin >> N;
	double sum = 0.0;
	double num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		sum += (double)num * (double)(N - i)*(double)(i + 1);	//关键是精度问题
	}
	printf("%.2f", sum);
	return 0;
}