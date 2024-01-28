#include "smart_ptr.h"
#include <iostream>

int main() {
    SmartUniquePtr<int> uniquePtr(new int(42));
    std::cout << "SmartUniquePtr value: " << *uniquePtr << std::endl;

    SmartSharedPtr<int> sharedPtr1(new int(10));
    SmartSharedPtr<int> sharedPtr2 = sharedPtr1;
    SmartSharedPtr<int> sharedPtr3(new int(20));

    std::cout << "Shared pointer 1 value: " << *sharedPtr1 << ", Use count: " << sharedPtr1.useCount() << std::endl;
    std::cout << "Shared pointer 2 value: " << *sharedPtr2 << ", Use count: " << sharedPtr2.useCount() << std::endl;
    std::cout << "Shared pointer 3 value: " << *sharedPtr3 << ", Use count: " << sharedPtr3.useCount() << std::endl;

    return 0;
}
