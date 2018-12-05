#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 非空字符串不代表输入的字符串没有空格！！！！
//不能用cin来读一整行，换成getline
int P1081() {
	int N;
	cin >> N;
	string s;
	vector<string> res(N);
	getchar();
	for (int i = 0; i < N; i++) {
		getline(cin, s);
		if (s.size() < 6) {
			res[i] = "Your password is tai duan le.";
			continue;
		}
		int digitNum = 0, characterNum = 0;
		bool invalidChar = false, noDigit = false, noCharacter = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0'&&s[i] <= '9')
				digitNum++;
			else if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z'))
				characterNum++;
			else if (s[i] != '.')
				invalidChar = true;
		}
		if (digitNum == 0)
			noDigit = true;
		else if (characterNum == 0)
			noCharacter = true;

		if (invalidChar)
			res[i] = "Your password is tai luan le.";
		else if (noDigit)
			res[i] = "Your password needs shu zi.";
		else if (noCharacter)
			res[i] = "Your password needs zi mu.";
		else
			res[i] = "Your password is wan mei.";
	}

	for (int i = 0; i < N; i++)
		cout << res[i] << endl;
	return 0;
}