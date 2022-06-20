#include <iostream>
#include <string.h>

// string class
class MyString {
	// 문자열이 저장된 공간을 가리키는 포인터
	char* string_content;
	// 문자열 데이터의 길이
	int string_length;
public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();
	int length() const;
	void print();
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
};
MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
}
MyString::MyString(const char* str) {
	string_length = strlen(str);
	string_content = new char[string_length + 1];
	for (int i = 0; i < string_length; i++)
	{
		string_content[i] = str[i];
	}
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length + 1];
	for (int i = 0; i < string_length; i++)
	{
		string_content[i] = str.string_content[i];
	}
}
MyString::~MyString() {
	delete[] string_content;
}
int MyString::length() const {
	return string_length;
}
void MyString::print() {
	for (int i = 0; i < string_length; i++)
	{
		std::cout << string_content[i];
	}
}
MyString& MyString::assign(const MyString& str) {

}
MyString& MyString::assign(const char* str) {

}
int main() {
	MyString str1("Hello world!");
	MyString str2(str1);
	str1.print();
	str2.print();
	return 0;
}