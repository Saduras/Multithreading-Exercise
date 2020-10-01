#include "Parallel.h"

#include <thread>
#include <future>
#include <iostream>

std::vector<int> Parallel::VectorAddThreads(const std::vector<int>& a, const std::vector<int>& b)
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

std::vector<int> Parallel::VectorAddAsync(const std::vector<int>& a, const std::vector<int>& b)
{
	std::vector<int> result(a.size());
	std::vector<std::future<int>> futures;

	// define function to execute async
	auto add = [](int a, int b) {
		return a + b;
	};

	for (size_t i = 0; i < result.size(); i++) {
		futures.push_back(std::async(std::launch::async, add, a[i], b[i]));
	}

	// wait for all futures to finish and get their result
	for (size_t i = 0; i < futures.size(); i++) {
		futures[i].wait();
		result[i] = futures[i].get();
	}

	return result;
}
