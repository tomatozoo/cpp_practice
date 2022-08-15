#include <iostream>
#include <string>
#include <vector>
#include <stack>

//
int mai_9012() {
	int size;
	std::cin >> size;

	std::vector<std::string> v;

	for (int i = 0; i < size; i++) {
		std::stack<std::string> st;
		bool done=false;
		std::string tmp;
		std::cin >> tmp;

		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == '(') {
				st.push("(");
			}
			else {
				if (st.size() == 0) {
					v.push_back("NO");
					done = true;
					break;
				}
				else {
					st.pop();
				}
			}
		}

		if (done) {
			continue;
		}
		else {
			if (st.size() == 0) {
				v.push_back("YES");
			}
			else {
				v.push_back("NO");
			}
		}
	
	}
	std::vector<std::string>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << std::endl;
	}
	return 0;
}