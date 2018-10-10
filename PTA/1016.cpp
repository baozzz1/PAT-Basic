#include<iostream>
using namespace std;
int Pnum(int num,const int &Dnum) {
	int count = 0;
	int res = 1;
	while (num) {
		if (num % 10 == Dnum)
			count++;
		num /= 10;
	}
	if (count == 0) return 0;
	else
		while (--count) {
			res = res * 10 + 1;
		}
	return res * Dnum;
}
int P1016() {
	int A, Da, B, Db;
	cin >> A >> Da >> B >> Db;
	cout << Pnum(A, Da) + Pnum(B, Db);

	return 0;
}