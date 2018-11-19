//
// Created by Andy on 2018/11/19.
//

#ifndef LONGESTCOMMONSEQUENCE_MEMOLCS_H
#define LONGESTCOMMONSEQUENCE_MEMOLCS_H

#include <string>
#include <vector>
using namespace std;

int __memoLCS(const string& s1, const string& s2, int m, int n, vector<vector<int>>& memo)
{
    if(m < 0 || n < 0)
        return 0;

    if(memo[m][n] != -1)
        return memo[m][n];

    if(s1[m] == s2[n])
        memo[m][n] = 1 + __memoLCS(s1, s2, m-1, n-1, memo);
    else
        memo[m][n] = max( __memoLCS(s1, s2, m-1, n, memo), __memoLCS(s1, s2, m, n-1, memo) );

    return memo[m][n];
}

int memoLCS(const string& s1, const string& s2)
{
    int m = s1.size()-1;
    int n = s2.size()-1;

    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));

    return __memoLCS(s1, s2, m, n, memo);
}

#endif //LONGESTCOMMONSEQUENCE_MEMOLCS_H
