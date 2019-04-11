#ifndef TIMP_OSTTREE_H
#define TIMP_OSTTREE_H

#endif //TIMP_OSTTREE_H

#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

class Graph
{
private:
    const int V = 1000;  // Количество вершин
    vector < pair < int, pair<int, int > > > graph;  // Вес, Направление из первой вершины, Направление из второй вершины
    std::vector<int> tree_id;  // Принадлежность вершины тому или иному поддереву
                               // хранится номер дерева, которому она принадлежит
public:
    vector<pair<int, int> > result;
    int sum = 0;
    const int vertex()
    {
        return this->V;
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









