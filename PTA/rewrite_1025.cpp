#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
struct Point {
	friend void swapData(Point &p1, Point &p2);
	Point(const string &addr, const int &data, const string &next) :Data(make_pair(addr, data)) {
		if (next == "-1")
			isEnd = true;
		Next = next;
	}
	Point() {}
	pair<string, int> Data;
	bool isEnd = false;
	string Next;
};
void swapData(Point &p1, Point &p2) {
	auto temp = p1.Data;
	p1.Data = p2.Data;
	p2.Data = temp;
}
void print(const Point &p) {
	cout << p.Data.first << " " << p.Data.second << " ";
	cout << p.Next;
	cout << endl;
}

int P1025_rewrite() {
	string start;
	int N, K;
	cin >> start >> N >> K;
	string addr, next;
	int data;
	list<Point> points;
	int n = N;
	while (n--) {
		cin >> addr >> data >> next;
		points.push_back(Point(addr, data, next));
	}

	string lastNext = start;
	vector<Point> res;
	while (lastNext != "-1") {
		auto iter = find_if(points.begin(), points.end(), [lastNext](const Point &p) {return p.Data.first == lastNext; });
		res.push_back(*iter);
		lastNext = iter->Next;
		points.erase(iter);
	}
	N = res.size();
	int times = N / K;
	for (int i = 0; i < times; i++) {
		for (int j = 0; j < K / 2; j++) {
			swapData(res[i*K + j], res[(i + 1)*K - j - 1]);
		}
	}
	int i = 0;
	for (; i < N - 1; i++) {
		res[i].Next = res[i + 1].Data.first;
		print(res[i]);
	}
	res[i].Next = "-1";
	print(res[i]);

	return 0;

}