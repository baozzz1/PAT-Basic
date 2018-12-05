#include<iostream>
#include<vector>
#include<tuple>
#include<math.h>
using namespace std;
void P1012() {
	int N;
	cin >> N;
	vector<vector<int>> allnum(5);
	double sum3 = 0.0;
	tuple<int, int, unsigned, double, int> tup({ 0,0,0,0.0,0 });
	int word;
	while (N-- && cin >> word) {
		int rem = word % 5;
		switch (rem) {
		case 0:
			allnum[0].push_back(word);
			break;
		case 1:
			allnum[1].push_back(word);
			break;
		case 2:
			allnum[2].push_back(word);
			get<2>(tup)++;
			break;
		case 3:
			allnum[3].push_back(word);
			break;
		case 4:
			allnum[4].push_back(word);
			if (word > get<4>(tup))
				get<4>(tup) = word;
			break;
		}
	}
	for (int i = 0; i < allnum[0].size(); i++) {
		if (allnum[0][i] % 2 == 0)
			get<0>(tup) += allnum[0][i];
	}
	for (int i = 0; i < allnum[1].size(); i++) {
		get<1>(tup) += ((i % 2) ? -1 : 1)*allnum[1][i];
	}
	for (int i = 0; i < allnum[3].size(); i++) {
		sum3 += allnum[3][i];
	}
	//---------------------------¹Ø¼ü£¡£¡£¡£¡£¡£¡£¡-----------------
	if (allnum[3].size() != 0)
		get<3>(tup) = (double)sum3 / allnum[3].size();

	if (get<0>(tup) == 0)
		cout << "N ";
	else
		cout << get<0>(tup) << " ";

	if (get<1>(tup) == 0 && allnum[1].size() == 0)
		cout << "N ";
	else
		cout << get<1>(tup) << " ";

	if (get<2>(tup) == 0)
		cout << "N ";
	else
		cout << get<2>(tup) << " ";

	if (get<3>(tup) != 0.0) {
		printf("%.1f", get<3>(tup));
		cout << " ";
	}
	else {
		cout << "N ";
	}

	if (get<4>(tup) == 0)
		cout << 'N';
	else
		cout << get<4>(tup);

}