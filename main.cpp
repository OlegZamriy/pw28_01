#include "FileHandler.h"

int main() {
    std::string filePath;
    std::cout << "Enter the path to the file: ";
    std::cin >> filePath;

    FileHandler fileHandler(filePath);

    std::cout << "\n1. Search and display\n"
        << "2. Replace\n"
        << "3. Display file\n"
        << "4. Reverse content\n"
        << "Enter your choice (1-4): ";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1: {
        std::string searchString;
        std::cout << "Enter the string to search: ";
        std::cin >> searchString;
        fileHandler.searchAndDisplay(searchString);
        break;
    }
    case 2: {
        std::string searchString, replacement;
        std::cout << "Enter the string to replace: ";
        std::cin >> searchString;
        std::cout << "Enter the replacement string: ";
        std::cin >> replacement;
        if (fileHandler.replace(searchString, replacement)) {
            std::cout << "String replaced successfully." << std::endl;
        }
        else {
            std::cerr << "String not found in the file." << std::endl;
        }
        break;
    }
    case 3:
        fileHandler.displayFile();
        break;
    case 4:
        fileHandler.reverseContent();
        std::cout << "Content reversed and updated in the file." << std::endl;
        break;
    default:
        std::cerr << "Invalid choice." << std::endl;
    }

    return 0;
}
