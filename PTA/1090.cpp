#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int K;
	map<int, map<int, int>> noFit;
	int first, second, item;
	vector<int> box;
	bool isFit = true;
	vector<bool> res(M);
	for (int i = 0; i < N; i++) {
		cin >> first >> second;
		if (first < second)
		noFit[first][second] = 1;
		else
		noFit[second][first] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> K;
		box.clear();
		isFit = true;
		/*for (int j = 0; j < K; j++) {
			cin >> item;
			for (auto iter = box.begin(); iter != box.end() && isFit; ++iter) {
				if (noFit[item][*iter])
					isFit = false;
			}
			if (isFit);
				box.push_back(item);
		}*/
		for (int j = 0; j < K; j++) {
			cin >> item;
			box.push_back(item);
		}
		sort(box.begin(), box.end());
		for (int j = 0; j < box.size() && isFit; j++) {
			for (int k = j+1; k < K && isFit; k++) {
				if (noFit[box[j]][box[k]])
					isFit = false;
			}
		}

		res[i] = isFit;
	}
	for (int i = 0; i < M; i++) {
		if (res[i])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}