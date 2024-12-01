#pragma once

#include <utility>
#include <vector>

namespace day1
{
	using LocationList = std::vector<int>;

	std::pair<LocationList, LocationList> GetLocationIDsFromInput(const char* inInput);

	size_t getDistanceBetweenLocationIDLists(LocationList inListA, LocationList inListB);
	size_t getSimilarity(LocationList inListA, LocationList inListB);
}