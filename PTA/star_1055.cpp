#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct student {
	student() {}
	student(string n, int t) :name(n), tall(t) {}
	string name;
	int tall;
};
bool comp(const student &s1, const student &s2) {
	if (s1.tall == s2.tall)
		return s1.name < s2.name;
	else
		return s1.tall > s2.tall;
}
void sortTallAtMid(vector<student> &st, const int &left, const int &length) {
	int resIndexMid = length / 2;
	vector<student> res(length);
	int stIndex = left;
	res[resIndexMid] = st[stIndex];
	stIndex++;
	int temp = 1;
	while (stIndex < left + length) {
		res[resIndexMid - temp] = st[stIndex++];
		if (resIndexMid + temp >= length)
			break;
		res[resIndexMid + temp] = st[stIndex++];
		temp++;
	}
	for (int i = 0; i < length - 1; i++)
		cout << res[i].name << " ";
	cout << res[length - 1].name << endl;
}
int P1055() {
	int N, K;
	cin >> N >> K;
	vector<student> all;
	string name;
	int tall;
	for (int n = 0; n < N; n++) {
		cin >> name >> tall;
		all.push_back(student(name, tall));
	}
	sort(all.begin(), all.end(), comp);
	//iÎªµÚN-iÅÅ
	int indexFirst = 0;
	int length = N - N / K * (K - 1);
	sortTallAtMid(all, indexFirst, length);
	for (int i = 1; i < K; i++) {
		indexFirst += length;
		length = N / K;
		sortTallAtMid(all, indexFirst, length);
	}


	return 0;
}