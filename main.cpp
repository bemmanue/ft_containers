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
	ft::vector<int> a(b);
	std::cout << a.max_size();
//	for (int i = 0; i < a.size(); ++i) {
//		std::cout << a.at(i) << std::endl;
//	}
	return 0;
}
