//#include "test/test_map.cpp"
//#include "test/test_set.cpp"
//#include "test/test_stack.cpp"
//#include "test/test_vector.cpp"

#include "vector/vector.hpp"
#include <functional>

#include "utility/utility.hpp"
#include "map/map.hpp"


#include "set/set.hpp"
#include "stack/stack.hpp"
#include <list>

void	test_vector()
{
	char ch, carr[] = "abc";

	ft::vector<char>::allocator_type	*p_alloc	= (std::allocator<char> *)0;
	ft::vector<char>::pointer			p_ptr		= (char *)0;
	ft::vector<char>::const_pointer		p_cptr		= (const char *)0;
	ft::vector<char>::reference			p_ref		= ch;
	ft::vector<char>::const_reference	p_cref		= (const char&)ch;
	ft::vector<char>::value_type		*p_val		= (char *)0;
	ft::vector<char>::size_type			*p_size		= (size_t *)0;
	ft::vector<char>::difference_type	*p_diff		= (ptrdiff_t *)0;

	(void) p_cref;
	(void) p_val;
	(void) p_ptr;
	(void) p_diff;
	(void) p_size;
	(void) p_cptr;
	(void) p_alloc;
	(void) p_ref;

	ft::vector<char> v0;
	std::allocator<char> al = v0.get_allocator();

	ft::vector<char> v0a(al);

	assert(v0.empty() && v0.size() == 0);
	assert(v0a.size() == 0 && v0a.get_allocator() == al);

	ft::vector<char> v1(5);

	ft::vector<char> v1a(6, 'x');

	ft::vector<char> v1b(7, 'y', al);

	assert(v1.size() == 5);

	assert(v1.back() == '\0');

	assert(v1a.size() == 6 && v1a.back() == 'x');
	assert(v1b.size() == 7 && v1b.back() == 'y');

	ft::vector<char> v2(v1a);
	assert (v2.size() == 6 && v2.front() == 'x');

	ft::vector<char> v3(v1a.begin(), v1a.end());
	assert(v3.size() == 6 && v3.front() =='x');

	const ft::vector<char> v4 (v1a.begin(), v1a.end(), al);
	assert(v4.size() == 6 && v4.back() == 'x');

	v0 = v4;
	assert(v0.size() == 6 && v0.at(5) == 'x');
	assert(v0[0] == 'x' && v0.at(5) == 'x');

	v0.reserve(12);
	assert(12 <= v0.capacity());

	v0.resize(8);
	assert (v0.size() == 8);
	assert (v0.back() == '\0');

	v0.resize(10, 'z');
	assert(v0.size() == 10 && v0.back() == 'z');
	assert(v0.size() <= v0.max_size());

	ft::vector<char>::iterator		 			p_it(v0.begin());
	ft::vector<char>::const_iterator			p_cit(v4.begin());
	ft::vector<char>::reverse_iterator 			p_rit(v0.rbegin());
	ft::vector<char>::const_reverse_iterator 	p_crit(v4.rbegin());

	assert(*p_it == 'x' && *--(p_it = v0.end()) == 'z');
	assert(*p_cit == 'x' && *--(p_cit = v4.end()) == 'x');

	assert(*p_rit == 'z' && *--(p_rit = v0.rend()) == 'x');
	assert(*p_crit == 'x' && *--(p_crit = v4.rend()) == 'x');

	assert(v0.front() == 'x' && v4.front() == 'x');

	v0.push_back('a');
	assert(v0.back() == 'a');

	v0.pop_back();
	assert(v0.back() == 'z' && v4.back() == 'x');

	v0.assign(v4.begin(), v4.end());
	assert(v0.size() == v4.size());
	assert(v0.front() == v4.front());

	v0.assign(4, 'w');
	assert(v0.size() == 4 && v0.front() == 'w');

	/* Test insert*/
	assert(*v0.insert(v0.begin(), 'a') == 'a');
	assert(v0.front() == 'a' && *++v0.begin() == 'w');

	v0.insert(v0.begin(), 2, 'b');
	assert(v0.front() == 'b' && *++v0.begin() == 'b' && *(++(++v0.begin())) == 'a');

	v0.insert(v0.end(), v4.begin(), v4.end());
	assert(v0.back() == v4.back());

	v0.insert(v0.end(), carr, carr + 3);
	assert(v0.back() == 'c');

	v0.erase(v0.begin());
	assert(v0.front() == 'b' && *++v0.begin() == 'a');

	v0.erase(v0.begin(), ++v0.begin());
	assert(v0.front() == 'a');
	v0.clear();
	assert(v0.empty());

	v0.swap(v1);
	assert(!v0.empty() && v1.empty());

	assert(v1 == v1 && v0 > v1);
	assert(v0 != v1 && v1 < v0);
	assert(v0 >= v1 && v1 <= v0 && v1 >= v1 && v0 <= v0);

	ft::vector<ft::pair<int, char> > pair;

	pair.insert(pair.begin(), ft::make_pair(4, 'a'));

	ft::vector<ft::pair<int, char>, std::allocator<ft::pair<int, char> > >::iterator itp(pair.begin());
	assert(itp->first == 4 && itp->second == 'a');
}

