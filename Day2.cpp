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

		static constexpr int kMaxAllowableLevelChange = 3;
		int numUnsafeReports = 0;

		enum class LevelChangeType { Increasing, Decreasing, Unknown };

		for (auto&& report : reports)
		{
			const auto levelChangeType = report[0] > report[1] ? LevelChangeType::Decreasing : report[0] < report[1] ? LevelChangeType::Increasing : LevelChangeType::Unknown;
			if (levelChangeType == LevelChangeType::Unknown)
			{
				++numUnsafeReports;
				continue;
			}

			int prevLevel = report[0];
			for (int i = 1; i < report.size(); ++i)
			{
				const auto level = report[i];
				if (levelChangeType == LevelChangeType::Increasing && level > prevLevel)
				{
					if ((level - prevLevel) > kMaxAllowableLevelChange)
					{
					  prevLevel = level;
					  ++numUnsafeReports;
					  break;
					}
				}
				else if (levelChangeType == LevelChangeType::Decreasing && level < prevLevel)
				{
					if ((prevLevel - level) > kMaxAllowableLevelChange)
					{
						prevLevel = level;
						++numUnsafeReports;
						break;
					}
				}
				else
				{
					prevLevel = level;
					++numUnsafeReports;
					break;
				}
				prevLevel = level;
			}
		}

		return reports.size() - numUnsafeReports;
	}
}