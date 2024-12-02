#pragma once
#include <utility>
#include <vector>

namespace day2
{
	int countSafeReports(const char* inInput);
	std::pair<bool, int> isUnsafe(std::vector<int> inReport);
}