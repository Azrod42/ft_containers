#include"./includes/vector.hpp"
#include<vector>

int main(void)
{
	{
		ft::vector<int> tete(32);

		tete.push_back(299);
		// tete.push_back(298);
		// tete.push_back(297);
		// tete.push_back(296);
		// tete.push_back(295);

		for (size_t i = 0; i < tete.size(); i++)
			std::cout << tete[i] << std::endl;
		std::cout << "=========" << std::endl;
		std::cout << tete.size() << std::endl;

		// for (size_t i = 0; i < tete.size(); i++)
		// 	std::cout << tete[0] << std::endl;
		std::cout << "=========" << std::endl;
	}
	{
		std::vector<int> tete(32);

		tete.push_back(299);
		tete.push_back(298);
		tete.push_back(297);
		tete.push_back(296);
		tete.push_back(295);

		for (size_t i = 0; i < tete.size(); i++)
			std::cout << tete[i] << std::endl;
		std::cout << "=========" << std::endl;
		std::cout << tete.size() << std::endl;

		// for (size_t i = 0; i < tete.size(); i++)
		// 	std::cout << tete[0] << std::endl;
		std::cout << "=========" << std::endl;
	}
	// test.~vector();
}
