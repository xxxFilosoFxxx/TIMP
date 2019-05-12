#include <iostream>
#include "vector"
#include "sstream"
#include "algorithm"
#include "graph.h"

using namespace std;

int main()
{
    std::string str = "a,b,c,d,e,f,g,h,ab,ff,ca,be,fh";
    std::string str1 = str;
    std::vector<int> vertices;
    std::vector<int> edges;
    int mas[26];
    for (int i = 0; i < 26; i++)
    {
        mas[i] = i;
    }

    std::stringstream ss(str);
    char i;
    int count = 0, k = 0;

    while (ss >> i)
    {
        if (ss.peek() == ',')
        {
            k++;
            ss.ignore();
        }

        if (count > k - 1)
            break;
        count++;

        for (int j = 0; j < 26; j++)
        {
            if (mas[j] == ((int)i - 97))
                vertices.push_back(j);
        }
    }

    str1.erase(str1.begin(), str1.end() - (str1.size() - 2*count));
    std::string str2 = str1;

    std::stringstream ss1(str1);

    while (ss1 >> i)
    {
        if (ss1.peek() == ',')
        {
            ss1.ignore();
        }
        for (int j = 0; j < 26; j++)
        {
            if (mas[j] == ((int)i - 97))
                edges.push_back(j);
        }
    }


    for (int i1=0; i1< vertices.size(); i1++)
        std::cout << vertices.at(i1)<<" ";

    cout<<endl;
    for (int i1=0; i1< edges.size(); i1++)
        std::cout << edges.at(i1)<< " ";

    cout << endl << "----------------" << endl;
    Graph g(vertices, edges);
    g.print_list();

    cout<<endl;

    vector<int> print = g.search_graph_wide(vertices[3]);
    for (auto i3 = print.begin(); i3 < print.end(); i3++)
        std::cout << *i3 << " ";

    int comp = g.find_components();
    cout << endl << comp;

    return 0;
}
