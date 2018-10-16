#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int P1050() {
	int N, m, n;
	cin >> N;
	for (int i = sqrt(N); i >= 0; i--)
		if (N%i == 0) {
			n = i;
			m = N / i;
			break;
		}
	vector<int> vec(N);
	vector<vector<int>> arr(m, vector<int>(n));
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end(), [](const int &a, const int &b) {return a > b; });
	int index = 0;
	int topCol, rightRow, bottomCol, leftRow;
	for (int cycle = 0; cycle <= n / 2 && index < N; cycle++) {
		for (topCol = cycle; topCol < n - cycle && index < N; topCol++)
			arr[cycle][topCol] = vec[index++];
		for (rightRow = cycle + 1; rightRow < m - cycle && index < N; rightRow++)
			arr[rightRow][n - 1 - cycle] = vec[index++];
		for (bottomCol = n - 2 - cycle; bottomCol >= cycle && index < N; bottomCol--)
			arr[m - 1 - cycle][bottomCol] = vec[index++];
		for (leftRow = m - 2 - cycle; leftRow >= cycle + 1 && index < N; leftRow--)
			arr[leftRow][cycle] = vec[index++];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++)
			cout << arr[i][j] << ' ';
		cout << arr[i][n - 1] << endl;
	}
	return 0;
}