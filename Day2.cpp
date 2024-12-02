#include "Day2.h"

#include "Utils.h"

#include <sstream>
#include <vector>

namespace day2
{
	int countSafeReports(const char* inInput)
	{
		std::vector<std::vector<int>> reports;

		const auto countUnSafeFunc = [&reports](const auto& inLine)
		{
				std::istringstream intStream(inLine);
				int level;
				std::vector<int> report;

				while (intStream >> level) {
					report.push_back(level);
				}
				reports.push_back(report);
		};

		stu::doPerLine(inInput, countUnSafeFunc);
	
		int numSafeReports = 0;
		for (auto&& report : reports)
		{
			const auto [unsafe, firstFailIndex] = isUnsafe(report);
			if (unsafe)
			{
				const auto originalReport = report;
				// Brute force, re-try the report for every combo with one element removed
				// If any pass, its good
				for (int i = 0; i < originalReport.size(); ++i)
				{
					report = originalReport;
					report.erase(report.begin() + i);
					const auto [fail, index] = isUnsafe(report);
					if (!fail)
					{
						++numSafeReports;
						break;
					}
				}
			}
			else
			{
				++numSafeReports;
			}		
		}
		return numSafeReports;
	}

	std::pair<bool, int> isUnsafe(std::vector<int> inReport)
	{
		static constexpr int kMaxAllowableLevelChange = 3;
		enum class LevelChangeType { Increasing, Decreasing, Unknown };
		const auto levelChangeType = inReport[0] > inReport[1] ? LevelChangeType::Decreasing : inReport[0] < inReport[1] ? LevelChangeType::Increasing : LevelChangeType::Unknown;
		
		if (levelChangeType == LevelChangeType::Unknown)
		{
			return { true, 0 };
		}

		int prevLevel = inReport[0];
		for (int i = 1; i < inReport.size(); ++i)
		{
			const auto level = inReport[i];
			if (levelChangeType == LevelChangeType::Increasing && level > prevLevel)
			{
				if ((level - prevLevel) > kMaxAllowableLevelChange)
				{
					return { true, i };
				}
			}
			else if (levelChangeType == LevelChangeType::Decreasing && level < prevLevel)
			{
				if ((prevLevel - level) > kMaxAllowableLevelChange)
				{
					return { true, i };
				}
			}
			else
			{
				return { true, i };
			}
			prevLevel = level;
		}
		return { false, -1 };
	}
}