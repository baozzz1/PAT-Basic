#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int H;
int L;
class student {
public:
	student(int i, int j, int k) :number(i), DEgrade(j), CAIgrade(k) {}
	const int totalGrade() const { return DEgrade + CAIgrade; }
	int number;
	int DEgrade;
	int CAIgrade;
};
bool firstLevel(const student &st) {
	return st.DEgrade >= H && st.CAIgrade >= H;
}
bool secondLevel(const student &st) {
	return st.DEgrade >= H && st.CAIgrade < H && st.CAIgrade >= L;
}
bool thirdLevel(const student &st) {
	return st.DEgrade < H && st.CAIgrade < H && st.CAIgrade >= L && st.DEgrade >= st.CAIgrade;
}
bool forthLevel(const student &st) {
	return (st.DEgrade < H || st.CAIgrade < H) && st.DEgrade >= L && st.CAIgrade >= st.DEgrade;
}
bool NoLevel(const student &st) {
	return st.DEgrade < L || st.CAIgrade < L;
}
bool equalLevelCompare(const student &st1, const student &st2) {
	if (st1.totalGrade() == st2.totalGrade())
		if (st1.DEgrade == st2.DEgrade)
			return st1.number < st2.number;
		else
			return st1.DEgrade > st2.DEgrade;
	else
		return st1.totalGrade() > st2.totalGrade();
}
int P1015() {
	int N;
	cin >> N >> L >> H;
	vector<vector<student>> Vec(4);
	int count = 0;
	while (N--) {
		int number, DEgrade, CAIgrade;
		cin >> number >> DEgrade >> CAIgrade;
		//vec.push_back(student(number, DEgrade, CAIgrade));
		student st = student(number, DEgrade, CAIgrade);
		if (firstLevel(st))
			Vec[0].push_back(st);
		else if (secondLevel(st))
			Vec[1].push_back(st);
		else if (thirdLevel(st))
			Vec[2].push_back(st);
		else if (forthLevel(st))
			Vec[3].push_back(st);
	}
	for (int i = 0; i < 4; i++) {
		sort(Vec[i].begin(), Vec[i].end(), equalLevelCompare);
		count += Vec[i].size();
	}
	cout << count << endl;
	for (int i = 0; i < 4; i++) 
		for (auto iter = Vec[i].cbegin(); iter != Vec[i].cend(); ++iter)
			cout << iter->number << " " << iter->DEgrade << " " << iter->CAIgrade << endl; 
	return 0;
}