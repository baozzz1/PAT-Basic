#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
constexpr int currYear = 2014;
constexpr int currMonth = 9;
constexpr int currDay = 6;
constexpr int invalidYears = 200;
constexpr int thatYear = currYear - invalidYears;
void str2int(int &int_temp, const string &string_temp)
{
	stringstream stream(string_temp);
	stream >> int_temp;
}
struct people {
	people(const string &n, const int &year, const int &month, const int &day) :name(n), birth_year(year), birth_month(month), birth_day(day) {}
	people(const string &n, const string &birth);
	string name;
	int birth_year = 0;
	int birth_month = 0;
	int birth_day = 0;
	bool isTrue = true;
};
bool isYounger(const people &younger, const people &p) {
	if (p.birth_year > younger.birth_year)
		return true;
	else if (p.birth_year == younger.birth_year)
		if (p.birth_month > younger.birth_month)
			return true;
		else if (p.birth_month == younger.birth_month)
			if (p.birth_day > younger.birth_day)
				return true;
	return false;
}
bool isOlder(const people &older, const people &p) {
	if (p.birth_year < older.birth_year)
		return true;
	else if (p.birth_year == older.birth_year)
		if (p.birth_month < older.birth_month)
			return true;
		else if (p.birth_month == older.birth_month)
			if (p.birth_day < older.birth_day)
				return true;
	return false;
}
people::people(const string &n, const string &birth) :name(n) {
	//以2014年9月6日为例，200岁为非法
	str2int(birth_year, birth.substr(0, 4));
	if (birth_year < thatYear || birth_year > currYear)	//若1814年前（不包括1814年）或大于2014年出生，为不合理日期
		isTrue = false;
	else {
		str2int(birth_month, birth.substr(5, 2));
		if (birth_year == thatYear && birth_month < currMonth)	//若1814年1~8月出生，为不合理日期
			isTrue = false;
		else if (birth_year == currYear && birth_month > currMonth)	//若2014年10~12月出生，不合理
			isTrue = false;
		else {
			str2int(birth_day, birth.substr(8, 2));
			if (birth_year == thatYear && birth_month == currMonth && birth_day < currDay)	//若1814年9月1~5日出生，不合理
				isTrue = false;
			else if (birth_year == currYear && birth_month == currMonth && birth_day > currDay)	//若2014年9月 >7 日出生，不合理
				isTrue = false;
		}
	}
}

int P1028() {
	int N;
	cin >> N;
	int count = 0;
	//vector<people> peoples;
	string name, birth;
	people youngest("", thatYear, currMonth, currDay - 1);
	people oldest("", currYear, currMonth, currDay + 1);
	while (N--) {
		cin >> name >> birth;
		people peo(name, birth);
		if (peo.isTrue) {
			if (isOlder(oldest, peo))
				oldest = peo;
			if (isYounger(youngest, peo))
				youngest = peo;
			count++;
		}
	}
	if (count == 0)
		cout << count;
	else {
		cout << count << " ";
		cout << oldest.name << " " << youngest.name;
	}

	return 0;
}
