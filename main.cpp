#include "HtmlValidator.h"

int main() {
    std::string filePath;
    std::cout << "Enter the path to the HTML file: ";
    std::cin >> filePath;

    HtmlValidator htmlValidator(filePath);

    if (htmlValidator.validateHtml()) {
        std::cout << "Validation successful." << std::endl;
    }
    else {
        std::cerr << "Validation failed." << std::endl;
    }

    return 0;
}
