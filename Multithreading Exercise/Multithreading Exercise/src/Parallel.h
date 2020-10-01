#pragma once

#include <vector>

namespace Parallel
{
	std::vector<int> VectorAddThreads(const std::vector<int>& a, const std::vector<int>& b);
	
	std::vector<int> VectorAddAsync(const std::vector<int>& a, const std::vector<int>& b);
}