#include"./includes/vector.hpp"
#include"./includes/iteratorv.hpp"
#include<vector>

int main(void)
{
	// ft::vector<int> test(5);
	std::vector<int> tete(5);

	tete.push_back(5);
	tete.push_back(4);
	tete.push_back(3);
	tete.push_back(2);
	tete.push_back(1);

	typedef typename ft::Iteratorv<std::vector<int> > it;

	it = tete.begin();


	// test.~vector();
}