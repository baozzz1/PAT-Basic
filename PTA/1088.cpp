#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;


bool findJia(const int &X, const int &Y,int &jia,int &yi) {
	int jia, yi;
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
int main() {
	int M, X, Y;
	cin >> M >> X >> Y;
	int jia, yi, bing;
	if (findJia(X, Y, jia, yi)) {

	}

	return 0;
}