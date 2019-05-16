#ifndef SEARCH_PRIMA_H
#define SEARCH_PRIMA_H 

#endif //SEARCH_PRIMA_H

#include <iostream>
#include "vector"
#include "list"
#include "algorithm"

using namespace std;

class Graph
{
private:
    vector<list<int>> vec;
public:

    int sum = 0;
    vector<pair<int,int>> rezult;
    Graph(const vector<int> &vertices, const vector<int> &edges)
    {
        vec.resize(vertices.size());
        for (int node : vertices) {
            for (int j = 0; j < edges.size(); j = j + 3)
            {
                if (node == edges.at(j))
                {
                    vec[node].push_back(edges.at(j+1));
                    vec[node].push_back(edges.at(j+2));
                    if (node != edges.at(j+1))
                    {
                        vec[edges.at(j+1)].push_back(node);
                        vec[edges.at(j+1)].push_back(edges.at(j+2));
                    }
                }
            }
        }
    }

    void print_list();
    void search_prima();
};
