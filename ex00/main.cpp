#include "easyfind.hpp"
# include <vector>
# include <list>

int main() {
	try {
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		std::vector<int>::iterator vecIt = easyfind(vec, 3);
		std::cout << "Found: " << *vecIt << " in vector" << std::endl;

		std::list<int> lst;
		lst.push_back(100);
		lst.push_back(200);
		lst.push_back(300);
		lst.push_back(400);
		lst.push_back(500);

		std::list<int>::iterator listIt = easyfind(lst, 300);
		std::cout << "Found: " << *listIt << " in list" << std::endl;

		easyfind(vec, 100);

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
