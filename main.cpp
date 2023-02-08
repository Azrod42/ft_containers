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

		std::cout << tete[0] << std::endl;
		std::cout << tete[1] << std::endl;
		std::cout << tete[2] << std::endl;
		std::cout << tete[3] << std::endl;
		std::cout << tete[4] << std::endl;

		ft::vector<int> teta(tete.begin(), tete.end());
		std::cout << teta[0] << std::endl;
		std::cout << teta[1] << std::endl;
		std::cout << teta[2] << std::endl;
		std::cout << teta[3] << std::endl;
		std::cout << teta[4] << std::endl;
		std::cout << "=========" << std::endl;
	}
	{
		std::vector<int> tete(3);


		tete.push_back(5);
		tete.push_back(4);
		tete.push_back(3);
		tete.push_back(2);
		tete.push_back(1);

		std::cout << tete[0] << std::endl;
		std::cout << tete[1] << std::endl;
		std::cout << tete[2] << std::endl;
		std::cout << tete[3] << std::endl;
		std::cout << tete[4] << std::endl;

		ft::vector<int> teta(tete.begin(), tete.end());
		std::cout << teta[0] << std::endl;
		std::cout << teta[1] << std::endl;
		std::cout << teta[2] << std::endl;
		std::cout << teta[3] << std::endl;
		std::cout << teta[4] << std::endl;
		std::cout << "=========" << std::endl;
	}
	// test.~vector();
}