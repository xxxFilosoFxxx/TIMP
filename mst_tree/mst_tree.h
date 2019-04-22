#ifndef OST_TREE_H
#define OST_TREE_H

#endif //OST_TREE_H

#include <iostream>
#include "vector"
#include "algorithm"
#include "ctime"

using namespace std;

class Graph
{
private:
    const int E = 10000; // Number of links between vertices (edges)
    const int V = 8000;  // Number of vertices
    vector<pair<int, pair<int, int>>> graph;  // weight, from, to
    std::vector<int> tree_id;
public:
    vector<pair<int, int>> result;
    int sum = 0;
    const int node()
    {
        return this->E;
    }
    const int vertex()
    {
        return this->V;
    }

    Graph(){}

    void add_node(int from, int to, int weight);
    int find(int v);
    void union_vertices(int x, int y);
    void kruskal_search();
};









