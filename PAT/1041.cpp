#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int P1041() {
	int N;
	cin >> N;
	int n = N;
	string number;
	int tryNum, testNum;
	map<int,string> numberMap;
	map<int, int> testNumMap;
	while (n--) {
		cin >> number >> tryNum >> testNum;
		numberMap[tryNum] = number;
		testNumMap[tryNum] = testNum;
	}
	int M;
	cin >> M;
	vector<int> search(M);
	for(int i=0;i<M;i++){
		cin >> search[i];
	}
	for (int i = 0; i < M; i++) {
		cout << numberMap[search[i]] << " " << testNumMap[search[i]] << endl;
	}
	return 0;
}