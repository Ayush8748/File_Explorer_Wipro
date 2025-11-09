#include "FileManager.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

namespace fs = std::filesystem;

bool FileManager::createFile(const std::string& path) {
    std::ofstream file(path);
    if (file) {
        std::cout << "File created: " << path << "\n";
        return true;
    }
    std::cerr << "Error creating file.\n";
    return false;
}

bool FileManager::deleteFile(const std::string& path) {
    if (fs::remove(path)) {
        std::cout << "Deleted: " << path << "\n";
        return true;
    }
    std::cerr << "Error deleting file.\n";
    return false;
}

bool FileManager::copyFile(const std::string& src, const std::string& dest) {
    try {
        fs::copy(src, dest, fs::copy_options::overwrite_existing);
        std::cout << "Copied to " << dest << "\n";
        return true;
    } catch (...) {
        std::cerr << "Error copying file.\n";
        return false;
    }
}

bool FileManager::moveFile(const std::string& src, const std::string& dest) {
    try {
        fs::rename(src, dest);
        std::cout << "Moved to " << dest << "\n";
        return true;
    } catch (...) {
        std::cerr << "Error moving file.\n";
        return false;
    }
}

void FileManager::showPermissions(const std::string& path) {
    struct stat info;
    if (stat(path.c_str(), &info) == 0) {
        std::cout << "Permissions: " << std::oct << (info.st_mode & 0777) << std::dec << "\n";
    } else {
        std::cerr << "Error reading permissions.\n";
    }
}

void FileManager::setPermissions(const std::string& path, const std::string& perms) {
    mode_t mode = std::stoi(perms, nullptr, 8);
    if (chmod(path.c_str(), mode) == 0)
        std::cout << "Permissions updated.\n";
    else
        std::cerr << "Error setting permissions.\n";
}
