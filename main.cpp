#include <iostream>
#include <vector>
#include "vector/vector.hpp"

int main()
{
	ft::vector<int> a(5);
	a[0] = 1;
	a[1] = 5;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;
	ft::vector<int>::iterator i = a.begin();
	std::cout << a.front() << std::endl;
	std::cout << *i << std::endl;

//	std::vector<int> e(5);
//	e[0] = 1;
//	e[1] = 5;
//	e[2] = 2;
//	e[3] = 3;
//	e[4] = 4;
//	std::vector<int>::iterator h = e.begin();
//	std::cout << *h << std::endl;
//
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
