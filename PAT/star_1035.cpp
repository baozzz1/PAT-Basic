#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int P1035() {
	int N;
	cin >> N;
	vector<int> origin(N), sorting(N);
	int i = 0;
	//原始序列
	for (i = 0; i < N; i++)
		cin >> origin[i];
	//中间序列
	for (i = 0; i < N; i++)
		cin >> sorting[i];
	int index = -1;
	for (int i = 1; i < N; ++i) {
		if (sorting[i] < sorting[i - 1]) {
			index = i;
			break;
		}
	}
	int flag = 0; //0为插入排序，1为归并排序
	for (int i = index; i < N; ++i) {
		if (sorting[i] != origin[i]) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << "Insertion Sort" << endl;
		sort(sorting.begin(), sorting.begin() + index + 1);
		for (int i = 0; i < N - 1; i++)
			cout << sorting[i] << " ";
		cout << sorting[N - 1];
	}
	else if (flag == 1) {
		cout << "Merge Sort" << endl;
		int k = 1;
		bool isNotEqual = true;
		while (isNotEqual) {
			isNotEqual = false;
			if (!equal(origin.begin(), origin.end(), sorting.begin())) { //如果不同的话，就进行一次归并排序
				isNotEqual = true;
			}
			k *= 2;
			for (int i = 0; i < N / k; ++i) {
				sort(origin.begin() + i * k, origin.begin() + (i + 1) * k);
			}
			sort(origin.begin() + k * (N / k), origin.end());
		}
		for (int i = 0; i < N - 1; i++)
			cout << origin[i] << " ";
		cout << origin[N - 1];
	}
	cout << endl;
	return 0;
}