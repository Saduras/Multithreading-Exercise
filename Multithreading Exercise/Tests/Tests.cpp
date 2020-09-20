#include "pch.h"
#include "CppUnitTest.h"

#include "../Multithreading Exercise/src/dummy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		TEST_METHOD(TestDummyAdd)
		{
			Assert::AreEqual(8, add(3, 5));
		}
	};
}
