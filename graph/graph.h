#ifndef GRAPH_H
#define GRAPH_H 

#endif //GRAPH_H

#include <iostream>
#include "vector"
#include "list"
#include "queue"

using namespace std;

class Graph
{
private:
    vector<list<int>> vec;

public:
    Graph(const vector<int> &vertices, const vector<int> &edges)
    {
        vec.resize(vertices.size());
        for (int node : vertices) {
            for (int j = 0; j < edges.size(); j = j + 2)
            {
                if (node == edges.at(j))
                {
                    vec[node].push_back(edges.at(j+1));
                    if (node != edges.at(j+1))
                    {
                        vec[edges.at(j+1)].push_back(node);
                    }
                }
            }
        }
    }

    void print_list();
    vector<int> search_graph_wide(int vertex);
    int find_components();
};

