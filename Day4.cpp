#include "Day4.h"

#include <array>
#include <utility>

#include "Utils.h"

namespace day4
{
	std::vector<std::string> stringToTable(const std::string& inInput)
	{
		std::vector<std::string> table;
		const auto addLine = [&table](const std::string& inLine) { table.push_back(inLine); };

		stu::doPerLine(inInput.c_str(), addLine);

		return table;
	}

	size_t countAppearances(const std::string& inWordToFind, const std::string& inInput)
	{
		static constexpr std::array<std::pair<int, int>, 8> kDirectionSteps{ std::pair{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

		const auto wordTable = stringToTable(inInput);

		std::vector<std::pair<int, int>> xIndices;
		for (int i = 0; i < wordTable.size(); ++i)
		{
			const auto& row = wordTable[i];
			for (int j = 0; j < row.length(); ++j)
			{
				if (wordTable[i][j] == 'x' || wordTable[i][j] == 'X')
				{
					xIndices.emplace_back(i, j);
				}
			}
		}

		size_t wordsFound = 0;
		for (auto&& [xStart, yStart] : xIndices)
		{
			const char* mas = "MAS";
			const auto row = wordTable[xStart];
			
			for (auto&& [xStep, yStep] : kDirectionSteps)
			{
				int x = xStart;
				int y = yStart;
				int matched = 0;
				for (int i = 0; i < 3 && i == matched; ++i)
				{
					x += xStep;
					const char nextDesired = mas[i];
					const auto nextX = x + xStep;
					if (x >= 0 && x < wordTable.size())
					{
						y += yStep;
						if (y >= 0 && y < row.length())
						{
							const char next = wordTable[x][y];
							if (next == nextDesired)
							{
								++matched;
							}
						}
					}
				}
				if (matched == 3) { ++wordsFound; };
			}		
		}
		return wordsFound;
	}
}