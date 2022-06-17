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
	b.insert(b.begin(), 1, 7);
	for (int i = 0; i < b.size(); i++)  {
		std::cout << b[i] << std::endl;
	}
	std::cout << "-\n" << b.size() << std::endl;
	std::cout << b.capacity() << std::endl;
//
//	std::cout << b.size() << std::endl;
//	std::cout << b.capacity() << std::endl;

//	std::cout << *(v.end() - 1) << std::endl;
//	std::cout << v.size() << std::endl;
//	std::cout << v.capacity() << std::endl;
//	for (int i = 0; i < b.size(); i++)  {
//		std::cout << b[i] << std::endl;
//	}

//	std::vector<int> e(5);
//	e[0] = 1;
//	e[1] = 5;
//	e[2] = 2;
//	e[3] = 3;
//	e[4] = 4;
//	e.insert(e.end(), 1, 0);
	//	std::vector<int>::iterator q = e.begin() + 10;
//	e.insert(q, 9);
//	e.clear();
//	for (int i = 0; i < e.size(); i++)  {
//		std::cout << e[i] << std::endl;
//	}
//	std::cout << e.size() << std::endl;
//	std::cout << e.capacity() << std::endl;

return 0;
}
