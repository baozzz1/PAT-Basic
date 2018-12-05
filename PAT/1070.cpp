#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int P1070() {
	int N;
	cin >> N;
	int length;
	//int totalLength = 0;
	vector<int> totalRope(N);
	for (int i = 0; i < N; i++)
		cin >> totalRope[i];
	sort(totalRope.begin(), totalRope.end());
	int lastLength = totalRope[0];
	for (int i = 1; i < N; i++) {
		length = totalRope[i];
		lastLength = (lastLength + length) / 2.0;
	}
	cout << (int)lastLength;
	return 0;
}