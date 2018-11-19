//
// Created by Andy on 2018/11/19.
//

#ifndef LONGESTCOMMONSEQUENCE_DYNAMICLCS_H
#define LONGESTCOMMONSEQUENCE_DYNAMICLCS_H

#include <vector>
#include <string>
using namespace std;

int dynamicLCS(const string& s1, const string& s2)
{
    int m = s1.size();
    int n = s2.size();

    if(m < 0 || n < 0)
        return 0;

    vector<vector<int>> memo(m+1, vector<int>(n+1, 0));

    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(s1[i] == s2[j])
                memo[i][j] = 1 + memo[i-1][j-1];
            else
                memo[i][j] = max( memo[i-1][j], memo[i][j-1] );
        }

    return memo[m][n];
}

#endif //LONGESTCOMMONSEQUENCE_DYNAMICLCS_H
