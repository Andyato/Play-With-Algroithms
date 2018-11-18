//
// Created by Andy on 2018/11/18.
//

#ifndef KNAPSACK_LEASTSPACEKNAPSACK01_H
#define KNAPSACK_LEASTSPACEKNAPSACK01_H

#include <vector>
using namespace std;

int leastSpaceKnapsack01(const vector<int>& w, const vector<int>& v, int c)
{
    size_t n = w.size();
    if(n == 0 || c == 0)
        return 0;

    vector<int> memo(c+1, -1);

    for(int j = 0; j <= c; ++j)
        memo[j] = j > w[0] ? v[0] : 0;

    for(int i = 0; i < n; ++i)
        for(int j = c; j >= w[i]; --j)
            memo[j] = max( memo[j], v[i] + memo[j-w[i]] );

    return memo[c];
}

#endif //KNAPSACK_LEASTSPACEKNAPSACK01_H
