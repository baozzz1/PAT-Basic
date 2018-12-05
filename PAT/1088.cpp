#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

bool findJia(const int &X, const int &Y, int &jia, int &yi) {
	for (int i = 9; i >= 1; i--) {
		for (int j = 9; j >= 0; j--) {
			jia = i * 10 + j;
			yi = j * 10 + i;
			if (yi *X == abs(jia - yi)*Y)
				return true;
		}
	}
	return false;
}
template <typename T>
void ThreePeopleGo(const int &me, const T &other) {
	if (me > other)
		cout << "Gai";
	else if (me < other)
		cout << "Cong";
	else if (me == other)
		cout << "Ping";
}

// 丙不一定是整数！！！
int P1088() {
	int M, X, Y;
	cin >> M >> X >> Y;
	int jia, yi;
	if (findJia(X, Y, jia, yi)) {
		double bing = (double)yi / (double)Y;
		cout << jia << " ";
		ThreePeopleGo(M, jia);
		cout << " ";
		ThreePeopleGo(M, yi);
		cout << " ";
		ThreePeopleGo(M, bing);
	}
	else
		cout << "No Solution";
	return 0;
}