#include <iostream>
#include "vector"
#include "fstream"
#include "algorithm"
#include "digital_sort.h"

using namespace std;

int main()
{
    vector<int> vec;
    int number;

    fstream fin;
    #ifdef _WIN32
      fin.open("..\\sort\\in.txt", std::ios_base::in);
    #else
      fin.open("../sort/in.txt", std::ios_base::in);
    #endif

    if (!fin.is_open())
    {
        cout << "Error opening file!" << endl;
        return -1;
    }

    else{
        while(!fin.eof())
        {
            fin >> number;
            vec.push_back(number);
        }
    }
    fin.close();
    auto it = vec.begin();
    for (; it!= vec.end(); it++)
        cout << *it << ' ';

    digit_sort(vec);
    cout << endl;
    for (int i : vec)
        cout << i << ' ';

    return 0;
}
