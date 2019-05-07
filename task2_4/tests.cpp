#include <iostream>
#include "vector"
#include "fstream"
#include "algorithm"
#include "task2-4.h"
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

using namespace std;

TEST_CASE("Test1", "task2-4_Tests")
{
    vector<int> vec;
    int number;

    fstream fin;
    fin.open("..\\task2_4\\in.txt", ios_base::in);

   /* if (!fin.is_open())
    {
        cout << "Error opening file!" << endl;
        return -1;
    }*/

    while(!fin.eof())
    {
        fin >> number;
        vec.push_back(number);
    }
    fin.close();

    vec = Digit_sort(vec);

    // TODO
}
