#pragma once

#include <cmath>

namespace Sort {
    namespace internal {
        template <typename T>
        constexpr void mergeSorted(const T* const sourceA, const size_t sourceASize,
                                   const T* const sourceB, const size_t sourceBSize,
                                   T* const target) {
            // can't write directly to target, as it might alias sourceA/sourceB
            std::vector<T> result(sourceASize + sourceBSize);

            size_t resultIndex = 0, aIndex = 0, bIndex = 0;
            while (aIndex < sourceASize && bIndex < sourceBSize) {
                result[resultIndex++] = sourceA[aIndex] < sourceB[bIndex] ? sourceA[aIndex++] : sourceB[bIndex++];
            }

            while (aIndex < sourceASize) {
                result[resultIndex++] = sourceA[aIndex++];
            }

            while (bIndex < sourceBSize) {
                result[resultIndex++] = sourceB[bIndex++];
            }

            memcpy(target, result.data(), result.size() * sizeof(T));
        }
    }

    template <typename Container>
    constexpr Container mergeSort(Container data) {
        using namespace internal;

        if (data.size() < 2) {
            return data;
        }

        size_t stride = 1;
        do {
            for (size_t i = 0; i + stride < data.size(); i += stride * 2) {
                mergeSorted(&data[i], stride,
                            &data[i + stride], std::min(stride, data.size() - (i + stride)),
                            &data[i]);
            }
            stride *= 2;
        } while (stride < data.size());

        return data;
    }
}
