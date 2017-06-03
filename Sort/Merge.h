#pragma once

#include <algorithm>

namespace Sort {
	template <typename Container>
	Container mergeSort(Container input) {
		// TODO: le merge sort
		std::sort(input.begin(), input.end());
		return input;
	}
}
