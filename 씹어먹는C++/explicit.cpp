#include <iostream>
class MString {
	char* string_content;
	int string_length;
	int memory_capacity;
public:
	explicit MString(int capacity);
	MString(const char* str);
	MString(const MString& str);
	~MString();
	int length() const;
};
MString::MString(int capacity) {
	string_content = new char[capacity];
	string_length = 0;
	memory_capacity = capacity;
	std::cout << "capacity : " << memory_capacity << std::endl;
}
MString::MString(const char* str){
	string_length = 0;
	while (str[string_length++]) {

	}
	string_content = new char[string_length];
	memory_capacity = string_length;
	for (int i = 0; i < string_length; i++)
	{
		string_content[i] = str[i];
	}
	std::cout << "capacity : " << memory_capacity << std::endl;

}
MString::MString(const MString& str){
	string_length = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i < string_length; i++)
	{
		string_content[i] = str.string_content[i];
	}
	memory_capacity = string_length;
	std::cout << "capacity : " << memory_capacity << std::endl;

}
MString::~MString(){
	delete[] string_content;
}
int MString::length() const{
	return string_length;
}
void DoSomthingWithString(MString s) {
	return;
}
int ma1in() {
	MString s(3);
	DoSomthingWithString(MString("abc"));
	DoSomthingWithString("abc");
	return 0;
}