#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Sales_item {
	Sales_item() {}
	double total_price;
	double all_numbers;
	double avg_price;
};
int P1020() {
	int N, D;
	double stock, total_price;
	cin >> N >> D;
	vector<Sales_item> items(N);
	for (int i = 0; i < N && cin >> stock;i++) {
		items[i].all_numbers = stock;
	}
	for (int i = 0; i < N && cin >> total_price; i++) {
		items[i].total_price = total_price;
		items[i].avg_price = total_price / items[i].all_numbers;
	}
	double total_get = 0.0;
	sort(items.begin(), items.end(), [](const Sales_item &it1, const Sales_item &it2) {return it1.avg_price > it2.avg_price; });
	for (int i = 0; i < N; i++) {
		if (items[i].all_numbers <= D) {
			total_get += items[i].total_price;
			D -= items[i].all_numbers;
		}
		else {
			total_get += items[i].avg_price*D;
			break;
		}
	}
	printf("%.2f", total_get);

	return 0;
}