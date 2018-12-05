#include<iostream>
#include<vector>
using namespace std;
void P1008() {
	int N, M;
	if (cin >> N && N >= 0 && N <= 100) {
		if (cin >> M && M >= 0) {
			M %= N;
			vector<int> vec;
			int word;
			while (vec.size() < N && cin >> word)
				vec.push_back(word);
			vector<int> res;
			for (int i = M; i > 0; i--)
				res.push_back(vec[N - i]);
			for (int i = 0; i < N - M; i++)
				res.push_back(vec[i]);
			for (int i = 0; i < N - 1; i++)
				cout << res[i] << " ";
			cout << res[N - 1];
		}
	}
}