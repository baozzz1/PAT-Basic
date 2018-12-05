#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool isPrime(int n) {	//返回1表示判断为质数，0为非质数，在此没有进行输入异常检测	
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
void P1007() {
	unsigned num;
	unsigned count = 0;
	if (cin >> num && num > 0 && num < 1e5) {
		vector<int> prime = { 2 };
		for (int i = 3; i <= num; i+=2) {
			if (isPrime(i))
				prime.push_back(i);
		}
		for (auto index = 0; index < prime.size() - 1; index++)
			if (prime[index + 1] - prime[index] == 2)count++;
		cout << count;
	}
}