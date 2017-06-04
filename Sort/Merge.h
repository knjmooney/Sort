#pragma once

#include <algorithm>

namespace Sort {
	namespace internal {
		template <typename Container>
		constexpr Container mergeSorted(Container a, Container b) {
			Container result;
			result.resize(a.size() + b.size());

			size_t resultIndex = 0, aIndex = 0, bIndex = 0;
			while (aIndex < a.size() && bIndex < b.size()) {
				result[resultIndex++] = a[aIndex] < b[bIndex] ? a[aIndex++] : b[bIndex++];
			}

			while (aIndex < a.size()) {
				result[resultIndex++] = a[aIndex++];
			}

			while (bIndex < b.size()) {
				result[resultIndex++] = b[bIndex++];
			}

			return result;
		}
	}

	template <typename Container>
	constexpr Container mergeSort(Container input) {
		using namespace internal;

		if (input.size() < 2) {
			return input;
		}

		Container result;
		result.resize(input.size());

		std::vector<Container> subContainers;

		for (size_t i = 0; i < input.size(); ++i) {
			subContainers.push_back({ input[i] });
		}

		while (subContainers.size() != 1) {
			for (size_t i = 0; i < subContainers.size() - 1; ++i) {
				subContainers.push_back(mergeSorted(subContainers[i], subContainers[i + 1]));
				subContainers.erase(subContainers.begin() + i, subContainers.begin() + i + 2);
			}
		}

		return subContainers.front();
	}
}
