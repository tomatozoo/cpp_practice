#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

class string {
	char* str;
	int len;
public:
	string(char c, int n);
	string(const char* s);
	string(const string& s);
	~string();

	void add_string(const string& s);
	void copy_string(const string& s);
	int strlen(); 
	void print_string();
};
// 문자 c가 n개 있는 문자열
string::string(char c, int n) {
	str = new char[n + 1];
	for (int i = 0; i < n; i++)
	{
		*str = c;
		str++;
	}
	len = n;
}
// 문자열 s
string::string(const char* s) {
	len = 0;
	while (s[len] != '\0') {
		len++;
	}
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = *s;
		s++;
	}
}
// string copy constructor
string::string(const string& s) {
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = *(s.str+i);
	}
}
// deconstructor
string::~string() {
	if (str) delete[] str;
}
void string::add_string(const string& s){
	str = new char[s.len + len];
	for (int i = 0; i < s.len; i++)
	{
		str[i + len] = s.str[i];
	}
	/*char* tmp = new char[len + s.len + 1];
	for (int i = 0; i < len; i++) {
		tmp[i] = str[i];
	}
	for (int i = 0; i < s.len; i++) {
		tmp[i + len] = s.str[i];
	}
	string tmp_str(tmp);
	copy_string(tmp_str);*/
}
void string::copy_string(const string& s){
	len = s.len;
	str = new char[s.len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = s.str[i];
	}
}
int string::strlen(){
	std::cout << len << std::endl;
	return len;
}
void string::print_string() {
	for (int i = 0; i < len; i++)
	{
		std::cout << str[i] << std::endl;
	}
}


int maaaain() {
	string strr("abcde");
	strr.print_string();
	strr.strlen();
	strr.copy_string("123456789");
	strr.print_string();
	strr.strlen();
	strr.add_string("fg");
	strr.print_string();

	/*
	strr.copy_string("12345");
	strr.print_string();
	strr.strlen();


	strr.add_string("fg");
	strr.print_string();
	*/
	return 0;
}

