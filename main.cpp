#include <iostream>
#include <vector>
#include "vector/vector.hpp"

int main()
{
//	ft::vector<int> b(5);
//	b[0] = 1;
//	b[1] = 5;
//	b[2] = 2;
//	b[3] = 3;
//	b[4] = 4;
//	b.insert(b.begin() + 1, 1, 9);
//	for (int i = 0; i < b.size(); i++)  {
//		std::cout << b[i] << std::endl;
//	}
//	std::cout << '-' << std::endl;
//	std::cout << b.size() << std::endl;
//	std::cout << b.capacity() << std::endl;

	std::vector<int> b(5);
	b[0] = 1;
	b[1] = 5;
	b[2] = 2;
	b[3] = 3;
//	b[4] = 4;
	b.reserve(7);
//	b.insert(b.end(), 1, 9);
//	for (int i = 0; i < b.size(); i++)  {
//		std::cout << b[i] << std::endl;
//	}
	std::cout << '-' << std::endl;
	std::cout << *(b.end() - 1) << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << b.capacity() << std::endl;
	return 0;
}
