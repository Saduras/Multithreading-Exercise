#include "Parallel.h"

#include <thread>

std::vector<int> Parallel::VectorAdd(const std::vector<int>& a, const std::vector<int>& b)
{
	std::vector<std::thread> threads;
	std::vector<int> result(a.size());

	// define function to execute on thread
	auto add = [](int a, int b, int& result) {
		result = a + b;
	};

	for (size_t i = 0; i < result.size(); i++) {
		// reference arguments (int&) must be wrapped with std::ref()
		threads.push_back(std::thread(add, a[i], b[i], std::ref(result[i])));
	}

	// wait for all threads to finish
	for (size_t i = 0; i < threads.size(); i++) {
		threads[i].join();
	}

	return result;
}
