#ifndef TIMP_TASK2_6_H
#define TIMP_TASK2_6_H

#endif //TIMP_TASK2_6_H

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
    Graph(const vector<int> &vect_versh, const vector<int> &vect_edge)
    {
        vec.resize(vect_versh.size());
        for (int node : vect_versh) {
            for (int j = 0; j < vect_edge.size(); j = j + 3)
            {
                if (node == vect_edge.at(j))
                {
                    vec[node].push_back(vect_edge.at(j+1));
                    vec[node].push_back(vect_edge.at(j+2));
                    if (node != vect_edge.at(j+1))
                    {
                        vec[vect_edge.at(j+1)].push_back(node);
                        vec[vect_edge.at(j+1)].push_back(vect_edge.at(j+2));
                    }
                }
            }
        }
    }
    void print_list();
    void search_Prima();
};