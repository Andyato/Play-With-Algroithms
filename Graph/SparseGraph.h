//
// Created by Andy on 2018/11/1.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 稀疏图 - 邻接表
class SparseGraph
{
private:
    int n, m; //n:点数 m:边数
    bool directed;
    vector<vector<int>> g;

public:
    SparseGraph(int n, bool d) : n(n), directed(d), m(0)
    {
        for(int i = 0; i < n; ++i)
            g.push_back( vector<int>() );
    }

    ~SparseGraph() {}

    int V() { return n; }
    int E() { return m; }

    void addEdge(int v, int w)
    {
        assert( 0 <= v && v < n);
        assert( 0 <= w && w < n);

        g[v].push_back(w);
        if(v != w && directed == false) //v != w 避免自环边
            g[w].push_back(v);
        ++m;
    }

    bool hasEdge(int v, int w)
    {
        assert( 0 <= v && v < n);
        assert( 0 <= w && w < n);

        for(int i = 0; i < g[v].size(); ++i)
            if(g[v][i] == w)
                return true;
        return false;
    }
};

#endif //GRAPH_SPARSEGRAPH_H
