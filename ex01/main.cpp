#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <set>

int main() {
	std::srand(std::time(NULL));

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::set<int> numbers;
		for (int i = 0; i < 100; ++i)
			numbers.insert(std::rand() % 1000000);

		Span sp(100);
		sp.addRange(numbers.begin(), numbers.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
