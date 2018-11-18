//
// Created by Andy on 2018/11/18.
//

#ifndef KNAPSACK_DYNAMICKNAPSACK01_H
#define KNAPSACK_DYNAMICKNAPSACK01_H

#include <vector>
using namespace std;

int dynamicKnapsack01(const vector<int>& w, const vector<int>& v, int c)
{
    size_t n = w.size();
    if(n == 0 || c == 0)
        return 0;

    vector<vector<int>> memo( n, vector<int>(c+1 ,-1) );

    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= c; ++j)
        {
            if(i == 0) //第一行初始化
            {
                memo[0][j] = (j >= w[0]) ? v[0] : 0;
                continue;
            }

            memo[i][j] = memo[i-1][j];
            if(j >= w[i])
                memo[i][j] = max( memo[i][j] , v[i] + memo[i-1][j-w[i]] );
        }

    return memo[n-1][c];
}

#endif //KNAPSACK_DYNAMICKNAPSACK01_H
