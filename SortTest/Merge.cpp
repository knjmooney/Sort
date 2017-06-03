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
			// THEN: the type of the return value is std::vector<TestType>
			{
				auto result = mergeSort(std::vector<TestType>{ {-10}});
				Assert::IsTrue(result.size() == 1);
				Assert::IsTrue(result[0] == -10);
				Assert::IsTrue(std::is_same<decltype(result), std::vector<TestType>>::value);
			}
		}

		TEST_METHOD(AlreadySorted)
		{
			// GIVEN: an already sorted std::vector<int32_t>
			// WHEN: it is sorted
			// THEN: the return value is sorted
			// THEN: the type of the return value is std::vector<int32_t>
			{
				auto result = mergeSort(std::vector<int32_t>{1, 4, 7, 9, 99});
				Assert::IsTrue(result.size() == 5);
				Assert::IsTrue(result == std::vector<int32_t>{1, 4, 7, 9, 99});
				Assert::IsTrue(std::is_same<decltype(result), std::vector<int32_t>>::value);
			}

			// GIVEN: an already sorted std::vector<TestType>
			// WHEN: it is sorted
			// THEN: the return value is sorted
			// THEN: the type of the return value is std::vector<TestType>
			{
				auto result = mergeSort(std::vector<TestType>{ { 2 }, { 24 }, { 2349 }, { 9121 }});
				Assert::IsTrue(result.size() == 4);
				Assert::IsTrue(result == std::vector<TestType>{ { 2 }, { 24 }, { 2349 }, { 9121 }});
				Assert::IsTrue(std::is_same<decltype(result), std::vector<TestType>>::value);
			}
		}

		TEST_METHOD(Backwards)
		{
			// GIVEN: a reverse-sorted std::vector<int32_t>
			// WHEN: it is sorted
			// THEN: the return value is sorted
			// THEN: the type of the return value is std::vector<int32_t>
			{
				auto result = mergeSort(std::vector<int32_t>{ 99, 76, 54, 12, 5, 4, 1});
				Assert::IsTrue(result.size() == 7);
				Assert::IsTrue(result == std::vector<int32_t>{1, 4, 5, 12, 54, 76, 99});
				Assert::IsTrue(std::is_same<decltype(result), std::vector<int32_t>>::value);
			}

			// GIVEN: a reverse-sorted std::vector<TestType>
			// WHEN: it is sorted
			// THEN: the return value is sorted
			// THEN: the type of the return value is std::vector<TestType>
			{
				auto result = mergeSort(std::vector<TestType>{ { 65 }, { 63 }, { 62 }, { 4 }, { 2 }});
				Assert::IsTrue(result.size() == 5);
				Assert::IsTrue(result == std::vector<TestType>{ { 2 }, { 4 }, { 62 }, { 63 }, { 65 }});
				Assert::IsTrue(std::is_same<decltype(result), std::vector<TestType>>::value);
			}
		}

		TEST_METHOD(Unsorted)
		{
			// GIVEN: an unsorted std::vector<int32_t>
			// WHEN: it is sorted
			// THEN: the return value is sorted
			// THEN: the type of the return value is std::vector<int32_t>
			{
				auto result = mergeSort(std::vector<int32_t>{6, 912, 233, 97, -239234, 0 });
				Assert::IsTrue(result.size() == 6);
				Assert::IsTrue(result == std::vector<int32_t>{-239234, 0, 6, 97, 233, 912});
				Assert::IsTrue(std::is_same<decltype(result), std::vector<int32_t>>::value);
			}

			// GIVEN: an unsorted std::vector<TestType>
			// WHEN: it is sorted
			// THEN: the return value is sorted
			// THEN: the type of the return value is std::vector<TestType>
			{
				auto result = mergeSort(std::vector<TestType>{ { -1 }, { -1230 }, { 2 }, { 659 }});
				Assert::IsTrue(result.size() == 4);
				Assert::IsTrue(result == std::vector<TestType>{ { -1230 }, { -1 }, { 2 }, { 659 }});
				Assert::IsTrue(std::is_same<decltype(result), std::vector<TestType>>::value);
			}
		}

		TEST_METHOD(SomeDuplicate)
		{
			// GIVEN: an unsorted std::vector<int32_t> duplicated elements
			// WHEN: it is sorted
			// THEN: the return value is sorted
			// THEN: the type of the return value is std::vector<int32_t>
			{
				auto result = mergeSort(std::vector<int32_t>{6, 912, 233, 6, 97, 0, -239234, 0 });
				Assert::IsTrue(result.size() == 8);
				Assert::IsTrue(result == std::vector<int32_t>{-239234, 0, 0, 6, 6, 97, 233, 912});
				Assert::IsTrue(std::is_same<decltype(result), std::vector<int32_t>>::value);
			}

			// GIVEN: an unsorted std::vector<TestType> with duplicated elements
			// WHEN: it is sorted
			// THEN: the return value is sorted
			// THEN: the type of the return value is std::vector<TestType>
			{
				auto result = mergeSort(std::vector<TestType>{ { -1 }, { 659 }, { 2 }, { -1230 }, { 2 }, { 659 }});
				Assert::IsTrue(result.size() == 6);
				Assert::IsTrue(result == std::vector<TestType>{ { -1230 }, { -1 }, { 2 }, { 2 }, { 659 }, { 659 }});
				Assert::IsTrue(std::is_same<decltype(result), std::vector<TestType>>::value);
			}
		}

		TEST_METHOD(AllDuplicate)
		{
			// GIVEN: an std::vector<int32_t> of all equal elements
			// WHEN: it is sorted
			// THEN: the return value is sorted
			// THEN: the type of the return value is std::vector<int32_t>
			{
				auto result = mergeSort(std::vector<int32_t>{ 4, 4, 4, 4 });
				Assert::IsTrue(result.size() == 4);
				Assert::IsTrue(result == std::vector<int32_t>{4, 4, 4, 4});
				Assert::IsTrue(std::is_same<decltype(result), std::vector<int32_t>>::value);
			}

			// GIVEN: an std::vector<TestType> of all equal elements
			// WHEN: it is sorted
			// THEN: the return value is sorted
			// THEN: the type of the return value is std::vector<TestType>
			{
				auto result = mergeSort(std::vector<TestType>{ { -1 }, { -1 }, { -1 }});
				Assert::IsTrue(result.size() == 3);
				Assert::IsTrue(result == std::vector<TestType>{ { -1 }, { -1 }, { -1 }});
				Assert::IsTrue(std::is_same<decltype(result), std::vector<TestType>>::value);
			}
		}
	};
}