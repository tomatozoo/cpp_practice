#include <iostream>
#include <string.h>

// string class
class MyString {
	// 문자열이 저장된 공간을 가리키는 포인터
	char* string_content;
	// 문자열 데이터의 길이
	int string_length;
	// 현재 할당된 용량
	int memory_capacity;
public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();

	int length() const;
	int capacity() const;
	void reserve(int size);

	void print();

	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	char at(int i) const;

	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);

	MyString& erase(int loc, int num);

	int find(int find_from, const MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	int compare(const MyString& str) const;
};
MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
	memory_capacity = 1;
}
MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length + 1];
	for (int i = 0; i < string_length; i++)
	{
		string_content[i] = str[i];
	}
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	memory_capacity = str.string_length;
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
	if (str.string_length > memory_capacity) {
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i < str.string_length; i++)
	{
		string_content[i] = str.string_content[i];
	}
	string_length = str.string_length;
	return *this;
}
MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		delete[] string_content;
		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i < str_length; i++)
	{
		string_content[i] = str[i];
	}
	string_length = str_length;
	return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;
		string_content = new char[size];
		memory_capacity = size;
		for (int i = 0; i < string_length; i++)
		{
			string_content[i] = prev_string_content[i];
		}
		delete[] prev_string_content;
	}
}
char MyString::at(int i) const {
	if (i >= string_length || i < 0) return NULL;
	else {
		return string_content[i];
	}
}

MyString& MyString::insert(int loc, const MyString& str){
	// i 위치 바로 앞에 문자를 삽입하기
	// 안해도 되는 케이스들
	if (loc < 0 || loc > string_length) return *this;
	// 새롭게 동적 할당해야 하는 경우 
	if (string_length + str.string_length > memory_capacity) {
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		// 일단 insert 되는 부분 직전까지 내용을 복사한다. 
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}
		// 새롭게 insert 되는 문자열을 삽입한다. 
	}
	// 안해도 되는 경우
	return *this;

}
MyString& MyString::insert(int loc, const char* str) {}
MyString& MyString::insert(int loc, char c) {}

MyString& MyString::erase(int loc, int num) {}

int MyString::find(int find_from, const MyString& str) const {}
int MyString::find(int find_from, const char* str) const {}
int MyString::find(int find_from, char c) const {}

int MyString::compare(const MyString& str) const {}

int main() {
	MyString str1("very very long string");
	str1.reserve(30);
	std::cout << "capacity : " << str1.capacity() << std::endl;
	std::cout << "length : " << str1.length() << std::endl;

	return 0;
}