#include <iostream>
#include "vector"
#include "sstream"
#include "algorithm"
#include "task2-5.h"

using namespace std;

int main()
{

    std::string str = "a,b,c,d,e,f,g,h,ab,ff,ca,be,fh";
    std::string str1 = str;
    std::vector<int> vect_versh;
    std::vector<int> vect_edge;
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
                vect_versh.push_back(j);
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
                vect_edge.push_back(j);
        }
    }


    for (int i1=0; i1< vect_versh.size(); i1++)
        std::cout << vect_versh.at(i1)<<" ";

    cout<<endl;
    for (int i1=0; i1< vect_edge.size(); i1++)
        std::cout << vect_edge.at(i1)<< " ";

    cout << endl << "----------------" << endl;
    Graph g(vect_versh, vect_edge);
    g.print_list();

    cout<<endl;

    g.search_graph_wide();

   /*vector<list<int>> vec(2);
   vec[0].push_back(15);
   vec[0].push_back(7);
   vec[1].push_back(10);
   vec[1].push_back(20);

   for (int i = 0; i < vec.size(); i ++)
   {
       list<int>::iterator it;
       for (it = vec[i].begin(); it != vec[i].end(); ++it)
           cout << *it << " ";
       cout << endl;
   }*/
    return 0;
}