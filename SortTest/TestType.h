#pragma once

#include "stdafx.h"

namespace SortTest {
	class TestType {
	public:
		constexpr TestType()
		: m_value(0) {

		}

		constexpr TestType(int32_t value)
		: m_value(value) {

		}

		constexpr TestType& operator=(const TestType& rhs) {
			m_value = rhs.m_value;
			return *this;
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
		int32_t m_value;
	};
}
