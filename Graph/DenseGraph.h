//
// Created by Andy on 2018/11/1.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 稠密图 - 邻接矩阵
class DenseGraph
{
private:
    int n, m; //n:点数 m:边数
    bool directed;
    vector<vector<bool>> g;

public:
    DenseGraph(int n, bool d) : n(n), directed(d), m(0)
    {
        for(int i = 0; i < n; ++i)
            g.push_back( vector<bool>(n, false) );
    }

    ~DenseGraph() {}

    int V() { return n; }
    int E() { return m; }

    void addEdge(int v, int w)
    {
        assert( 0 <= v && v < n);
        assert( 0 <= w && w < n);

        if(hasEdge(v, w))
            return;

        g[v][w] = true;
        if(directed == false)
            g[w][v] = true;
        ++m;
    }

    bool hasEdge(int v, int w)
    {
        assert( 0 <= v && v < n);
        assert( 0 <= w && w < n);

        return g[v][w];
    }
};

#endif //GRAPH_DENSEGRAPH_H
