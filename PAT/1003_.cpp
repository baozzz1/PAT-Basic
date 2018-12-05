#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1003_() {
	int n;
	string s;
	cin >> n;
	int indexP, indexT;
	bool flag = true;
	while (n--) {
		cin >> s;
		indexP = -1, indexT = -1;
		flag = true;
		for (int i = 0; i < s.size() && flag;i++) {
			switch (s[i]) {
			case 'A':
				break;
			case 'P':
				if (indexP == -1)
					indexP = i;
				else
					flag = false;
				break;
			case 'T':
				if (indexT == -1)
					indexT = i;
				else
					flag = false;
				break;
			default:
				flag = false;
			}
		}

		if(flag && indexP >=0 && indexP + 1 < indexT && (indexP *(indexT-indexP- 1) == s.size()-indexT-1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}