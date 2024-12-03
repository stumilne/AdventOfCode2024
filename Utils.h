#pragma once

#include <functional>
#include <string>

#ifdef _DEBUG
#include <print>
#define LogDebug(...) std::println(__VA_ARGS__)
#else
#define LogDebug(x)
#endif

namespace stu
{
    std::string readFile(const char* inFilename);

    void doPerLine(const char* inInput, std::function<void(const std::string&)> inFunc);
}