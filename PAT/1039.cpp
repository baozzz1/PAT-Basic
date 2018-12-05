#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int P1039() {
	string sold, wanted;
	getline(cin, sold);
	getline(cin, wanted);
	if (wanted.size() == 0) {
		cout << "Yes " << sold.size();
		return 0;
	}
	else if (sold.size() == 0) {
		cout << "No " << wanted.size();
		return 0;
	}

	map<char, int> soldMap, wantedMap;
	for (auto iter = sold.begin(); iter != sold.end(); ++iter)
		soldMap[*iter]++;
	for (auto iter = wanted.begin(); iter != wanted.end(); ++iter)
		wantedMap[*iter]++;

	bool flag = true;	//true:¿ÉÂò; false:²»¿ÉÂò
	int moreCount = 0, lessCount = 0;
	for (auto iter = wantedMap.begin(); iter != wantedMap.end(); ++iter) {
		if (iter->second > soldMap[iter->first]) {
			flag = false;
			lessCount += iter->second - soldMap[iter->first];
		}
		else
			moreCount += soldMap[iter->first] - iter->second;
		soldMap[iter->first] = 0;
	}
	if (flag) {
		for (auto iter = soldMap.begin(); iter != soldMap.end(); ++iter)
			if (iter->second != 0)
				moreCount += iter->second;
		cout << "Yes " << moreCount;
	}
	else
		cout << "No " << lessCount;

	return 0;
}