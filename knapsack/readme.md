## 状态转移方程
- F(n,c) 考虑将n个物品放入容量为c的背包中，使得背包中所放物品价值最大。
- F(i,c) = max( F(i-1, c), v(i) + F(i-1, c-w(i)) ) ,其中v(i)--value_i, w(i)--weight_i