#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1021() {
	string N;
	cin >> N;
	vector<int> vec(10,0);
	for (int i = 0; i < N.size(); i++) {
		vec[N[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (vec[i] != 0)
			cout << i << ":" << vec[i] << endl;
	}

	return 0;
}