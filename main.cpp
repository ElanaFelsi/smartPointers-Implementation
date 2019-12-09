#include <iostream>
#include "sharedPointer.h"

int main() {
    SharedPtr<int> ptr1(new int);
    SharedPtr<int> ptr2(new int);
    ptr1 = ptr2;
    return 0;
}