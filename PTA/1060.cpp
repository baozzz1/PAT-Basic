#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//关键是看清题意
int P1060() {
	int N;
	cin >> N;
	unsigned distance;
	vector<unsigned> length(N);
	for (int i = 0; i < N; i++) {
		cin >> distance;
		length[i] = distance;
	}
	unsigned totalMaxDay = 0;
	unsigned maxE = 0;
	sort(length.rbegin(), length.rend());
	for (int i = 0; i < N; i++) {
		if (length[i] <= i + 1)
			break;
		maxE++;
	}
	cout << maxE;

	return 0;
}