#include <iostream>
#include <vector>
#include "vector/vector.hpp"

int main()
{
	ft::vector<int> b(5);
	b[0] = 1;
	b[1] = 5;
	b[2] = 2;
	b[3] = 3;
	b[4] = 4;
	std::cout << b.empty() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << b.max_size() << std::endl;

	std::vector<int> e(5);
	e[0] = 1;
	e[1] = 5;
	e[2] = 2;
	e[3] = 3;
	e[4] = 4;
	std::cout << e.empty() << std::endl;
	std::cout << e.size() << std::endl;
	std::cout << e.max_size() << std::endl;

//	h = e.begin();
//	h += 3;
//	std::cout << *h << std::endl;
//
//	h = e.begin();
//	h + 3;
//	std::cout << *h << std::endl;
//
//	h = e.end();
//	h -= 3;
//	std::cout << *h << std::endl;
//
//	h = e.end();
//	h - 3;
//	std::cout << *h << std::endl;

}
