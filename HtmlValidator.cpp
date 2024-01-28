#include "HtmlValidator.h"

HtmlValidator::HtmlValidator(const std::string& path) : filePath(path) {}

HtmlValidator::~HtmlValidator() {
    closeFile();
}

bool HtmlValidator::openFile() {
    fileStream = std::make_shared<std::ifstream>(filePath);
    return fileStream->is_open();
}

void HtmlValidator::closeFile() {
    if (fileStream && fileStream->is_open()) {
        fileStream->close();
    }
}

bool HtmlValidator::validateHtml() {
    if (!fileStream || !fileStream->is_open()) {
        std::cerr << "File is not open." << std::endl;
        return false;
    }

    std::stack<char> tagStack;
    std::string line;
    int lineNumber = 0;

    while (std::getline(*fileStream, line)) {
        lineNumber++;

        for (char& ch : line) {
            if (ch == '<') {
                tagStack.push(ch);
            }
            else if (ch == '>') {
                if (tagStack.empty()) {
                    std::cerr << "Error at line " << lineNumber << ": Found closing '>' without corresponding opening '<'" << std::endl;
                    return false;
                }
                tagStack.pop();
            }
        }
    }

    if (!tagStack.empty()) {
        std::cerr << "Error: Some tags are not closed properly." << std::endl;
        return false;
    }

    std::cout << "HTML file is valid." << std::endl;
    return true;
}
