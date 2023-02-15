#include"./includes/vector.hpp"
#include<vector>

int main(void)
{
	{
		ft::vector<int> vct(7);
		ft::vector<int> vct_two(4);
		ft::vector<int> vct_three;
		ft::vector<int> vct_four;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		for (unsigned long int i = 0; i < vct_two.size(); ++i)
			vct_two[i] = (vct_two.size() - i) * 5;
		std::cout << "vct : "<< vct.size() << " " << vct.capacity() << std::endl;
		std::cout << "vct_two : "<< vct_two.size() << " " << vct_two.capacity() << std::endl;

		vct_three.assign(vct.begin(), vct.end());
		vct.assign(vct_two.begin(), vct_two.end());
		vct_two.assign(2, 42);
		vct_four.assign(4, 21);


		std::cout << "\t### After assign(): ###" << std::endl;

		std::cout << "vct : "<< vct.size() << " " << vct.capacity() << std::endl;
		std::cout << "vct_two : "<< vct_two.size() << " " << vct_two.capacity() << std::endl;
		std::cout << "vct_three : "<< vct_three.size() << " " << vct_three.capacity() << std::endl;
		std::cout << "vct_four : "<< vct_four.size() << " " << vct_four.capacity() << std::endl;

		vct_four.assign(6, 84);
		std::cout << "vct_four : "<< vct_four.size() << " " << vct_four.capacity() << std::endl;

		std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

		vct.assign(5, 53);
		vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

		std::cout << "vct : "<< vct.size() << " " << vct.capacity() << std::endl;
		std::cout << "vct_two : "<< vct_two.size() << " " << vct_two.capacity() << std::endl;
		std::cout << "======================" << std::endl;
	}
	{
		std::vector<int> vct(7);
		std::vector<int> vct_two(4);
		std::vector<int> vct_three;
		std::vector<int> vct_four;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		for (unsigned long int i = 0; i < vct_two.size(); ++i)
			vct_two[i] = (vct_two.size() - i) * 5;
		std::cout << "vct : "<< vct.size() << " " << vct.capacity() << std::endl;
		std::cout << "vct_two : "<< vct_two.size() << " " << vct_two.capacity() << std::endl;

		vct_three.assign(vct.begin(), vct.end());
		vct.assign(vct_two.begin(), vct_two.end());
		vct_two.assign(2, 42);
		vct_four.assign(4, 21);


		std::cout << "\t### After assign(): ###" << std::endl;

		std::cout << "vct : "<< vct.size() << " " << vct.capacity() << std::endl;
		std::cout << "vct_two : "<< vct_two.size() << " " << vct_two.capacity() << std::endl;
		std::cout << "vct_three : "<< vct_three.size() << " " << vct_three.capacity() << std::endl;
		std::cout << "vct_four : "<< vct_four.size() << " " << vct_four.capacity() << std::endl;

		vct_four.assign(6, 84);
		std::cout << "vct_four : "<< vct_four.size() << " " << vct_four.capacity() << std::endl;

		std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

		vct.assign(5, 53);
		vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

		std::cout << "vct : "<< vct.size() << " " << vct.capacity() << std::endl;
		std::cout << "vct_two : "<< vct_two.size() << " " << vct_two.capacity() << std::endl;
		std::cout << "======================" << std::endl;
	}
}
