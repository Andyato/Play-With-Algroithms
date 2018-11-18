#include <iostream>
#include "knapsack01.h"
#include "memoKnapsack01.h"
#include "dynamicKnapsack01.h"
#include "lessSpaceKnapsack01.h"

int main() {
    vector<int> w = {1,2,3};
    vector<int> v = {6,10,12};

    for(int c = 0; c <= 6; ++c)
    {
        std::cout << "c = " << c << " :: ";
        std::cout << "knapesack01 : " << knapesack01(w, v, c) << "  ";
        std::cout << "memoKnapsack01 : " << memoKnapsack01(w, v, c) << "  ";
        std::cout << "dynamicKnapsack01 : " << dynamicKnapsack01(w, v, c) << "  ";
        std::cout << "lessSpaceKnapsack01 : " << lessSpaceKnapsack01(w, v, c) << std::endl;
    }

    return 0;
}