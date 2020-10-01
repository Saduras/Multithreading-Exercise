#include "pch.h"
#include "CppUnitTest.h"

#include "../Multithreading Exercise/src/Parallel.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(TestParallel)
	{
	public:
		TEST_METHOD(TestVectorAddThreads)
		{
			using namespace std;

			int n = 100;
			vector<int> a(n);
			vector<int> b(n);
			for (size_t i = 0; i < n; i++) {
				a[i] = std::rand();
				b[i] = std::rand();
			}

			vector<int> result = Parallel::VectorAddThreads(a, b);
			for (size_t i = 0; i < result.size(); i++) {
				Assert::AreEqual(a[i] + b[i], result[i]);
			}
		}

		TEST_METHOD(TestVectorAddAsync)
		{
			using namespace std;

			int n = 100;
			vector<int> a(n);
			vector<int> b(n);
			for (size_t i = 0; i < n; i++) {
				a[i] = std::rand();
				b[i] = std::rand();
			}

			vector<int> result = Parallel::VectorAddAsync(a, b);
			for (size_t i = 0; i < result.size(); i++) {
				Assert::AreEqual(a[i] + b[i], result[i]);
			}
		}
	};
}
