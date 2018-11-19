//
// Created by Andy on 2018/11/19.
//

#ifndef LONGESTCOMMONSEQUENCE_LCS_H
#define LONGESTCOMMONSEQUENCE_LCS_H

#include <string>
using namespace std;

int __LCS(const string& s1, const string& s2, int m, int n)
{
    if(m < 0 || n < 0)
        return 0;

    if(s1[m] == s2[n])
        return 1 + __LCS(s1, s2, m-1, n-1);
    else
        return max( __LCS(s1, s2, m-1, n), __LCS(s1, s2, m, n-1) );
}

int LCS(const string& s1, const string& s2)
{
    int m = s1.size()-1;
    int n = s2.size()-1;

    return __LCS(s1, s2, m, n);
}

#endif //LONGESTCOMMONSEQUENCE_LCS_H
