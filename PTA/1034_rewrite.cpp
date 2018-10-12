#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<tuple>
using namespace std;

//查找两数的最大公约数
long long findGcd(const long long &num1, const long long &num2) {
	if (num2 == 0)
		return num1;
	else
		return findGcd(num2, num1%num2);
	//long long t = (num1 > num2) ? num2 : num1;
	//while (!(num1%t == 0 && num2 % t == 0))
	//	t--;
	//return t;
}
class fraction {
public:
	fraction() {}
	fraction(const string&);
	fraction(const long long &num, const long long &den) :input_numerator(num), input_denominator(den) {}
	fraction& operator+(const fraction&);
	fraction& operator-(const fraction&);
	fraction& operator*(const fraction&);
	fraction& operator/(const fraction&);
	const bool signFlag()const
	{
		return (input_numerator < 0) ? false : true;
	}
	const tuple<long long, long long, long long> getVulgarFraction()const;

private:
	//假分数表示时的分子部分
	long long  input_numerator;
	//假分数表示时的分母部分,该值可以为1
	long long input_denominator;
};
const void print(const fraction &frac) {
	if (!frac.signFlag())
		cout << "(-";
	auto printItem = frac.getVulgarFraction();
	if (get<0>(printItem) != 0) {
		cout << get<0>(printItem);
		if (get<1>(printItem) != 0)
			cout << " ";
	}
	if (get<0>(printItem) == 0 && get<1>(printItem) == 0)
		cout << "0";
	if (get<1>(printItem) != 0)
		cout << get<1>(printItem) << '/' << get<2>(printItem);
	if (!frac.signFlag())
		cout << ")";

}
fraction::fraction(const string &s) {
	auto iter = s.cbegin();
	string numerator_str, denominator_str;
	for (; iter != s.cend() && *iter != '/'; ++iter)
		numerator_str.push_back(*iter);
	++iter;
	for (; iter != s.cend(); ++iter)
		denominator_str.push_back(*iter);

	stringstream numerator_stream(numerator_str);
	stringstream denominator_stream(denominator_str);
	numerator_stream >> input_numerator;
	denominator_stream >> input_denominator;
}
const tuple<long long, long long, long long> fraction::getVulgarFraction()const {
	long long vulgar_fraction_numerator = abs(input_numerator);
	if (vulgar_fraction_numerator == 0)
		return make_tuple(0, 0, 0);
	auto maxGcd = findGcd(vulgar_fraction_numerator, input_denominator);
	vulgar_fraction_numerator /= maxGcd;
	long long vulgar_fraction_denominator = input_denominator / maxGcd;
	if (vulgar_fraction_denominator == 1)	//整数的情况
		return make_tuple(vulgar_fraction_numerator, 0, 0);
	if (vulgar_fraction_numerator < vulgar_fraction_denominator)
		return make_tuple(0, vulgar_fraction_numerator, vulgar_fraction_denominator);
	else
		return make_tuple(vulgar_fraction_numerator / vulgar_fraction_denominator, vulgar_fraction_numerator%vulgar_fraction_denominator, vulgar_fraction_denominator);
	return make_tuple(0, 0, 0);
}
fraction& fraction::operator+(const fraction &frac2) {
	auto common_divisor_of_denominator = findGcd(this->input_denominator, frac2.input_denominator);
	long long numerator_total = this->input_numerator * frac2.input_denominator / common_divisor_of_denominator + frac2.input_numerator * this->input_denominator / common_divisor_of_denominator;
	long long denominator_total = this->input_denominator * frac2.input_denominator / common_divisor_of_denominator;
	fraction result(numerator_total, denominator_total);
	print(*this);
	cout << " + ";
	print(frac2);
	cout << " = ";
	print(result);
	cout << endl;
	return result;
}
fraction& fraction::operator-(const fraction &frac2) {
	auto common_divisor_of_denominator = findGcd(this->input_denominator, frac2.input_denominator);
	long long numerator_total = this->input_numerator * frac2.input_denominator / common_divisor_of_denominator - frac2.input_numerator * this->input_denominator / common_divisor_of_denominator;
	long long denominator_total = this->input_denominator * frac2.input_denominator / common_divisor_of_denominator;
	fraction result(numerator_total, denominator_total);
	print(*this);
	cout << " - ";
	print(frac2);
	cout << " = ";
	print(result);
	cout << endl;
	return result;
}
fraction& fraction::operator*(const fraction &frac2) {
	long long numerator_total = this->input_numerator * frac2.input_numerator;
	long long denominator_total = this->input_denominator * frac2.input_denominator;
	//long long common_divisor = findGcd(numerator_total, denominator_total);
	fraction result(numerator_total, denominator_total);
	print(*this);
	cout << " * ";
	print(frac2);
	cout << " = ";
	print(result);
	cout << endl;
	return result;
}
fraction& fraction::operator/(const fraction &frac2) {
	long long numerator_total = this->input_numerator * frac2.input_denominator *(frac2.signFlag() ? 1 : -1);
	long long denominator_total = this->input_denominator * frac2.input_numerator*(frac2.signFlag() ? 1 : -1);
	//long long common_divisor = findGcd(numerator_total, denominator_total);
	fraction result(numerator_total, denominator_total);
	print(*this);
	cout << " / ";
	print(frac2);
	cout << " = ";
	if (frac2.input_numerator == 0) {
		cout << "Inf" << endl;
		return *this;
	}
	else {
		print(result);
		cout << endl;
		return result;
	}
}
int	P1034_rewrite() {
	string num1_str, num2_str;
	cin >> num1_str >> num2_str;
	fraction num1(num1_str);
	fraction num2(num2_str);
	num1 + num2;
	num1 - num2;
	num1 * num2;
	num1 / num2;
	return 0;
}

