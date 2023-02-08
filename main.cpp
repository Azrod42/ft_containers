#include"./includes/vector.hpp"
#include"./includes/iteratorv.hpp"
#include<vector>

int main(void)
{
	{
		ft::vector<int> tete(1);

		tete.push_back(5);
		tete.push_back(4);
		tete.push_back(3);
		tete.push_back(2);
		tete.push_back(1);

		std::cout << tete.front() << std::endl;
		int *j = tete.data();
		*j = 32;
		std::cout << tete.front() << std::endl;
		std::cout << tete.at(1) << std::endl;
		std::cout << tete[2] << std::endl;
		std::cout << tete.at(3) << std::endl;
		std::cout << tete.back() << std::endl;
		std::cout << tete.max_size() << std::endl;

		std::cout << "=========" << std::endl;
	}
	{
		std::vector<int> tete(5);

		std::cout << tete.capacity() << std::endl;
		tete.push_back(5);
		std::cout << tete.capacity() << std::endl;
		tete.push_back(4);
		tete.push_back(3);
		tete.push_back(2);
		tete.push_back(1);
		tete.push_back(1);

		std::cout << tete.front() << std::endl;
		int *j = tete.data();
		*j = 32;
		std::cout << tete.front() << std::endl;
		std::cout << tete.at(1) << std::endl;
		std::cout << tete[2] << std::endl;
		std::cout << tete.at(3) << std::endl;
		std::cout << tete.back() << std::endl;
		std::cout << tete.max_size() << std::endl;
		std::cout << tete.capacity() << std::endl;

		std::cout << "=========" << std::endl;
	}
	// test.~vector();
}