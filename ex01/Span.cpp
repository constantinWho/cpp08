#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _data(other._data), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_data = other._data;
		_maxSize = other._maxSize;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (_data.size() >= _maxSize)
		throw SpanOverflow();
	_data.push_back(num);
}

int Span::shortestSpan() const {
	if (_data.size() < 2)
		throw SpanNotPossible();
	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i) {
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const {
	if (_data.size() < 2)
		throw SpanNotPossible();

	int min = *std::min_element(_data.begin(), _data.end());
	int max = *std::max_element(_data.begin(), _data.end());

	return max - min;
}