void test_stack() {

	ft::stack<int> stack;
	ft::stack<int> stack1;

	typedef std::allocator<char>		Myal;
	typedef std::deque<char, Myal>		Myimpl;
	typedef ft::stack<char, Myimpl>		Mycont;
	typedef std::list<char, Myal>		Myimpl2;
	typedef ft::stack<char, Myimpl2>	Mycont2;
	typedef ft::vector<char, Myal>		Myimpl3;
	typedef ft::stack<char, Myimpl3>	Mycont3;

	Mycont::container_type	*p_cont	= (Myimpl *)0;
	Mycont::value_type		*p_val	= (char *)0;
	Mycont::size_type		*p_size	= (size_t *)0;

	Mycont	v0(Myimpl(3, 'x')), v0a;
	Mycont2	v1;
	Mycont3	v2;
	assert(v0.size() == 3 && v0.top() == 'x');
	assert(v0a.empty());

	v0 = v0a;
	v0.push('a');
	assert(v0.size() == 1 && v0.top() == 'a');
	v0.push('b');
	assert(v0.size() == 2 && v0.top() == 'b');
	v0.push('c');
	assert(v0.size() == 3 && v0.top() == 'c');
	assert(v0 == v0 && v0a < v0);
	assert(v0 != v0a && v0 > v0a);
	assert(v0a <= v0a && v0a >= v0a);
	v0.pop();
	assert(v0.top() == 'b');
	v0.pop();
	assert(v0.top() == 'a');
	v0.pop();
	assert(v0.empty());

	assert(stack1.empty());
	for (int i = 0; i < 30; i++)
		stack1.push(i);
	assert(!stack1.empty());
	assert(stack1.size() == 30);
}

