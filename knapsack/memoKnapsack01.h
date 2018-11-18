//
// Created by Andy on 2018/11/18.
//

#ifndef KNAPSACK_MEMOKNAPSACK01_H
#define KNAPSACK_MEMOKNAPSACK01_H

#include <vector>
using namespace std;

int bestValue(const vector<int>& w, const vector<int>& v, int i, int c, vector<vector<int>>& memo)
{
    if(c <= 0 || i < 0)
        return 0;

    if(memo[i][c] != -1)
        return memo[i][c];

    int res = bestValue(w, v, i-1, c, memo);
    if(c >= w[i])
        res = max( res , v[i] + bestValue(w, v, i-1, c-w[i], memo) );

    memo[i][c] = res;
    return res;
}

int memoKnapsack01(const vector<int>& w, const vector<int>& v, int c)
{
    auto n = w.size();

    vector<vector<int>> memo( n, vector<int>(c+1, -1) );

    return bestValue(w, v, n-1, c, memo);
}

#endif //KNAPSACK_MEMOKNAPSACK01_H
