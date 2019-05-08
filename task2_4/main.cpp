#include <iostream>
#include "vector"
#include "fstream"
#include "algorithm"
#include "task2-4.h"

using namespace std;

int main()
{
    vector<int> vec;
    int number;

    fstream fin;
    fin.open("..\\task2_4\\in.txt", ios_base::in);

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

    Digit_sort(vec);
    cout << endl;
    for (int i : vec)
        cout << i << ' ';

    return 0;
}