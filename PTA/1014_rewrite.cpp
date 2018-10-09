#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
void P1014_rewrite() {
	vector<string> get;
	string word;
	int N = 4;
	map<char, string> week = { {'A',"MON"},{'B',"TUE"},{'C',"WED"},
	{'D',"THU"},{'E',"FRI"},{'F',"SAT"}, {'G',"SUN"} };
	while (N-- && cin >> word)
		get.push_back(word);
	int count = 0;
	for (int index = 0; index < get[0].size() && index < get[1].size(); index++) {
		if (get[0][index] == get[1][index])
			if (get[0][index] >= 'A'&&get[0][index] <= 'G' && count == 0)
			{
				cout << week[get[0][index]] << " ";
				count++;
				continue;
			}
			else if (((get[0][index] >= 'A'&&get[0][index] <= 'N') || (get[0][index] >= '0'&&get[0][index] <= '9')) && count == 1) {
				if (get[0][index] >= '0'&&get[0][index] <= '9')
					cout << "0" << get[0][index];
				else if (get[0][index] >= 'A'&&get[0][index] <= 'N')
					cout << get[0][index] - 'A' + 10;
				cout << ":";
				count++;
				continue;
			}
	}
	for (int index = 0; index < get[2].size() && index < get[3].size(); index++) {
		if (get[2][index] == get[3][index])
			if ((get[2][index] >= 'A'&&get[2][index] <= 'Z') || (get[2][index] >= 'a'&&get[2][index] <= 'z')) {
				if (index < 10)
					cout << "0" << index;
				else
					cout << index;
			}
	}

}