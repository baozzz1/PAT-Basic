#include<iostream>
#include<string>
#include<set>
#include<list>
#include<algorithm>
using namespace std;

int P1029() {
	string actul_str, input_str;
	cin >> actul_str >> input_str;
	//std中toupper的原型为一个二元函数，所以使用std::toupper会报错：unresolved overloaded function
	//因此使用函数指针
	transform(actul_str.begin(), actul_str.end(), actul_str.begin(), (int(*)(int))toupper);
	transform(input_str.begin(), input_str.end(), input_str.begin(), (int(*)(int))toupper);
	set<char> actulText;
	set<char> inputText;
	for (auto iter = actul_str.begin(); iter != actul_str.end(); iter++) {
		actulText.insert(*iter);
	}
	for (auto iter = input_str.begin(); iter != input_str.end(); iter++) {
		inputText.insert(*iter);
	}
	list<char> resText(actulText.size()- inputText.size());
	string resText_sorted;
	set_difference(actulText.begin(), actulText.end(), inputText.begin(), inputText.end(), resText.begin());
	for (int i = 0; i < actul_str.size(); i++) {
		auto iter = find(resText.cbegin(), resText.cend(), actul_str[i]);
		if (iter != resText.cend()) {
			resText_sorted.push_back(*iter);
			resText.erase(iter);
		}
		if (resText.begin() == resText.end())
			break;
	}
	cout << resText_sorted;

	return 0;
}
