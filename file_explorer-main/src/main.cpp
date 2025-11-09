#include "Navigator.h"
#include "FileManager.h"
#include "Utils.h"
#include <iostream>
#include <sstream>

int main() {
    Navigator nav;
    std::string command;

    std::cout << "=== Linux File Explorer ===\n";
    std::cout << "Commands: ls, cd <dir>, create <file>, del <file>, cp <src> <dest>, mv <src> <dest>\n";
    std::cout << "          search <name>, perm <file>, chmod <file> <octal>, exit\n";

    while (true) {
        std::cout << "[" << nav.getCurrentPath() << "]$ ";
        std::getline(std::cin, command);
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "ls") nav.listFiles();
        else if (cmd == "cd") {
            std::string dir; iss >> dir;
            nav.changeDirectory(dir);
        }
        else if (cmd == "create") {
            std::string file; iss >> file;
            FileManager::createFile(file);
        }
        else if (cmd == "del") {
            std::string file; iss >> file;
            FileManager::deleteFile(file);
        }
        else if (cmd == "cp") {
            std::string src, dest; iss >> src >> dest;
            FileManager::copyFile(src, dest);
        }
        else if (cmd == "mv") {
            std::string src, dest; iss >> src >> dest;
            FileManager::moveFile(src, dest);
        }
        else if (cmd == "search") {
            std::string name; iss >> name;
            Utils::searchFile(nav.getCurrentPath(), name);
        }
        else if (cmd == "perm") {
            std::string file; iss >> file;
            FileManager::showPermissions(file);
        }
        else if (cmd == "chmod") {
            std::string file, mode; iss >> file >> mode;
            FileManager::setPermissions(file, mode);
        }
        else if (cmd == "exit") break;
        else std::cout << "Unknown command.\n";
    }
}

