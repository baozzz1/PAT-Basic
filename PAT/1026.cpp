#include<iostream>
#include<iomanip>
using namespace std;

int P1026() {
	long C1, C2;
	cin >> C1 >> C2;
	int second_count = (C2 - C1) / 100;
	if ((C2 - C1) % 100 >= 50)
		second_count++;
	int hours = second_count / 3600;
	int minutes = (second_count - hours * 3600) / 60;
	int seconds = second_count - hours * 3600 - minutes * 60;
	cout << setw(2) << setfill('0') << hours << ":";
	cout << setw(2) << setfill('0') << minutes << ":";
	cout << setw(2) << setfill('0') << seconds;
	return 0;
}
