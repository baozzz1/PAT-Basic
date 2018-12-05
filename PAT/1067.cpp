#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1067() {
	string password, passwordTry;
	vector<string> res;
	int N;
	cin >> password >> N;
	getchar();
	int errorCount = 0;
	while (true) {
		getline(cin, passwordTry);
		if (passwordTry == "#")
			break;
		else if (passwordTry == password) {
			res.push_back("Welcome in");
			break;
		}
		else {
			res.push_back("Wrong password: " + passwordTry);
			errorCount++;
			if (errorCount == N) {
				res.push_back("Account locked");
				break;
			}
		}
	}

	for (int j = 0; j < res.size(); j++)
		cout << res[j] << endl;

	return 0;
}