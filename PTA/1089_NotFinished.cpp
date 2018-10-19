#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct wolfKiller {
	int index;
	bool isWolf;
	bool guess;
	int guessOther;

};
int P1089() {
	int N, num;
	cin >> N;
	char c;
	vector<wolfKiller> wolves(N);
	for (int i = 0; i < N; i++) {
		cin >> c >> num;
		wolves[i].index = i + 1;
		if (c == '-')
			wolves[i].guess = false;
		else if(c == '+')
			wolves[i].guess = true;
		wolves[i].guessOther = num;
	}

	return 0;
}