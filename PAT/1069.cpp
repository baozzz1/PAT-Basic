#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int P1069() {
	int M, N, S;
	//ת���������н��������һλ�н��ߵ���ţ�1��ʼ��
	cin >> M >> N >> S;
	//���ԣ����н����˷���vector�����������������Ϣ
	string name;
	int cycleN = 0;
	//set<string> whoGetPrice;
	vector<string> getPriceOrdered;
	for (int i = 0; i < M; i++) {
		cin >> name;
		if (i + 1 == S) {
			//whoGetPrice.insert(name);
			getPriceOrdered.push_back(name);
		}
		else if (i + 1 > S) {
			cycleN++;
			if (cycleN == N) {
				auto iter = find(getPriceOrdered.begin(), getPriceOrdered.end(), name);
				if (iter == getPriceOrdered.end()) {
					//whoGetPrice.insert(name);
					getPriceOrdered.push_back(name);
					cycleN = 0;
				}
				else
					cycleN--;
			}
		}
	}
	if (getPriceOrdered.size() == 0) {
		cout << "Keep going..." << endl;
		return 0;
	}
	for (int i = 0; i < getPriceOrdered.size(); i++) {
		cout << getPriceOrdered[i] << endl;
	}
	return 0;
}