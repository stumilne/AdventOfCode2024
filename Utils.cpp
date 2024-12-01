#include "Utils.h"

#include <filesystem>
#include <fstream>
#include <string>

namespace stu
{
    std::string stu::readFile(const char* inFilename)
    {
        std::filesystem::path path{ inFilename };
        std::ifstream f(path, std::ios::in | std::ios::binary);
        const auto sizeBytes = std::filesystem::file_size(path);
        std::string result(sizeBytes, '\0');
        f.read(result.data(), sizeBytes);

        return result;
    }
}