void	test_map() {

	typedef std::less<char>						Mypred;
	typedef ft::pair<const char, int>			Myval;
	typedef std::allocator<Myval>				Myal;
	typedef ft::map<char, int, Mypred, Myal>	Mycont;


	Myval x, xarr[3], xarr2[3];

	for (int i = 0; i < 3; ++i)
	{
		new (&xarr[i])Myval('a' + i, 1 + i);
		new (&xarr2[i])Myval('d' + i, 4 + i);
	}

	Mycont::key_type		*p_key = (char *)0;
	Mycont::mapped_type		*p_mapped = (int *)0;
	Mycont::key_compare		*p_kcomp = (Mypred *)0;
	Mycont::allocator_type  *p_alloc = (Myal *)0;
	Mycont::value_type      *p_val = (Myval *)0;
	Mycont::value_compare	*p_vcomp = 0;
	Mycont::pointer			p_ptr = (Myval *)0;
	Mycont::const_pointer	p_cptr = (const Myval *)0;
	Mycont::reference		p_ref = x;
	Mycont::const_reference p_cref = (const Myval &)x;
	Mycont::size_type       *p_size = (size_t *)0;
	Mycont::difference_type *p_diff = (ptrdiff_t *)0;

	Mycont v0;
	Myal al = v0.get_allocator();
	Mypred pred;
	Mycont v0a(pred), v0b(pred, al);

	assert(v0.empty() && v0.size() == 0);
	assert(v0a.size() == 0 && v0a.get_allocator() == al);
	assert(v0b.size() == 0 && v0b.get_allocator() == al);

	Mycont v1(xarr, xarr + 3);
	assert(v1.size() == 3 && (*v1.begin()).first == 'a');

	Mycont v2(xarr, xarr + 3, pred);
	assert(v2.size() == 3 && (*v2.begin()).first == 'a');

	Mycont v3(xarr, xarr + 3, pred, al);
	assert(v3.size() == 3 && (*v3.begin()).first == 'a');

	const Mycont v4(xarr, xarr + 3);
	assert(v4.size() == 3 && (*v4.begin()).first == 'a');
	v0 = v4;
	assert(v0.size() == 3 && (*v0.begin()).first == 'a');

	assert(v0.size() <= v0.max_size());

	Mycont::iterator				p_it(v1.begin());
	Mycont::const_iterator			p_cit(v4.begin());
	Mycont::reverse_iterator		p_rit(v1.rbegin());
	Mycont::const_reverse_iterator	p_crit(v4.rbegin());

	assert((*p_it).first == 'a' && (*p_it).second == 1
		   && (*--(p_it = v1.end())).first == 'c');

	assert((*p_cit).first == 'a'
		   && (*--(p_cit = v4.end())).first == 'c');

	assert((*p_rit).first == 'c' && (*p_rit).second == 3
		   && (*--(p_rit = v1.rend())).first == 'a');

	assert((*p_crit).first == 'c'
		   && (*--(p_crit = v4.rend())).first == 'a');

	v0.clear();
	ft::pair<Mycont::iterator, bool> pib = v0.insert(Myval('d', 4));
	assert((*pib.first).first == 'd' && pib.second);
	assert((*--v0.end()).first == 'd');
	pib = v0.insert(Myval('d', 5));
	assert((*pib.first).first == 'd'
		   && (*pib.first).second == 4 && !pib.second);
	assert((*v0.insert(v0.begin(), Myval('e', 5))).first == 'e');

	v0.insert(xarr, xarr + 3);
	assert(v0.size() == 5 && (*v0.begin()).first == 'a');

	v0.insert(xarr2, xarr2 + 3);
	assert(v0.size() == 6 && (*--v0.end()).first == 'f');
	assert(v0['c'] == 3);

	assert((*v0.erase(v0.begin())).first == 'b'
		   && v0.size() == 5);
	assert((*v0.erase(v0.begin(), ++v0.begin())).first == 'c'
		   && v0.size() == 4);
	assert(v0.erase('x') == 0 && v0.erase('e') == 1);

	v0.clear();
	assert(v0.empty());
	v0.swap(v1);
	assert(!v0.empty() && v1.empty());
	ft::swap(v0, v1);
	assert(v0.empty() && !v1.empty());
	assert(v1 == v1 && v0 < v1);
	assert(v0 != v1 && v1 > v0);
	assert(v0 <= v1 && v1 >= v0);

	assert(v0.key_comp()('a', 'c') && !v0.key_comp()('a', 'a'));
	assert(v0.value_comp()(Myval ('a', 0), Myval('e', 0))
		   && !v0.value_comp()(Myval ('a', 0), Myval('a', 1)));
	assert((*v4.find('b')).first == 'b');
	assert(v4.count('x') == 0 && v4.count('b') == 1);
	assert((*v4.lower_bound('a')).first == 'a');
	assert((*v4.upper_bound('a')).first == 'b');
	ft::pair<Mycont::const_iterator, Mycont::const_iterator> pcc
			= v4.equal_range('a');
	assert((*pcc.first).first == 'a' && (*pcc.second).first == 'b');
}

