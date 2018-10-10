#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct OnePoint {
	friend void swapData(OnePoint &p1, OnePoint &p2);
	OnePoint(const string &addr, const int &data, const string &next) :Address(addr), Data(data) {
		if (next == "-1")
			isEnd = true;
		else
			Next = next;
	}
	OnePoint() {}
	int Data;
	string Address;
	bool isEnd = false;
	string Next;
};
void swapData(OnePoint &p1, OnePoint &p2) {
	int temp = p1.Data;
	p1.Data = p2.Data;
	p2.Data = temp;
}
void print(const OnePoint &p) {
	cout << p.Address << " " << p.Data << " ";
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
	vector<OnePoint> points;
	int n = N;
	while (n--) {
		cin >> addr >> data >> next;
		points.push_back(OnePoint(addr, data, next));
	}
	//vector<OnePoint> pointsK(K);
	string lastNext = start;
	/*while (N > 0) {
		for (auto iter = pointsK.begin(); iter != pointsK.end(); iter++) {
			*iter = *find_if(points.begin(), points.end(), [lastNext](const OnePoint &p) {return p.Address == lastNext ? true : false; });
			if (iter->isEnd) {
				pointsK.resize(iter - pointsK.begin());
				lastNext = "-1";
				break;
			}
			else
				lastNext = iter->Next;
		}
		for (int i = 0; i < pointsK.size() / 2; i++)
			swapData(pointsK[i], pointsK[pointsK.size() - i - 1]);
		for (int i = 0; i < pointsK.size(); i++) {
			print(pointsK[i]);
		}
		N -= K;
	}*/
	for (int i = 0; i < N; i++) {
		print(points[i]);
	}
	return 0;
}