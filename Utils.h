#pragma once

#include <functional>
#include <string>

namespace stu
{
    std::string readFile(const char* inFilename);

    void doPerLine(const char* inInput, std::function<void(const std::string&)> inFunc);
}