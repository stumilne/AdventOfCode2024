#include <algorithm>
#include <iostream>
#include <print>
#include <vector>

#include "Day1.h"
#include "Utils.h"


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

    return 0;
}