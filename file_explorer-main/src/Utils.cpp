#include "Utils.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void Utils::searchFile(const std::string& directory, const std::string& name) {
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.path().filename().string().find(name) != std::string::npos) {
            std::cout << "Found: " << entry.path().string() << "\n";
        }
    }
}

