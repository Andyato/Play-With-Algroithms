## 状态定义
LCS(m,n) 表示：S1[0...m] 和 S2[0...n]的最长公共子序列的长度
- S1[m] == S2[n]: LCS(m,n) = 1 + LCS(m-1, n-1)
- S1[m] != S2[n]: LCS(m,n) = max{ LCS(m-1,n), LCS(m,n-1) };