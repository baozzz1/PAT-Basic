#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int P1023() {
	vector<int> vec;
	int word;
	for (int i = 0; i < 10 && cin>>word; i++){
		for (int j = 0; j < word; j++) {
			vec.push_back(i);
		}
	}
	sort(vec.begin(), vec.end());
	auto iter = find_if(vec.begin(), vec.end(), [](const int &n) {return n != 0; });
	int temp = *vec.begin();
	*vec.begin() = *iter;
	*iter = temp;
	for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter) {
		cout << *iter;
	}
	return 0;
}