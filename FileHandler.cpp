#include "FileHandler.h"

FileHandler::FileHandler(const std::string& path) : filePath(path) {}

FileHandler::~FileHandler() {
    closeFile();
}

bool FileHandler::openFile() {
    fileStream = std::make_shared<std::ifstream>(filePath);
    return fileStream->is_open();
}

void FileHandler::closeFile() {
    if (fileStream && fileStream->is_open()) {
        fileStream->close();
    }
}

bool FileHandler::searchAndDisplay(const std::string& searchString) {
    if (!fileStream || !fileStream->is_open()) {
        std::cerr << "File is not open." << std::endl;
        return false;
    }

    std::string line;
    int lineNumber = 0;
    int occurrences = 0;

    while (std::getline(*fileStream, line)) {
        lineNumber++;
        size_t pos = line.find(searchString);
        if (pos != std::string::npos) {
            occurrences++;
            std::cout << "Line " << lineNumber << ": " << line << std::endl;
        }
    }

    std::cout << "Search statistics: Total occurrences: " << occurrences << std::endl;
    return true;
}

bool FileHandler::replace(const std::string& searchString, const std::string& replacement) {
    if (!fileStream || !fileStream->is_open()) {
        std::cerr << "File is not open." << std::endl;
        return false;
    }

    std::string content((std::istreambuf_iterator<char>(*fileStream)), std::istreambuf_iterator<char>());
    size_t pos = content.find(searchString);

    if (pos != std::string::npos) {
        content.replace(pos, searchString.length(), replacement);

        closeFile();
        std::ofstream outFile(filePath);
        outFile << content;
        outFile.close();

        return true;
    }

    return false;
}

void FileHandler::displayFile() {
    if (openFile()) {
        std::string line;
        while (std::getline(*fileStream, line)) {
            std::cout << line << std::endl;
        }
        closeFile();
    }
}

void FileHandler::reverseContent() {
    if (openFile()) {
        std::string content((std::istreambuf_iterator<char>(*fileStream)), std::istreambuf_iterator<char>());
        closeFile();

        std::reverse(content.begin(), content.end());

        std::ofstream outFile(filePath);
        outFile << content;
        outFile.close();
    }
}
