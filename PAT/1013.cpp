#include<iostream>
#include<vector>
#include<math.h>
#include<memory>
using namespace std;
bool isprime(int n) {	//返回1表示判断为质数，0为非质数，在此没有进行输入异常检测	
	float n_sqrt;
	if (n == 2 || n == 3)
		return true;
	if (n % 6 != 1 && n % 6 != 5)
		return false;
	n_sqrt = floor(sqrt((float)n));
	for (int i = 5; i <= n_sqrt; i += 6) {
		if (n % i == 0 | n % (i + 2) == 0)
			return false;
	}
	return true;
}
void print(const vector<int> &vec) {
	for (int i = 0; i < vec.size() - 1; i++) {
		cout << vec[i];
		if ((i + 1) % 10 == 0)
			cout << endl;
		else
			cout << " ";
	}
	cout << vec[vec.size() - 1];
}
void P1013() {
	int M, N;
	cin >> M >> N;
	vector<int> prime = { 2 };
	int i = 3;
	while (true) {
		if (isprime(i))
			prime.push_back(i);
		if (prime.size() >= N)
			break;
		i += 2;
	}
	vector<int> res;
	for (int i = M - 1; i < N; i++)
		res.push_back(prime[i]);
	print(res);
}