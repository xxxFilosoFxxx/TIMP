#include <iostream>
#include "vector"
#include "algorithm"
#include "set"
#include "task2-6.h"

using namespace std;

void Graph::print_list() {
    for (int i = 0; i < vec.size(); i ++)
    {
        cout << i << ":";
        for(auto it = vec[i].begin(); it != vec[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

void Graph::search_Prima() {
    if (vec.empty()) throw "No MST!";
    for (int i = 0; i < vec.size(); i++)
    {
        rezult.emplace_back(-1, -1);
    }

    set<pair<int, int> > q;
    int min_e[vec.size()];
    for (int i = 0; i < vec.size(); i++)
    {
        min_e[i] = INT_MAX;
    }
    min_e[0] = 0;

    q.insert(make_pair(0,0));

    for (int i = 0; i < vec.size(); i++)
    {
        rezult[i].first = i;
        int v = q.begin()->second;
        q.erase(q.begin());
        int weight = 0;
        for (int j = 0, z = 0; j < vec[v].size(), z < vec[v].size(); j++, z = z + 2)
        {
            auto it = vec[v].begin();
            advance(it,z);
            int to = *it;

            advance(it,1);
            weight = *it;

            if (weight < min_e[to] && i != vec.size()-1)
            {
                q.erase(make_pair(min_e[to],to));
                min_e[to] = weight;
                rezult[to].second = v;
                q.insert(make_pair(min_e[to],to));
            }
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (min_e[i] < INT_MAX)
            sum += min_e[i];
    }

    for (auto it2 = rezult.begin(); it2 !=rezult.end(); it2++)
    {
        if (it2->second == -1)
            rezult.erase(it2);
    }
}

