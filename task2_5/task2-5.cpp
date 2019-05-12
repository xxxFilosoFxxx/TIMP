#include <iostream>
#include "vector"
#include "queue"
#include "task2-5.h"
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

vector<int> Graph::search_graph_wide(int vertex) {
    vector<int> _nodes;
    queue<int> Queue;
    int nodes[vec.size()]; // вершины графа
    int color[3] = {0, 1, 2}; // 0->white; 1->gray; 2->black
    for (int i = 0; i < vec.size(); i++)
        nodes[i] = color[0]; // исходно все вершины white
    Queue.push(vertex); // помещаем в очередь первую вершину
    while (!Queue.empty())
    {
        int node = Queue.front(); // извлекаем вершину
        Queue.pop();
        nodes[node] = color[2]; // отмечаем ее black
        for(auto it = vec[node].begin(); it != vec[node].end(); it++)
        {
            for (int j = 0; j < vec.size(); j++) // проверяем для нее все смежные вершины
            {
                if (*it == j && nodes[j] == color[0]) // если вершина смежная и не обнаружена
                {
                    Queue.push(j); // добавляем ее в очередь
                    nodes[j] = color[1]; // отмечаем вершину как обнаруженную
                }
            }
        }
        _nodes.push_back(node); // заносим номер вершины
       // cout << node << endl; // выводим номер вершины
    }
    return _nodes;
}

int Graph::find_components() {
    int components = 0;
    vector<int> count, check;
    bool use[vec.size()];

    count = search_graph_wide(0);
    components++;
    for (auto it = count.begin(); it < count.end(); it++)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (*it == i)
                use[i] = true;
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (!use[i])
        {
            count.push_back(-1);
            check = search_graph_wide(i);
            if (check.size() != 1)
            {
                for (auto it = check.begin(); it < check.end(); it++)
                {
                    for (int j = 0; j < vec.size(); j++)
                    {
                        if (*it == j)
                            use[j] = true;
                    }
                }
            }
            else
            {
                use[i] = true;
            }
            components++;
        }
    }
    return components;
}
