//
// Created by Andy on 2018/11/18.
//

#ifndef KNAPSACK_LESSSPACEKNAPSACK01_H
#define KNAPSACK_LESSSPACEKNAPSACK01_H

#include <vector>
using namespace std;

// 优化空间占用，只需保留两行memo
int lessSpaceKnapsack01(const vector<int>& w, const vector<int>& v, int c)
{
    int n = w.size();
    if(n == 0)
        return 0;

    vector<vector<int>> memo(2, vector<int>(c+1, -1) );

    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= c; ++j)
        {
            if(i == 0)
            {
                memo[0][j] = (j >= w[0]) ? v[0] : 0;
                continue;
            }

            memo[i%2][j] = memo[(i-1)%2][j];
            if(j >= w[i])
                memo[i%2][j] = max( memo[i%2][j], v[i] + memo[(i-1)%2][j-w[i]] );
        }
    return memo[(n-1)%2][c];
}

#endif //KNAPSACK_LESSSPACEKNAPSACK01_H
