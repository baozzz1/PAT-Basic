#include<iostream>
#include<string>
#include<vector>
using namespace std;

//超级坑...输出格式应该对应样例的句号、叹号后两个空格，不然全为格式错误
int P1071() {
	int T, K;
	cin >> T >> K;
	int n1, b, t, n2;
	vector<string> res;
	string thisOut;
	for (int i = 0; i < K; i++) {
		cin >> n1 >> b >> t >> n2;
		/*if (T == 0)
			continue;*/
		if (t > T)
			thisOut = "Not enough tokens.  Total = ";
		else if ((n2 < n1 && b == 0) || (n2 > n1 && b == 1)) {
			T += t;
			thisOut = "Win " + to_string(t) + "!  Total = ";
		}
		else if ((n2 < n1 && b == 1) || (n2 > n1 && b == 0)) {
			T -= t;
			thisOut = "Lose " + to_string(t) + ".  Total = ";
		}
		thisOut += to_string(T) + ".";
		res.push_back(thisOut);
		if (T == 0) {
			res.push_back("Game Over.");
			break;
		}
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}