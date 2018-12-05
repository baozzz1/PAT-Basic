#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int P1052() {
	string line;
	vector<vector<string>> face(3);
	for (int line_no = 0; line_no < 3; line_no++) {
		getline(cin, line);
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '[') {
				i++;
				string word;
				while (line[i] != ']' && i < line.size())
					word += line[i++];
				face[line_no].push_back(word);
			}
		}
	}
	int K;
	cin >> K;
	int wordIndex;
	vector<string> res(K);
	for (int k = 0; k < K; k++) {
		bool flag = true;
		for (int i = 0; i < 3 && flag == true; i++) {
			cin >> wordIndex;
			if (wordIndex < 1 || wordIndex > face[i].size()) {
				flag = false;
				continue;
			}
			res[k] += face[i][wordIndex - 1] + ((i == 0) ? "(" : "");
		}
		for (int i = 1; i >= 0 && flag == true; i--) {
			cin >> wordIndex;
			if (wordIndex < 1 || wordIndex > face[i].size()) {
				flag = false;
				continue;
			}
			res[k] += face[i][wordIndex - 1] + ((i == 1) ? ")" : "");
		}
		if (!flag)
			res[k] = "Are you kidding me? @\\/@";		//×¢Òâ×ªÒå·û
	}
	for (int k = 0; k < K; k++)
		cout << res[k] << endl;
	return 0;
}