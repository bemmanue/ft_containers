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
	ft::vector<int>::iterator a = b.begin();
	ft::vector<int>::iterator c = b.end();

	ft::vector<int> d(a, c);
	return 0;
}
