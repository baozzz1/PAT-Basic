#include<iostream>
#include<math.h>
using namespace std;

int P1051() {
	double r1, p1, r2, p2;
	cin >> r1 >> p1 >> r2 >> p2;
	double r3 = r1 * r2;
	double p3 = p1 + p2;
	double a3 = r3 * cos(p3);
	double b3 = r3 * sin(p3);
	//关键是浮点数在只取2位小数的时候，和0的大小对比方式；另外还要考虑输出的格式
	if (fabs(a3) < 0.01) {
		if (fabs(b3) < 0.01)
			cout << "0";
		else if (b3 < 0)
			printf("0.00-%.2fi", -b3);
		else if (b3 > 0)
			printf("0.00+%.2fi", b3);
	}
	else {
		printf("%.2f", a3);
		if (fabs(b3) < 0.01)
			printf("+0.00i");
		else if (b3 < 0)
			printf("-%.2fi", -b3);
		else if (b3 > 0)
			printf("+%.2fi", b3);
	}

	return 0;
}