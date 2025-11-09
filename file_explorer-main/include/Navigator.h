#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <string>

class Navigator {
private:
    std::string currentPath;

public:
    Navigator();
    void listFiles() const;
    bool changeDirectory(const std::string& dir);
    std::string getCurrentPath() const;
};

#endif

