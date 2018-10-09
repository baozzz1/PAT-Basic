#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
void Callatz(set<int> &covered, const int &input) {
	int x = input;
	while (x != 1) {
		if (x & 1)
			x = (3 * x + 1) / 2;
		else
			x /= 2;
		covered.insert(x);
	}
}
void P1005() {
	unsigned num;
	if (cin >> num && num > 0 && num < 100) {
		vector<int> vec;
		int word;
		while (num-- && cin >> word)
			vec.push_back(word);
		set<int> covered;
		vector<int> res;
		for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter)
			Callatz(covered, *iter);
		for (auto iter1 = vec.cbegin(); iter1 != vec.cend(); ++iter1)
			if (covered.find(*iter1) == covered.cend())
				res.push_back(*iter1);
		sort(res.begin(), res.end(), [](const int &a, const int &b) {return a > b; });
		for (auto i = 0; i < res.size() - 1; i++)
			cout << res[i] << " ";
		cout << res[res.size() - 1];
	}

}