#include<vector>
#include<string>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<iterator>
using namespace std;
class database;
void print(const database&);
class database {
	friend void print(const database&);
public:
	database(const string &n, const string &sn, const int &g) :name(n), student_number(sn), grade(g) {}
	const int get_grade() const { return grade; }
private:
	string name;
	string student_number;
	int grade;
};
void print(const database &db) {
	cout << db.name << " " << db.student_number << endl;
}
bool compare(const database &db1, const database &db2) {
	return db1.get_grade() < db2.get_grade();
}
void P1004() {
	vector<database> dbvec;
	unsigned num;
	if (cin >> num && num > 0) {
		int grade = 0;
		string name, student_number;
		for (unsigned index = 0; index < num; index++) {
			cin >> name >> student_number >> grade;
			dbvec.push_back(database(name, student_number, grade));
		}
		sort(dbvec.begin(), dbvec.end(), compare);
		print(*(dbvec.cend()-1));
		print(*dbvec.cbegin());
	}
}