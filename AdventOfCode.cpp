#include "Day1.h"
#include "Day2.h"
#include "day3.h"
#include "Utils.h"

#include <print>

void startDay(const int inDayNum)
{
    std::println();;
    std::println("=== DAY {} ===", inDayNum);
}

int main()
{
    std::println("stumilne's Advent of Code 2024");
    {
        // Day 1
        const auto input = stu::readFile("input/day1.txt");
        auto [locationListA, locationListB] = day1::GetLocationIDsFromInput(input.c_str());
        const auto listDistance = day1::getDistanceBetweenLocationIDLists(locationListA, locationListB);
        const auto similarity = day1::getSimilarity(locationListA, locationListB);

        startDay(1);
        std::println("The distance between location lists is: {}", listDistance);
        std::println("The Similarity of the lists is: {}", similarity);
    }

    {
        const auto input = stu::readFile("input/day2.txt");
        const auto numSafeReports = day2::countSafeReports(input.c_str());

        startDay(2);
        std::println("The number of safe reports is: {}", numSafeReports);
    }
    
    {
        const auto input = stu::readFile("input/day3.txt");
        const auto sumOfMuls = day3::parseMulInput(input);

        startDay(3);
        std::println("The sum of mul expressions is: {}", sumOfMuls);
    }

    return 0;
}