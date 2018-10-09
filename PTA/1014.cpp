#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
bool isCapAlpha(char c) {
	if (c >= 'A' && c <= 'G')
		return true;
	else
		return false;
}
bool isAlpha(char c) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return true;
	else
		return false;
}
bool isNumOrCapAlpha(char c) {
	if ((c >= 'A' && c <= 'N') || (c >= '0' && c <= '9'))
		return true;
	else
		return false;
}
bool isNum(char c) {
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}
void P1014() {
	vector<string> get;
	string word;
	int N = 4;
	map<char, string> week = { {'A',"MON"},{'B',"TUE"},{'C',"WED"},
	{'D',"THU"},{'E',"FRI"},{'F',"SAT"}, {'G',"SUN"} };
	while (N-- && cin >> word)
		get.push_back(word);
	int index0 = 0;
	int count = 0;
	while (index0 < get[0].size() && index0 < get[1].size()) {
		if (isCapAlpha(get[0][index0]) && get[0][index0] == get[1][index0])
			if (count == 0) {
				cout << week[get[0][index0]] << ' ';
				count++;
				continue;
			}
		if (isNumOrCapAlpha(get[0][index0]) && get[0][index0] == get[1][index0])
			if (count == 1) {
				if (isNum(get[0][index0]))
					cout << '0' <<get[0][index0];
				else if (get[0][index0]>='A' && get[0][index0] <= 'N' )
					cout << get[0][index0] - 'A' + 11;
				cout << ':';
				count++;
				break;
			}
		index0++;
	}

	int index2 = 0;
	while (index2 < get[2].size() && index2 < get[3].size()) {
		if (isAlpha(get[2][index2]) && get[2][index2] == get[3][index2]) {
			if (index2 < 10)
				cout << '0' << index2;
			else
				cout << index2;
			break;
		}
		index2++;
	}
}