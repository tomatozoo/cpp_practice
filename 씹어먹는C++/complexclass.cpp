#include <cstring>
#include <iostream>

class Complex {
private:
	double real, img;
	double get_number(const char* str, int from, int to);
public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);

	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);

	Complex operator+(const char* str);
	Complex operator-(const char* str);
	Complex operator*(const char* str);
	Complex operator/(const char* str);

	Complex& operator=(const Complex& c);

	void println() { std::cout << real << "+" << img << "i" << std::endl; }
};

double Complex::get_number(const char* str, int from, int to) {
	bool minus = false;
	if (from > to) return 0;
	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;

	double num = 0.0;
	double decimal = 1.0;
	bool integer_part = true;
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			integer_part = false;
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else
			break;
	}

	if (minus) num *= -1.0;

	return num;

}
Complex::Complex(const char* str) {
	// 문자열 분석을 통해 real / img 부분 나누기
	// 나누어서 complex real, img 변수에 저장하기

	// 초기화
	int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;

	// i의 index를 찾아보자
	int pos_i = -1;
	for (int i = 0; i < end; i++)
	{
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}
	// i 가 없으면 실수 뿐
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}

	// i가 있다면
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end-1);

	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

Complex Complex::operator+(const char* str) {
	Complex temp(str);
	return (*this) + temp;
}
Complex Complex::operator-(const char* str) {
	Complex temp(str);
	return (*this) - temp;
}
Complex Complex::operator*(const char* str) {
	Complex temp(str);
	return (*this) * temp;
}
Complex Complex::operator/(const char* str) {
	Complex temp(str);
	return (*this) / temp;
}
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real*c.real - img*c.img, real*c.img+img*c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real*c.real + img * c.img)/(c.real * c.real+c.img*c.img),
		(img * c.real-real*c.img)/(c.real*c.real+c.img*c.img)
	);
	return temp;
}
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}

int main() {
	Complex a(1.0, 2.0);
	a.println();
	a = a + "-1.1+i3.923";
	a.println();
	return 0;
}