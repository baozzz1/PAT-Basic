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
void swapPoint(Point &p1, Point &p2) {
	auto temp = p1;
	p1 = p2;
	p2 = temp;
}
void print(const Point &p) {
	cout << p.Data.first << " " << p.Data.second << " ";
	if (p.isEnd)
		cout << "-1";
	else
		cout << p.Next;
	cout << endl;
}

int main() {
	string start;
	int N, K;
	cin >> start >> N >> K;
	string addr, next;
	int data;
	vector<Point> points;
	int n = N;
	while (n--) {
		cin >> addr >> data >> next;
		points.push_back(Point(addr, data, next));
	}

	string lastNext = start;
	list<Point> lst;
	while (lastNext != "-1") {
		lst.push_back(*find_if(points.begin(), points.end(), [lastNext](const Point &p) {return p.Data.first == lastNext; }));
		lastNext=
	}


	

}