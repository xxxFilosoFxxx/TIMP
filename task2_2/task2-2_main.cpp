#include <iostream>
#include <time.h>
#include "vector"
#include <algorithm>
#include "sstream"
#include "../DDZ/OstTree.h"

using namespace std;

int main()
{
 /*   int **mas = new int*[20];
    for(int i = 0; i < 20; i++)
    {
        mas[i] = new int(i);
        cout << mas[i] << ' ';
    }
    for (int i = 0; i < 20; i++)
    {
        delete mas[i];
    }
    delete [] mas;

*/
   //TODO переделка для неор графа
    std::string str = "a,b,c,d,e,f,g,h,ab10,ff20,dl30,qm40";
    std::string str1 = str;
    std::vector<int> vect_versh;
    std::vector<int> vect_edge;
    vector<int> vect_diiich;

    int mas[26];
    for (int i = 0; i < 26; i++)
    {
        mas[i] = i;
    }

    std::stringstream ss(str);
    char i;
    int r;
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
            {
                vect_edge.push_back(j);
                str1.erase(str1.find(i), 1);
            }
        }
    }

    std::stringstream ss2(str1);

    while (ss2 >> r)
    {
        if (ss2.peek() == ',')
        {
            ss2.ignore();
        }
        vect_diiich.push_back(r);
    }

    for (i=0; i< vect_versh.size(); i++)
        std::cout << vect_versh.at(i)<<" ";

    cout<<endl;
    for (i=0; i< vect_edge.size(); i++)
        std::cout << vect_edge.at(i)<< " ";
    cout << endl;

    for (i=0; i< vect_diiich.size(); i++)
        std::cout << vect_diiich.at(i)<< " ";

    cout<<endl;

return 0;
}