void	test_set() {

	typedef std::allocator<char> Myal;
	typedef std::less<char> Mypred;
	typedef ft::set<char, Mypred, Myal> Mycont;
	char ch, str1[] = "abc", str2[] = "def";

	Mycont::key_type        *p_key = (char *)0;
	Mycont::key_compare     *p_komp = (Mypred *)0;
	Mycont::value_type      *p_val = (char *)0;
	Mycont::value_compare   *p_vcomp = (Mypred *)0;
	Mycont::allocator_type  *p_alloc = (Myal *)0;
	Mycont::pointer         p_ptr = (char *)0;
	Mycont::const_pointer   p_cptr = (const char *)0;
	Mycont::reference       p_ref = ch;
	Mycont::const_reference p_cref = (const char &)ch;
	Mycont::size_type       *p_size = (size_t *)0;
	Mycont::difference_type *p_diff = (ptrdiff_t *)0;

	Mycont v0;
	Myal al = v0.get_allocator();
	Mypred pred;
	Mycont v0a(pred), v0b(pred, al);

	assert(v0.empty() && v0.size() == 0);
	assert(v0a.size() == 0 && v0a.get_allocator() == al);
	assert(v0b.size() == 0 && v0b.get_allocator() == al);

	Mycont v1(str1, str1 + 3);
	assert(v1.size() == 3 && *v1.begin() == 'a');

	Mycont v2(str1, str1 + 3, pred);
	assert(v2.size() == 3 && *v2.begin() == 'a');
	Mycont v3(str1, str1 + 3, pred, al);
	assert(v3.size() == 3 && *v3.begin() == 'a');
	const Mycont v4(str1, str1 + 3);
	v0 = v4;
	assert(v0.size() == 3 && *v0.begin() == 'a');

	Mycont::iterator p_it(v1.begin());
	Mycont::const_iterator p_cit(v4.begin());
	Mycont::reverse_iterator p_rit(v1.rbegin());
	Mycont::const_reverse_iterator p_crit(v4.rbegin());
	assert(*p_it == 'a' && *--(p_it = v1.end()) == 'c');
	assert(*p_cit == 'a' && *--(p_cit = v4.end()) == 'c');
	assert(*p_rit == 'c' && *--(p_rit = v1.rend()) == 'a');
	assert(*p_crit == 'c' && *--(p_crit = v1.rend()) == 'a');

	v0.clear();
	ft::pair<Mycont::iterator, bool> pib = v0.insert('d');
	assert(*pib.first == 'd' && pib.second);
	assert(*--v0.end() == 'd');
	pib = v0.insert('d');
	assert(*pib.first == 'd');
	assert(!pib.second);

	assert(*v0.insert(v0.begin(), 'e') == 'e');
	v0.insert(str1, str1 + 3);
	assert(v0.size() == 5 && *v0.begin() == 'a');
	v0.insert(str2, str2 + 3);
	assert(v0.size() == 6 && *--v0.end() == 'f');
	assert(*v0.erase(v0.begin()) == 'b');
	assert(v0.size() == 5);
	assert(*v0.erase(v0.begin(), ++v0.begin()) == 'c' && v0.size() == 4);
	assert(v0.erase('x') == 0 && v0.erase('e') == 1);

	v0.clear();
	assert(v0.empty());
	v0.swap(v1);
	assert(!v0.empty() && v1.empty());
	ft::swap(v0, v1);
	assert(v0.empty() && !v1.empty());


	assert(v1 == v1);
	assert(v0 < v1);
	assert(v0 != v1 && v1 > v0);
	assert(v0 <= v1 && v1 >= v0);

	assert(v0.key_comp()('a', 'c') && !v0.key_comp()('a', 'a'));
	assert(v0.value_comp()('a', 'c') && !v0.value_comp()('a', 'a'));
	assert(*v4.find('b') == 'b');
	assert(v4.count('x') == 0 && v4.count('b') == 1);
	assert(*v4.lower_bound('a') == 'a');
	assert(*v4.upper_bound('a') == 'b');
	ft::pair<Mycont::const_iterator, Mycont::const_iterator> pcc = v4.equal_range('a');
	assert(*pcc.first == 'a' && *pcc.second == 'b');
}

int main() {
	test_vector();
	std::cout << "SUCCESS testing ft::vector" << std::endl;

	test_stack();
	std::cout << "SUCCESS testing ft::stack" << std::endl;

	test_map();
	std::cout << "SUCCESS testing ft::map" << std::endl;

	test_set();
    std::cout << "SUCCESS testing ft::set" << std::endl;
}
