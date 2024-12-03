#include "Day1.h"
#include "Day2.h"
#include "day3.h"
#include "Utils.h"

#include <numeric>
#include <print>

int main()
{
    {
        // Day 1
        const auto input = stu::readFile("day1.txt");
        auto [locationListA, locationListB] = day1::GetLocationIDsFromInput(input.c_str());
        const auto listDistance = day1::getDistanceBetweenLocationIDLists(locationListA, locationListB);
        const auto similarity = day1::getSimilarity(locationListA, locationListB);

        std::println("=== DAY 1 ===");
        std::println("The distance between location lists is: {}", listDistance);
        std::println("The Similarity of the lists is: {}", similarity);
    }

    std::println();
    {
        const auto input = stu::readFile("day2.txt");
        const auto numSafeReports = day2::countSafeReports(input.c_str());

        std::println("=== DAY 2 ===");
        std::println("The number of safe reports is: {}", numSafeReports);
    }

    std::println();
    {
        const auto input = stu::readFile("day3.txt");
        const auto sumOfMuls = day3::getMuls(input);

        std::println("=== DAY 3 ===");
        std::println("The sum of mul expressions is: {}", sumOfMuls);
    }

    return 0;
}