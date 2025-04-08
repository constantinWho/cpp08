#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
	private:
		std::vector<int>	_data;
		unsigned int		_maxSize;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;

		class SpanOverflow : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "ERROR: Span is full";
				}
			};

		class SpanNotPossible : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "ERROR: Span is not possible";
			}
		};

		template <typename ContainerIter>
		void addRange(ContainerIter begin, ContainerIter end) {
			if (static_cast<size_t>(std::distance(begin, end)) + _data.size() > _maxSize)
				throw SpanOverflow();
		_data.insert(_data.end(), begin, end);
}

};

#endif
