#include<iostream>
#include<vector>
using namespace std;

// �������⣡������Ŀ˵������ظ��Ĳ�ֵ������ôֻ��һ�εĲ�ֵ�Ͳ�Ҫ�����
int P1083() {
	int N;
	cin >> N;
	// �±��ǲ�ֵ������ֵ���ΪN-1��ֵΪ�ظ�����
	vector<int> res(N,0);
	int diff, unordered;
	for (int i = 0; i < N; i++) {
		cin >> unordered;
		diff = (unordered >= (i + 1)) ? (unordered - (i + 1)) : ((i + 1) - unordered);
		res[diff]++;
	}
	for (int i = res.size() - 1; i >= 0; i--)
		if (res[i] != 0 &&res[i] !=1)
			cout << i << " " << res[i] << endl;
	return 0;
}