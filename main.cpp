#include"./includes/vector.hpp"
#include<vector>

int main(void)
{
	{
		ft::vector<int> tete(2);

		std::cout << tete.size() << std::endl;
		std::cout << tete.capacity() << std::endl;
		tete.reserve(10);
		std::cout << tete.size() << std::endl;
		std::cout << tete.capacity() << std::endl;
		tete.resize(13, 32);
		std::cout << tete.size() << std::endl;
		std::cout << tete.capacity() << std::endl;
		ft::vector<int>::iterator it = tete.begin() + 5;
		std::cout << *it << std::endl;
		std::cout << "========" << std::endl;
		tete[9] = 31;
		tete[0] = 42;
		tete[12] = 900;
		std::cout << tete[9] << std::endl;
		std::cout << tete[10] << std::endl;
		std::cout << tete.at(9) << std::endl;
		std::cout << tete.at(10) << std::endl;
		std::cout << tete.front() << std::endl;
		std::cout << tete.back() << std::endl;
		tete.data();
		ft::vector<int> teta(5);
		teta.assign(tete.begin(), tete.end());
		std::cout << "========" << std::endl;
		std::cout << teta[9] << std::endl;
		std::cout << teta[10] << std::endl;
		std::cout << teta.at(9) << std::endl;
		std::cout << teta.at(10) << std::endl;
		std::cout << teta.front() << std::endl;
		std::cout << teta.back() << std::endl;
		teta.assign((size_t)32, (int)989);	
		std::cout << teta[9] << std::endl;
		std::cout << teta[10] << std::endl;
		std::cout << teta.at(9) << std::endl;
		std::cout << teta.at(10) << std::endl;
		std::cout << teta.front() << std::endl;
		std::cout << teta.back() << std::endl;
		teta.push_back(3232);
		std::cout << teta.back() << std::endl;
		// for (size_t i = 0; i < tete.size(); i++)
		// 	std::cout << tete[i] << std::endl;
		std::cout << "======================" << std::endl;
	}
	{
		std::vector<int> tete(2);

		std::cout << tete.size() << std::endl;
		std::cout << tete.capacity() << std::endl;
		tete.reserve(10);
		std::cout << tete.size() << std::endl;
		std::cout << tete.capacity() << std::endl;
		tete.resize(13, 32);
		std::cout << tete.size() << std::endl;
		std::cout << tete.capacity() << std::endl;
		std::vector<int>::iterator it = tete.begin() + 5;
		std::cout << *it << std::endl;
		std::cout << "========" << std::endl;
		tete[9] = 31;
		tete[0] = 42;
		tete[12] = 900;
		std::cout << tete[9] << std::endl;
		std::cout << tete[10] << std::endl;
		std::cout << tete.at(9) << std::endl;
		std::cout << tete.at(10) << std::endl;
		std::cout << tete.front() << std::endl;
		std::cout << tete.back() << std::endl;
		tete.data();
		std::vector<int> teta(5);
		teta.assign(tete.begin(), tete.end());
		std::cout << "========" << std::endl;
		std::cout << teta[9] << std::endl;
		std::cout << teta[10] << std::endl;
		std::cout << teta.at(9) << std::endl;
		std::cout << teta.at(10) << std::endl;
		std::cout << teta.front() << std::endl;
		std::cout << teta.back() << std::endl;
		teta.assign(32, 989);	
		std::cout << teta[9] << std::endl;
		std::cout << teta[10] << std::endl;
		std::cout << teta.at(9) << std::endl;
		std::cout << teta.at(10) << std::endl;
		std::cout << teta.front() << std::endl;
		std::cout << teta.back() << std::endl;
		teta.push_back(3232);
		std::cout << teta.back() << std::endl;
		std::cout << "===========u---u===========" << std::endl;
	}
	{
		ft::vector<int> tete(0);

		tete.push_back(30);
		tete.push_back(31);
		tete.push_back(32);
		tete.push_back(33);
		tete.push_back(34);
		tete.push_back(35);
		tete.pop_back();
		tete.insert(tete.begin() + 2, 200);
		tete.insert(tete.begin() + 2, 200);
		// tete.insert(tete.begin()+2, 200);
		for (size_t i = 0; i < tete.size(); i++)
			std::cout << tete[i] << std::endl;
		std::cout << tete.size() << " " << tete.capacity() << std::endl;
		std::cout << "======================" << std::endl;
	}
	{
		std::vector<int> tete(0);

		tete.push_back(30);
		tete.push_back(31);
		tete.push_back(32);
		tete.push_back(33);
		tete.push_back(34);
		tete.push_back(35);
		tete.pop_back();
		// tete.insert(tete.begin()+5, 10000, 32);
		for (size_t i = 0; i < tete.size(); i++)
			std::cout << tete[i] << std::endl;
		std::cout << tete.size() << " " << tete.capacity() << std::endl;
	}
}
