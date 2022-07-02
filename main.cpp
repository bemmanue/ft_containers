#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include "vector/vector.hpp"

int main() {

	std::map<std::string, int> a;
	int x = a["Yulya"];
	std::cout << x << std::endl;

	int y = a["Yulya"];
	a["Kuliyulya"] = 7;

//	int y = a["Yulya"];
//	a["Kuliyulya"] = 9;

	return 0;
}
