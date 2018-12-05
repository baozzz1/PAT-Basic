#include<iostream>
#include<vector>
using namespace std;
int P1010() {
	vector<int> ratio;
	vector<int> exponent;
	int ratioN, exponentN;
	while (cin >> ratioN >> exponentN) {
		ratio.push_back(ratioN);
		exponent.push_back(exponentN);
	}
	if (exponent[0] == 0) {
		cout << "0 0";
		return 0;
	}
	for (auto i = 0; i < ratio.size(); i++) {
		if (exponent[i] == 0) break;
		cout << ratio[i] * exponent[i] << " " << exponent[i] - 1;
		if (i + 1 == ratio.size())
			break;
		else if (exponent[i + 1] != 0)	
			cout << " ";
		else
			break;
	}
	return 0;
}