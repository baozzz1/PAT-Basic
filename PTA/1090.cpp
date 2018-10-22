#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int P1090() {
	int N, M;
	cin >> N >> M;

	map<int, vector<int>> noFit;
	int first, second;
	for (int i = 0; i < N; i++) {
		cin >> first >> second;
		noFit[first].push_back(second);
		noFit[second].push_back(first);
	}

	int K;
	bool isFit = true;
	for (int i = 0; i < M; i++) {
		cin >> K;
		vector<int> box(100000, 0);
		isFit = true;
		vector<int> thisShip(K);
		for (int j = 0; j < K; j++) {
			//thisShip��¼�˴���ŵĻ��box��¼��Ӧ�����Ʒ�Ƿ��ڴ���
			cin >> thisShip[j];
			box[thisShip[j]] = 1;
		}
		for (int j = 0; j < K && isFit; j++) {
			//�Դ˴��ϵ���Ʒ����Ѱ�ң����Ƿ������Υ��Ʒ�б���iter==end�򲻴���
			auto iter = noFit.find(thisShip[j]);
			if (iter != noFit.end()) {
				auto vec = iter->second;
				for (auto x : vec)
					if (box[x]) {
						isFit = false;
						break;
					}
			}
		}
		if (isFit)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}

//#include<iostream>
//#include<string>
//#include<vector>
//#include<map>
//using namespace std;
//
//int main() {
//	int N, M;
//	cin >> N >> M;
//	int K;
//	map<int, map<int, int>> noFit;
//	int first, second;
//	bool isFit = true;
//	for (int i = 0; i < N; i++) {
//		cin >> first >> second;
//			noFit[first][second] = 1;
//			noFit[second][first] = 1;
//	}
//	for (int i = 0; i < M; i++) {
//		cin >> K;
//		vector<int> box(K);
//		for (int j = 0; j < K; j++)
//			cin >> box[j];
//		isFit = true;
//		for (int j = 0; j < K && isFit; j++) {
//			for (int k = j + 1; k < K && isFit; k++) {
//				if (noFit[box[j]][box[k]]) {
//					isFit = false;
//					break;
//				}
//			}
//		}
//		if (isFit)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//
//	return 0;
//}