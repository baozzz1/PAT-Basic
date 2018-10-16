#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

//���һ�����Ե����ȥ����Ϊ�ѡ�432.������С�����������������Ϊ�Ƿ��ˣ�Ӧ��ɾȥ���ж�����
int P1054() {
	int N;
	cin >> N;

	//�������
	int K = 0;
	double sum = 0.0;

	//�м����
	double num;
	string numStr;
	bool flag = true;
	while (N--) {
		flag = true;
		cin >> numStr;
		//����Ϸ��ж�1���Ƿ��������ַ���
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
			//�����벻Ϊ0~9�����֡�С���㡢���Ż����ŵģ��ж�Ϊ�Ƿ�
			if (!((numStr[i] >= '0' && numStr[i] <= '9')|| numStr[i] == '.')) {
				flag = false;
				continue;
			}
			if (numStr[i] == '.') {
				//���ж��С���㡢С��������λ��ĩβ��������ж�Ϊ�Ƿ�
				if (pointIndex != 0 || i == 0 /*|| i == numStr.size() - 1*/) {
					flag = false;
					continue;
				}
				//��С���㲻����λ����ǰ�治�����֣����ж�Ϊ�Ƿ�
				if (!(numStr[i - 1] >= '0' && numStr[i - 1] <= '9')) {
					flag = false;
					continue;
				}
				pointIndex = i;
			}
			//����ȷλ������С�����2λ���ж�Ϊ�Ƿ�
			if (pointIndex != 0 && i - pointIndex > 2) {
				flag = false;
				continue;
			}
		}
		//����Ϸ��ж�2���Ƿ���-1000~1000��Χ��
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