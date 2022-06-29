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
//	ft::vector<int> a(b);
//	std::cout << a.max_size();
//	for (int i = 0; i < a.size(); ++i) {
//		std::cout << a.at(i) << std::endl;
//	}
//std::vector<int> n;
//n.get_allocator();
	ft::vector<int> a(5);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	a.get_allocator();
//	a.reserve(13);
//	std::cout << *a.begin() << std::endl;
//	a.insert(a.begin() + 2, a.begin(), a.begin() + 2);
//	for (int i = 0; i < a.size(); ++i) {
//		std::cout << a.at(i) << std::endl;
//	}
//	std::cout << "capasity = " << a.capacity() << std::endl;
//
//	std::vector<int> b(5);
//	b[0] = 1;
//	b[1] = 2;
//	b[2] = 3;
//	b[3] = 4;
//	b[4] = 5;
//	b.reserve(13);
//	std::cout << *(b.begin()) << std::endl;
//	b.insert(b.begin() + 2, b.begin(), b.begin() + 2);
//	for (int i = 0; i < b.size(); ++i) {
//		std::cout << b.at(i) << std::endl;
//	}
//	std::cout << "capasity = " << b.capacity() << std::endl;

	return 0;
}
