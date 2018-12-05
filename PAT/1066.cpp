#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

int P1066() {
	int M, N, A, B, grayLevel;
	cin >> M >> N >> A >> B >> grayLevel;
	int sourceGray;
	vector<vector<int>> mat(M, vector<int>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sourceGray;
			if (sourceGray >= A && sourceGray <= B)
				sourceGray = grayLevel;
			mat[i][j] = sourceGray;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N - 1; j++)
			cout << setw(3) << setfill('0') << mat[i][j] << ' ';
		cout << setw(3) << setfill('0') << mat[i][N - 1] << endl;
	}
	return 0;
}