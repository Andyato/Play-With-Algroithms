//
// Created by Andy on 2018/11/18.
//

#ifndef KNAPSACK_KNAPSACK01_H
#define KNAPSACK_KNAPSACK01_H

#include<vector>
using namespace std;

int bestValue(const vector<int>& w, const vector<int>& v, int i, int c)
{
    if(c <= 0 || i < 0)
        return 0;

    int res = bestValue(w, v, i-1, c);
    if(c >= w[i])
        res = max(res, v[i] + bestValue(w, v, i-1, c-w[i]) );

    return res;
}

int knapesack01(const vector<int>& w, const vector<int>& v, int c)
{
    int n = w.size();

    return bestValue(w, v, n-1, c);
}

#endif //KNAPSACK_KNAPSACK01_H
