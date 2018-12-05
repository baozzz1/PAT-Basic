#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct money {
	money() {}
	money(long t) {
		Knut = t % 29;
		t /= 29;
		Sickle = t % 17;
		Galleon = t / 17;
		cout << Galleon << '.' << Sickle << '.' << Knut;
	}
	int Galleon;
	int Sickle;
	int Knut;
	long total() {
		return (Galleon * 17 + Sickle) * 29 + Knut;
	}
};
int P1037() {
	money P, A;
	scanf_s("%d.%d.%d", &P.Galleon, &P.Sickle, &P.Knut);
	scanf_s("%d.%d.%d", &A.Galleon, &A.Sickle, &A.Knut);
	long P_total = P.total();
	long A_total = A.total();
	long diff = A_total - P_total;
	if (diff < 0) {
		cout << '-';
		diff = abs(diff);
	}
	money R(diff);

	return 0;
}