#pragma once

#include <string>
#include <vector>

namespace day4
{
	std::vector<std::string> stringToTable(const std::string& inInput);
	size_t countAppearances(const std::string& inWordToFind, const std::string& inInput);
}