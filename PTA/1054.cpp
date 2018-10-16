#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

//最后一个测试点过不去，因为把“432.”这样小数点在最后的情况考虑为非法了，应该删去此判断条件
int P1054() {
	int N;
	cin >> N;

	//结果变量
	int K = 0;
	double sum = 0.0;

	//中间变量
	double num;
	string numStr;
	bool flag = true;
	while (N--) {
		flag = true;
		cin >> numStr;
		//输入合法判断1：是否属于数字符号
		int pointIndex = 0;
		int i = 0;
		if (numStr[0] == '-'){
			i = 1;
			if (numStr.size() == 1) {
				flag = false;
				continue;
			}
		}
		for (; i < numStr.size() && flag; i++) {
			//若输入不为0~9的数字、小数点、负号或正号的，判断为非法
			if (!((numStr[i] >= '0' && numStr[i] <= '9')|| numStr[i] == '.')) {
				flag = false;
				continue;
			}
			if (numStr[i] == '.') {
				//若有多个小数点、小数点在首位或末尾的情况，判断为非法
				if (pointIndex != 0 || i == 0 /*|| i == numStr.size() - 1*/) {
					flag = false;
					continue;
				}
				//若小数点不在首位，但前面不是数字，则判断为非法
				if (!(numStr[i - 1] >= '0' && numStr[i - 1] <= '9')) {
					flag = false;
					continue;
				}
				pointIndex = i;
			}
			//若精确位数大于小数点后2位，判断为非法
			if (pointIndex != 0 && i - pointIndex > 2) {
				flag = false;
				continue;
			}
		}
		//输入合法判断2：是否在-1000~1000范围内
		if (flag) {
			stringstream ss(numStr);
			ss >> num;
			if (num<-1000.00 || num>1000.00)
				flag = false;
		}

		if (flag) {
			sum += num;
			K++;
		}
		else {
			cout << "ERROR: " << numStr << " is not a legal number" << endl;
		}

	}
	if (K == 1) {
		printf("The average of 1 number is %.2f", sum);
	}
	else if (K == 0) {
		cout << "The average of 0 numbers is Undefined";
	}
	else {
		printf("The average of %d numbers is %.2f", K, (double)sum/(double)K);
	}
	return 0;
}