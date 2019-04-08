#ifndef TIMP_OSTTREE_H
#define TIMP_OSTTREE_H

#endif //TIMP_OSTTREE_H

#include <iostream>
#include <stdio.h>
#include "vector"
#include "algorithm"

using namespace std;

class Graph
{
private:
    const int V = 10000000;  // Количество вершин
    const int E = 10000;  // Количество рёбер
    vector < pair < int, pair<int, int > > > graph;  // Вес, Направление из первой вершины, Направление из второй вершины
    std::vector<int> tree_id ; // Множество вершин в форме чисел

public:
    vector<pair<int, int> > result;
    int sum = 0;
    const int vertex()
    {
        return this->V;
    }

    const int node()
    {
        return this->E;
    }

    Graph(){}
    Graph(int from, int to, int weight)
    {
        add_node(from, to, weight);
    }

    void add_node(int from, int to, int weight);
    int find(int v);
    void Union (int x, int y);
    void KruskalPoisk ();

};









