#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

bool isprime(const int &n) {	//����1��ʾ�ж�Ϊ������0Ϊ���������ڴ�û�н��������쳣���	
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

	//�˴���ѭ�����ܳ�ʱ�������
	//1. Nֵ����ѭ����ѯstudents�������׳�ʱ���Ľ�����map���ѧ������
	//2. Kֵ���ظ��������ݹ���ѭ����ѯisChecked�������׳�ʱ���Ľ�����map��Ų�ѯ�������ݣ�����out_of_range�������
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