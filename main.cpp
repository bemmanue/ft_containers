#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	std::vector<int> q;
	std::vector<int> e(5);
	e[0] = 1;
	e[1] = 5;
	e[2] = 2;
	e[3] = 3;
	e[4] = 4;

	ft::vector<int> a(5);
	a[0] = 1;
	a[1] = 5;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;

//	std::cout << e.at(5) << std::endl;
//	try {
		std::cout << e.back() << std::endl;
		std::cout << e.back() << std::endl;
//	}
//	catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
}
