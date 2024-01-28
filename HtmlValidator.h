#ifndef HTML_VALIDATOR_H
#define HTML_VALIDATOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <memory>

class HtmlValidator {
private:
    std::string filePath;
    std::shared_ptr<std::ifstream> fileStream;

public:
    HtmlValidator(const std::string& path);
    ~HtmlValidator();

    bool openFile();
    void closeFile();

    bool validateHtml();
};

#endif // HTML_VALIDATOR_H
