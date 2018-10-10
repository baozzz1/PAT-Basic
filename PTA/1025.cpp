#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct OnePoint {
	friend void swapData(OnePoint &p1, OnePoint &p2);
	OnePoint(const string &addr, const int &data, const string &next) :Data(make_pair(addr, data)) {
		if (next == "-1")
			isEnd = true;
		Next = next;
	}
	OnePoint() {}
	pair<string, int> Data;
	bool isEnd = false;
	string Next;
};
void swapData(OnePoint &p1, OnePoint &p2) {
	auto temp = p1.Data;
	p1.Data = p2.Data;
	p2.Data = temp;
}
void swapPoint(OnePoint &p1, OnePoint &p2) {
	auto temp = p1;
	p1 = p2;
	p2 = temp;
}
void print(const OnePoint &p) {
	cout << p.Data.first << " " << p.Data.second << " ";
	if (p.isEnd)
		cout << "-1";
	else
		cout << p.Next;
	cout << endl;
}
int sortByAddress(vector<OnePoint> &points, const string &start) {
	string lastNext = start;
	for (int i = 0; i < points.size(); i++) {
		for (int j = i; j < points.size(); j++) {
			if (points[j].Data.first == lastNext) {
				if (points[j].isEnd) {
					swapPoint(points[i], points[j]);
					return j + 1;
				}
				lastNext = points[j].Next;
				swapPoint(points[i], points[j]);
				break;
			}
		}
	}
	return points.size();
}
int P1025() {
	string start;
	int N, K;
	cin >> start >> N >> K;
	string addr, next;
	int data;
	vector<OnePoint> points;
	int n = N;
	while (n--) {
		cin >> addr >> data >> next;
		points.push_back(OnePoint(addr, data, next));
	}
	N = sortByAddress(points, start);
	int times = N / K;
	for (int i = 0; i < times; i++) {
		for (int j = 0; j < K / 2; j++) {
			swapData(points[i*K + j], points[(i + 1)*K - j - 1]);
		}
	}
	for (int i = 0; i < N; i++) {
		if (i < N - 1)
			points[i].Next = points[i + 1].Data.first;
		else
			points[i].Next = "-1";
		print(points[i]);
	}

	return 0;
}