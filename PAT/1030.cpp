#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int P1030() {
	long long N, p, M, m;
	cin >> N >> p;
	vector<long long> vec;
	int word;
	while (N--) {
		cin >> word;
		vec.push_back(word);
	}
	sort(vec.begin(), vec.end());
	int max = 0;
	int num = 0;
	for (int i = 0; i < vec.size(); ++i) {
		m = vec[i];
		for (int j_max = vec.size() - 1, j_min = i, j = vec.size() - 1; ; j = (j_min + j_max) / 2) {
			if (vec[j] <= p * m) {
				j_min = j;
				num = j - i + 1;
				if (j_max - j_min <= 1)
					break;
			}
			else
				j_max = j;
		}
		if (max < num)
			max = num;
		if (max > (vec.size() - i))
			break;
	}
	cout << max;
	return 0;
}
