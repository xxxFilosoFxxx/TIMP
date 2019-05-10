#include <iostream>
#include "vector"
#include "queue"
#include "task2-5.h"
using namespace std;

void Graph::print_list() {
    for (int i = 0; i < vec.size(); i ++)
    {
        list<int>::iterator it;
        cout << i << ":";
        for(it = vec[i].begin(); it != vec[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

void Graph::search_graph_wide() {
    queue<int> Queue;
    int nodes[vec.size()]; // вершины графа
    int color[3] = {0, 1, 2}; // 0->white; 1->gray; 2->black
    for (int i = 0; i < vec.size(); i++)
        nodes[i] = color[0]; // исходно все вершины white
    Queue.push(0); // помещаем в очередь первую вершину
    while (!Queue.empty())
    {
        int node = Queue.front(); // извлекаем вершину
        Queue.pop();
        nodes[node] = color[2]; // отмечаем ее black
        list<int>::iterator it;
        for(it = vec[node].begin(); it != vec[node].end(); it++)
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
        cout << node << endl; // выводим номер вершины
    }

}
