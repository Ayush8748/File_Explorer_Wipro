#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>   // ✅ add this line

class FileManager {
public:
    static bool createFile(const std::string& path);
    static bool deleteFile(const std::string& path);
    static bool copyFile(const std::string& src, const std::string& dest);
    static bool moveFile(const std::string& src, const std::string& dest);
    static void showPermissions(const std::string& path);
    static void setPermissions(const std::string& path, const std::string& perms);
};

#endif

