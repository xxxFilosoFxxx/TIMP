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
    std::string str = "1,2,3,4,5,6,7,8,ab,ff,dl,qm";
    std::string str1 = str;
    std::vector<char> vect_versh;
    std::vector<char> vect_edge;

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
        vect_versh.push_back(i);
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
        vect_edge.push_back(i);
    }


    for (i=0; i< vect_versh.size(); i++)
        std::cout << vect_versh.at(i)<<" ";

    cout<<endl;
    for (i=0; i< vect_edge.size(); i++)
        std::cout << vect_edge.at(i)<< " ";

    cout<<endl;

return 0;
}