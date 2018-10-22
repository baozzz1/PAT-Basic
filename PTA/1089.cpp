#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1089() {
	int N, num;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++)
		cin >> vec[i];

	//遍历2只狼
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			vector<int> people(N, 1);
			vector<int> lier;
			people[i] = people[j] = -1;	//是狼人
			for (int k = 0; k < N; k++) {
				//若说的话指的对象是普通人（+1），但断言指的对象是狼人，则此人说谎;
				//若说的话指的对象是狼人（-1），但断言指的对象是普通人，则此人说谎;
				if (people[abs(vec[k]) - 1] * vec[k] < 0)
					lier.push_back(k);
			}
			if (lier.size() == 2 && people[lier[0]] * people[lier[1]] < 0) {
				cout << i + 1 << " " << j + 1 << endl;
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
	return 0;
}