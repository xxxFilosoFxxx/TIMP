#include <iostream>
#include "vector"
#include "sstream"
#include "algorithm"
#include "task2-6.h"

using namespace std;

int main()
{
    string str = "a,b,c,d,e,ab10,ac20,cd30,ad10,bc15,de40,ce60";
    string str1 = str;
    vector<int> vect_versh;
    vector<int> vect_edge;
    vector<int> vect_weight;

    int mas[26];
    for (int i = 0; i < 26; i++)
    {
        mas[i] = i;
    }

    stringstream ss(str);
    char ch;
    int num;
    int count = 0, k = 0;

    while (ss >> ch)
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
            if (mas[j] == ((int)ch - 97))
                vect_versh.push_back(j);
        }
    }

    str1.erase(str1.begin(), str1.end() - (str1.size() - 2*count));
    std::stringstream ss1(str1);

    while (ss1 >> ch)
    {
        if (ss1.peek() == ',')
        {
            ss1.ignore();
        }
        for (int j = 0; j < 26; j++)
        {
            if (mas[j] == ((int)ch - 97))
            {
                vect_edge.push_back(j);
                str1.erase(str1.find(ch), 1);
            }
        }

    }

    std::stringstream ss2(str1);

    while (ss2 >> num)
    {
        if (ss2.peek() == ',')
        {
            ss2.ignore();
        }
        vect_weight.push_back(num);
    }

    for (int i = 2, j = 0; i < vect_edge.size(), j < vect_weight.size(); i = i + 3, j++)
    {
        vect_edge.insert(vect_edge.begin() + i, vect_weight.at(j));
    }

    for (int i=0; i< vect_versh.size(); i++)
        std::cout << vect_versh.at(i)<<" ";

    cout<<endl;
    for (int i=0; i< vect_edge.size(); i++)
        std::cout << vect_edge.at(i)<< " ";
    cout << endl;
    cout << endl;
    cout << endl;


    Graph gr(vect_versh,vect_edge);
    gr.print_list();
    gr.search_Prima();
    cout << endl;
    cout << gr.sum << endl;
    for (int i = 0; i < gr.rezult.size(); i++)
    {
        cout << gr.rezult[i].first << "," << gr.rezult[i].second << " ";
    }

    return 0;
}