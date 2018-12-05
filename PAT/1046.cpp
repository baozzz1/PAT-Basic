#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1046() {
	int N;
	cin >> N;
	int Ashout, Bshout, Ahand, Bhand;
	int Acount = 0, Bcount = 0;
	bool Awin, Bwin;
	while (N--) {
		cin >> Ashout >> Ahand >> Bshout >> Bhand;
		Awin = Ahand == Ashout + Bshout;
		Bwin = Bhand == Ashout + Bshout;
		if (Awin && !Bwin)	Acount++;
		else if (!Awin && Bwin)	Bcount++;
	}
	cout << Bcount << " " << Acount;

	return 0;
}