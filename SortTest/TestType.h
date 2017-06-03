#pragma once

#include "stdafx.h"

namespace SortTest {
	class TestType {
	public:
		constexpr TestType(int32_t value)
		: m_value(value) {

		}

		constexpr bool operator<(const TestType& rhs) const {
			return m_value < rhs.m_value;
		}

		constexpr bool operator==(const TestType& rhs) const {
			return m_value == rhs.m_value;
		}

		constexpr int32_t getValue() const {
			return m_value;
		}

	private:
		const int32_t m_value;
	};
}
