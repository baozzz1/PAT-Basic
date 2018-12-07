#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
#include<iomanip>
using namespace std;

struct node_point {
	string addr, next;
	int data;
};

void exch(vector<node_point> &points, int lo, int hi) {
	node_point temp;
	int i = lo, j = hi - 1;
	while (i < j) {
		temp = points[i];
		points[i] = points[j];
		points[j] = temp;
		i++;
		j--;
	}
}


int main() {
	int K, N;
	string start;
	cin >> start >> N >> K;
	vector<node_point> points(N), point_sorted(N);
	for (int i = 0; i < N; i++)
		cin >> points[i].addr >> points[i].data >> points[i].next;

	string curr = start;
	for (int i = 0; i < N; i++) {
		auto iter = find_if(points.begin(), points.end(), [curr](node_point x) {return x.addr == curr; });
		point_sorted[i] = *iter;
		curr = iter->next;
	}
	int cycle = N / K;
	int last = N % K;
	for (int i = 0; i < cycle; i++) {
		exch(point_sorted, i*K, (i + 1)*K);
	}
	for (int i = 0; i < N -1; i++) {
		cout << point_sorted[i].addr << " " << point_sorted[i].data << " " << point_sorted[i + 1].addr << endl;
	}
	cout << point_sorted[N-1].addr << " " << point_sorted[N-1].data << " -1";
	

}