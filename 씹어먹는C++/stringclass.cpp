#include <iostream>
class String
{
	char* str;
	int len;
public:
	String();
	String(char c, int n);
	String(const char* c);
	~String();
	String& addString(String& s);
	bool IsEqual(String& s);
	bool IsLonger(String& s);
	void PrintString();
private:

};
// 디폴트 생성자
String::String()
{
	str = NULL;
	len = 0;
}
// char로부터 문자열 생성
String::String(char c, int n) {
	len = n;
	str = new char[n+1];
	for (int i = 0; i < len; i++)
	{
		str[i] = c;
	}
}
// string으로부터 문자열 생성
String::String(const char* c) {
	len = 0;
	// len 구하기
	while (1) {
		if (*c != '\0') {
			len++;
			c++;
		}
		else {
			break;
		}
	}
	for (int i = 0; i < len; i++)
	{
		c--;
	}
	// str 구하기
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = *c;
		c++;
	}
}
String& String::addString(String& s) {
	str = new char[len + s.len];
	for (int i = 0; i < s.len; i++)
	{
		str[i + len] = s.str[i];
	}
	return *this;
}
bool String::IsEqual(String& s) {
	if (len != s.len) return false;
	else {
		for (int i = 0; i < len; i++)
		{
			if (str[i] != s.str[i]) return false;
		}
		return true;
	}
}
bool String::IsLonger(String& s) {
	if (len > s.len) {
		return true;
	}
	else {
		return false;
	}
}
void String::PrintString() {
	for (int i = 0; i < len; i++)
	{
		std::cout << str[i] << std::endl;
	}
	return;
}
String::~String()
{
	delete[] str;
}
int m1ain() {
	String string1('c', 5);
	const char* c = "abcdefg";
	String string2(c);
	string1.PrintString();
	string2.PrintString();
	string1.addString(string2);
	string1.PrintString();
	return 0;
}