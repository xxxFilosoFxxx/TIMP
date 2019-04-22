#include <iostream>
#include "vector"
#include "algorithm"
#include "ctime"
#include "mst_tree.h"

using namespace std;

void Graph::add_node(int from, int to, int weight) {
    graph.emplace_back(weight, make_pair(from,to));
}

int Graph::find(int v) {
    return (v == tree_id[v]) ? v : (tree_id[v] = find(tree_id[v]));
}

void Graph::union_vertices(int x, int y) {
    x = find(x);
    y = find(y);
    if (rand() & 1)
        swap (x, y);
    if (x != y)
        tree_id[x] = y;
}

void Graph::kruskal_search() {
    // Quick sort. Complexity on average is O( n*log(n) ), but in the worst case O( n*n )
    sort(graph.begin(), graph.end());
    tree_id.resize(vertex());

    for (int i = 0; i < vertex(); i++)
    {
        tree_id[i] = i;
    }

    for (int i = 0; i < graph.size(); i++)
    {
        int from = graph[i].second.first,  to = graph[i].second.second,  weight = graph[i].first;
        if (find(from) != find(to))
        {
            sum += weight;
            result.push_back(graph[i].second);
            union_vertices(from, to);
        }
    }

    //*************************************
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i].first << " " << result[i].second << endl;
    // }
    // cout << sum << endl;
}


