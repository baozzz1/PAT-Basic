#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<map>
using namespace std;
using namespace placeholders;

struct ListPoint {
	int Address, Next;
	int Data;
	int orderedRank;
};

/*-------------------------------*/
void printAddrOrNext(const vector<ListPoint>::const_iterator &iter) {
	cout << setw(5) << setfill('0') << iter->Address << " " << iter->Data << " ";
	cout << setw(5) << setfill('0') << (iter + 1)->Address << endl;
}
void printData(const vector<ListPoint>::const_iterator &iter) {
	cout << setw(5) << setfill('0') << iter->Address << " " << iter->Data << " ";
	cout << setw(5) << setfill('0') << (iter + 1)->Address << endl;
}
int main() {
	int start;
	int N, K;
	cin >> start >> N >> K;
	vector<ListPoint> res;
	vector<ListPoint> belowZeroPoints, midPoints, upperPoints;

	int addr, data, next;
	map<int, ListPoint> points;
	for (int i = 0; i < N; i++) {
		cin >> addr >> data >> next;
		points[addr].Address = addr;
		points[addr].Data = data;
		points[addr].Next = next;
	}
	int last = start;
	int index = 0;
	while (true) {
		try {
			auto point = points.at(last);
			if (point.Data < 0)
				belowZeroPoints.push_back(point);
			else if (point.Data >= 0 && point.Data <= K)
				midPoints.push_back(point);
			else
				upperPoints.push_back(point);
			last = point.Next;
			points.erase(point.Address);
		}
		catch (out_of_range) {
			break;
		}
	}

	auto iter = belowZeroPoints.cbegin();
	for (; iter != belowZeroPoints.cend() - 1; ++iter) {
		print(iter);
	}
	cout << setw(5) << setfill('0') << iter->Address << " " << iter->Data << " ";
	iter = midPoints.cbegin();
	cout << setw(5) << setfill('0') << iter->Address << endl;

	for (; iter != midPoints.cend() - 1; ++iter) {
		print(iter);
	}
	cout << setw(5) << setfill('0') << iter->Address << " " << iter->Data << " ";
	iter = upperPoints.cbegin();
	cout << setw(5) << setfill('0') << iter->Address << endl;

	for (; iter != upperPoints.cend() - 1; ++iter) {
		print(iter);
	}
	cout << setw(5) << setfill('0') << iter->Address << " " << iter->Data << " " << "-1";

	return 0;
}