#include <iostream>
#include "vector"
#include "queue"
#include "fstream"
#include "algorithm"

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
        cout << *it << endl;

    auto it1 = max_element(vec.begin(), vec.end());
    cout<< *it1 << endl;

    int i = 0;
    while(*it1 >0)
    {
        *it1 = *it1 / 10;
        ++i;
    }
    cout << i << endl;

    return 0;
}