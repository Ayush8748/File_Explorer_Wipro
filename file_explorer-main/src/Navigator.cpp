#include "Navigator.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

Navigator::Navigator() {
    currentPath = fs::current_path().string();
}

void Navigator::listFiles() const {
    std::cout << "Listing: " << currentPath << "\n";
    for (const auto& entry : fs::directory_iterator(currentPath)) {
        std::cout << (entry.is_directory() ? "[DIR]  " : "       ");
        std::cout << entry.path().filename().string() << "\n";
    }
}

bool Navigator::changeDirectory(const std::string& dir) {
    fs::path newPath = fs::path(currentPath) / dir;
    if (fs::exists(newPath) && fs::is_directory(newPath)) {
        currentPath = fs::canonical(newPath).string();
        fs::current_path(currentPath);
        return true;
    }
    std::cerr << "Error: Directory not found\n";
    return false;
}

std::string Navigator::getCurrentPath() const {
    return currentPath;
}

