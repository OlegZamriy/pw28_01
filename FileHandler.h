#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

class FileHandler {
private:
    std::string filePath;
    std::shared_ptr<std::ifstream> fileStream;

public:
    FileHandler(const std::string& path);
    ~FileHandler();

    bool openFile();
    void closeFile();

    bool searchAndDisplay(const std::string& searchString);
    bool replace(const std::string& searchString, const std::string& replacement);
    void displayFile();
    void reverseContent();
};

#endif // FILE_HANDLER_H
