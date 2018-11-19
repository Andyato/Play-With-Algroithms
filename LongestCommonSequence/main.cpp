#include <iostream>
#include <string>
#include "LCS.h"
#include "memoLCS.h"
#include "dynamicLCS.h"

int main() {
    string s1 ;
    string s2 ;
    std::cout << "input two strings please: " << endl;
    std::cin >> s1 >> s2 ;

    std::cout << "LCS: " << LCS(s1, s2) << std::endl;
    std::cout << "memoLCS: " << memoLCS(s1, s2) << std::endl;
    std::cout << "dynamicLCS: " << dynamicLCS(s1, s2) << std::endl;
    return 0;
}