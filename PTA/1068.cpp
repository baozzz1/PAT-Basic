#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<tuple>
using namespace std;

struct point {
	point() {}
	point(int r, int co, int colo) :row(r), col(co), color(colo) {}
	int row;
	int col;
	int color;
};

bool compare(const int &currNum, const int &target, const int &diff) {
	return abs(currNum - target) > diff;
}

bool compareWithArray(const int IndexI, const int &IndexJ, const vector<vector<int>> &mat, const int &TOL) {
	bool noLeft = IndexJ == 0;
	bool noRight = IndexJ == mat[0].size() - 1;
	bool noUp = IndexI == 0;
	bool noDown = IndexI == mat.size() - 1;
	if(		(noUp || noLeft ||		compare(mat[IndexI][IndexJ], mat[IndexI - 1	][IndexJ - 1], TOL))
		&&	(noUp ||				compare(mat[IndexI][IndexJ], mat[IndexI - 1	][IndexJ	], TOL))
		&&	(noUp || noRight||		compare(mat[IndexI][IndexJ], mat[IndexI - 1	][IndexJ + 1], TOL))
		&&	(noLeft ||				compare(mat[IndexI][IndexJ], mat[IndexI		][IndexJ - 1], TOL))
		&&	(noRight ||				compare(mat[IndexI][IndexJ], mat[IndexI		][IndexJ + 1], TOL))
		&&	(noDown || noLeft ||	compare(mat[IndexI][IndexJ], mat[IndexI + 1	][IndexJ - 1], TOL))
		&&	(noDown ||				compare(mat[IndexI][IndexJ], mat[IndexI + 1	][IndexJ	], TOL))
		&&	(noDown || noRight ||	compare(mat[IndexI][IndexJ], mat[IndexI + 1	][IndexJ + 1], TOL)))
		return true;
	return false;
}

//关键是图像四周边缘的点的检测，可以就直接不考虑超限边缘.
int P1068() {
	int M, N, TOL;
	cin >> M >> N >> TOL;
	vector<vector<int>> mat(N, vector<int>(M));
	//color, 点的数目, 对应的点的坐标
	map<int, vector<point>> isSame;
	vector<point> speciallyPoints, res;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
			//isSame[mat[i][j]].first++;
			isSame[mat[i][j]].push_back(point(i, j, mat[i][j]));
		}
	}

	auto iter = isSame.begin();
	for (; iter != isSame.end(); ++iter)
		if (iter->second.size() == 1)
			speciallyPoints.push_back(iter->second[0]);
	if (speciallyPoints.size() == 0) {
		cout << "Not Exist";
		return 0;
	}

	for (int r = 0; r < speciallyPoints.size(); r++) {
		//if (speciallyPoints[r].row == 0 || speciallyPoints[r].row == N - 1 || speciallyPoints[r].col == 0 || speciallyPoints[r].col == M - 1)
		//	continue;
		if (compareWithArray(speciallyPoints[r].row, speciallyPoints[r].col, mat, TOL))
			res.push_back(speciallyPoints[r]);
	}
	if (res.size() == 0) {
		cout << "Not Exist";
		return 0;
	}
	else if (res.size() > 1) {
		cout << "Not Unique";
		return 0;
	}
	else
		cout << "(" << res[0].col + 1 << ", " << res[0].row + 1 << "): " << res[0].color;

	return 0;
}