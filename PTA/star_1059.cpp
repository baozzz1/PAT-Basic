#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

bool isprime(const int &n) {	//返回1表示判断为质数，0为非质数，在此没有进行输入异常检测	
	float n_sqrt;
	if (n == 2 || n == 3)
		return true;
	if (n % 6 != 1 && n % 6 != 5)
		return false;
	n_sqrt = floor(sqrt((float)n));
	for (int i = 5; i <= n_sqrt; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}

string getPrice(const int &rank) {
	if (rank == 1)
		return "Mystery Award";
	else if (isprime(rank))
		return "Minion";
	else
		return "Chocolate";
}

int P1059() {
	//Input
	int N, K;
	cin >> N;
	// ID,level
	map<string, int> students;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		students[name] = i + 1;
	}

	cin >> K;
	string searchID;
	map<string, bool> isChecked;
	vector<string> searches(K), resPrint(K);

	//此处的循环可能超时的情况：
	//1. N值过大，循环查询students数组容易超时；改进：用map存放学生数据
	//2. K值中重复检查的数据过大，循环查询isChecked数组容易超时；改进：用map存放查询过的数据，并用out_of_range跳出检查
	for (int i = 0; i < K; i++) {
		cin >> searchID;
		searches[i] = searchID;
		try {
			if (isChecked.at(searchID) == true) {
				resPrint[i] = "Checked";
				continue;
			}
		}
		catch (out_of_range) {
			try {
				resPrint[i] = getPrice(students.at(searchID));
				isChecked[searchID] = true;
			}catch (out_of_range) {
				resPrint[i] = "Are you kidding?";
			}
		}

	}

	for (int i = 0; i < K; i++)
		cout << searches[i] << ": " << resPrint[i] << endl;


	return 0;
}