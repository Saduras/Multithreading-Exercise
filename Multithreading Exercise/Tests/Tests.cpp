#include "pch.h"
#include "CppUnitTest.h"

#include "../Multithreading Exercise/src/Parallel.h"
#include "../Multithreading Exercise/src/Parallel.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TestParallel)
	{
	public:
		TEST_METHOD(TestVectorAdd)
		{
			using namespace std;

			int n = 100;
			vector<int> a(n);
			vector<int> b(n);
			for (size_t i = 0; i < n; i++) {
				a[i] = std::rand();
				b[i] = std::rand();
			}

			vector<int> result = Parallel::VectorAdd(a, b);
			for (size_t i = 0; i < result.size(); i++) {
				Assert::AreEqual(a[i] + b[i], result[i]);
			}
		}
	};
}
