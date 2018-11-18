#include <iostream>
#include "BinarySearch.h"

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int index = binarySearch(arr, 10, 3);
    std::cout << index  << std::endl;
    return 0;
}