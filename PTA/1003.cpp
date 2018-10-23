#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//看清输出格式！Yes 和 YES 要分清
int P1003() {
	int N;
	cin >> N;
	string s;
	vector<bool> res(N);
	for (int i = 0; i < N; i++) {
		cin >> s;
		bool flag = true;
		int countP = 0, countT = 0;
		int indexP = 0, indexT = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'P') {
				countP++;
				indexP = j;
			}
			else if (s[j] == 'T') {
				countT++;
				indexT = j;
			}
			else if (s[j] != 'A') {
				flag = false;
				break;
			}
		}
		if (!flag || countP != 1 || countT != 1 || indexT - indexP <= 1) {
			res[i] = false;
			continue;
		}
		int lengthA = indexP;
		int lengthB = indexT - indexP - 1;
		int lengthC = s.size() - indexT - 1;
		if (lengthC == lengthA * lengthB)
			res[i] = true;
		else
			res[i] = false;


	}
	for (int i = 0; i < N - 1; i++)
		cout << (res[i] ? "YES" : "NO") << endl;
	cout << (res[N - 1] ? "YES" : "NO");
	return 0;
}