#include "Day1.h"

#include <algorithm>
#include <cassert>
#include <charconv>
#include <cmath>
#include <sstream>
#include <utility>
#include <vector>

namespace day1
{
	std::pair<std::vector<int>, std::vector<int>> GetLocationIDsFromInput(const char* inInput)
	{
		std::stringstream stream{ inInput };
		std::string line{};

		std::vector<int> locationAs, locationBs;

		while (std::getline(stream, line)) {
			int locationA = 0;
			int locationB = 0;

			const auto endOfAOffset = line.find_first_of("\t ");
			const auto startOfB = line.data() + line.find_first_not_of("\t ", endOfAOffset);
			const auto endOfA = line.data() + endOfAOffset;

			const auto resultA = std::from_chars(line.data(), endOfA, locationA);
			const auto resultB = std::from_chars(startOfB, line.data() + line.length(), locationB);

			locationAs.push_back(locationA);
			locationBs.push_back(locationB);
		}
		return { locationAs, locationBs };
	}

	size_t getSimilarity(LocationList inListA, LocationList inListB)
	{
		size_t similarity = 0;
		for (size_t i = 0; i < inListA.size(); ++i)
		{
			const auto a = inListA[i];
			size_t numMatches = 0;
			for (auto&& b : inListB)
			{
				if (a == b) { ++numMatches; }
			}

			similarity += (a * numMatches);
		}

		return similarity;
	}

	size_t getDistanceBetweenLocationIDLists(LocationList inA, LocationList inB)
	{
		std::sort(std::begin(inA), std::end(inA));
		std::sort(std::begin(inB), std::end(inB));

		const auto numLocations = inA.size();
		assert(numLocations == inB.size());

		size_t distance = 0;
		for (size_t i = 0; i < numLocations; ++i)
		{
			distance += std::abs(inA[i] - inB[i]);
		}
		return distance;
	}

}
