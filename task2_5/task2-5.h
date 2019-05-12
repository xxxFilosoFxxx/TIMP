#ifndef TIMP_TASK2_5_H
#define TIMP_TASK2_5_H

#endif //TIMP_TASK2_5_H

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
    Graph(const vector<int> &vect_versh, const vector<int> &vect_edge)
    {
        vec.resize(vect_versh.size());
        for (int node : vect_versh) {
            for (int j = 0; j < vect_edge.size(); j = j + 2)
            {
                if (node == vect_edge.at(j))
                {
                    vec[node].push_back(vect_edge.at(j+1));
                    if (node != vect_edge.at(j+1))
                    {
                        vec[vect_edge.at(j+1)].push_back(node);
                    }
                }
            }
        }
    }
    void print_list();
    vector<int> search_graph_wide(int vertex);
    int find_components();

};

