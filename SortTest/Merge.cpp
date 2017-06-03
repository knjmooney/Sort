#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Merge.h"

using namespace Sort;

#include "TestType.h"

namespace SortTest
{		
	TEST_CLASS(MergeSortTest)
	{
	public:
		TEST_METHOD(NoElements)
		{
			// GIVEN: an empty std::vector<int32_t>
			// WHEN: it is sorted
			// THEN: the return value is empty
			// THEN: the type of the return value is std::vector<int>
			{
				auto result = mergeSort(std::vector<int32_t> {});
				Assert::IsTrue(result.size() == 0);
				Assert::IsTrue(std::is_same<decltype(result), std::vector<int32_t>>::value);
			}

			// GIVEN: an empty std::vector<TestType>
			// WHEN: it is sorted
			// THEN: the return value is empty
			// THEN: the type of the return value is std::vector<TestType>
			{
				auto result = mergeSort(std::vector<TestType> {});
				Assert::IsTrue(result.size() == 0);
				Assert::IsTrue(std::is_same<decltype(result), std::vector<TestType>>::value);
			}
		}

		TEST_METHOD(SingleElement)
		{
			// GIVEN: a single element std::vector<int32_t>
			// WHEN: it is sorted
			// THEN: the return value contains the input element
			// THEN: the type of the return value is std::vector<int32_t>
			{
				auto result = mergeSort(std::vector<int32_t> {42});
				Assert::IsTrue(result.size() == 1);
				Assert::IsTrue(result[0] == 42);
				Assert::IsTrue(std::is_same<decltype(result), std::vector<int32_t>>::value);
			}

			// GIVEN: a single element std::vector<TestType>
			// WHEN: it is sorted
			// THEN: the return value contains the input element
			// THEN: the tye of the return value is std::vector<TestType>
			{
				auto result = mergeSort(std::vector<TestType>{ {-10}});
				Assert::IsTrue(result.size() == 1);
				Assert::IsTrue(result[0] == -10);
				Assert::IsTrue(std::is_same<decltype(result), std::vector<TestType>>::value);
			}
		}
	};
}