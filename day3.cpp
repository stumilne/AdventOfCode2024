#include "day3.h"

#include <charconv>
#include <regex>
#include <string>

namespace day3
{
	size_t getMuls(const std::string& inInput)
	{
		std::regex mulExpressionRegex(R"(mul\(\d+,\d+\))");
		std::sregex_iterator matchesIt(std::cbegin(inInput), std::cend(inInput), mulExpressionRegex);

		size_t sumOfMuls = 0;
		int numMatches = 0;
		
		for (auto i = matchesIt; i != std::sregex_iterator{}; ++i)
		{
			const auto match = *i;
			const auto mulExpression = match.str();
			int a = 0; int b = 0;
			const auto commaOffset = mulExpression.find_first_of(',');
			std::from_chars(&mulExpression.at(4), &mulExpression.at(commaOffset), a);
			std::from_chars(&mulExpression.at(commaOffset + 1), &mulExpression.at(mulExpression.size() - 1), b);

			++numMatches;
			sumOfMuls += (a * b);
		}
		return sumOfMuls;
	}

	size_t parseMulInput(const std::string& inInput)
	{
		std::string mulsToExecute{};

		const auto firstStopInstruction = inInput.find("don't()");
		mulsToExecute.append(inInput.substr(0, firstStopInstruction));

		auto stop = firstStopInstruction;
		while (stop != std::string::npos)
		{
			const auto start = inInput.find("do()", stop);
			if (start == std::string::npos) { break; }

			stop = inInput.find("don't()", start);
			const auto numChars = stop != std::string::npos ? stop - start : inInput.length() - start;

			mulsToExecute.append(inInput.substr(start, numChars));
		}

		return getMuls(mulsToExecute);
	}
}