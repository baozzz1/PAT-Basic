#include<iostream>
#include<string>
#include<map>
using namespace std;
void print(map<char, int> count) {
	int maxA = 0;
	char maxChar = 'B';
	if (count['B'] > maxA) {
		maxA = count['B'];
		maxChar = 'B';
	}
	if (count['C'] > maxA) {
		maxA = count['C'];
		maxChar = 'C';
	}
	if (count['J'] > maxA) {
		maxA = count['J'];
		maxChar = 'J';
	}
	cout << maxChar;
}
int P1018() {
	int N;
	cin >> N;
	char A, B;
	map<char, int> countA = { {'C',0},{'J',0}, {'B',0} };
	map<char, int> countB = { {'C',0},{'J',0}, {'B',0} };
	int countEqual = 0;
	while (N--) {
		cin >> A >> B;
		switch (A) {
		case 'C':
			switch (B) {
			case 'C':
				countEqual++;
				break;
			case 'J':
				countA['C']++;
				break;
			case 'B':
				countB['B']++;
				break;
			}
			break;
		case 'J':
			switch (B) {
			case 'J':
				countEqual++;
				break;
			case 'B':
				countA['J']++;
				break;
			case 'C':
				countB['C']++;
				break;
			}
			break;
		case 'B':
			switch (B) {
			case 'B':
				countEqual++;
				break;
			case 'C':
				countA['B']++;
				break;
			case 'J':
				countB['J']++;
				break;
			}
			break;
		}
	}
	cout << countA['C'] + countA['J'] + countA['B'] << " " << countEqual << " " << countB['C'] + countB['J'] + countB['B'] << endl;
	cout << countB['C'] + countB['J'] + countB['B'] << " " << countEqual << " " << countA['C'] + countA['J'] + countA['B'] << endl;
	print(countA);
	cout << " ";
	print(countB);
	return 0;
}