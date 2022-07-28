#include <iostream>
#include <string>

// 타입 이름을 넣으면 코드를 내보내준다
template <typename T>
class Vector {
	T* data;
	int capacity;
	int length;
public:
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

	void push_back(T s) {
		if (capacity <= length) {
			T* temp = new T[capacity * 2];
			for (int i = 0; i < length; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}
		data[length] = s;
		length++;
	}
	T operator[](int i) { return data[i]; }

	void remove(int x) {
		for (int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}

	int size() { return length; }
	
	~Vector() {
		if (data) {
			delete[] data;
		}
	}

};

int masin() {
	Vector<int> int_vector;
	Vector<std::string> str_vector;

	int_vector.push_back(3);
	int_vector.push_back(1);

	std::cout << int_vector[0] << int_vector[1] << std::endl;
	
	str_vector.push_back("hi there");
	str_vector.push_back("im yongju");

	std::cout << str_vector[0] << str_vector[1] << std::endl;


	return 0;
}