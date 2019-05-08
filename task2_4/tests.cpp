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

    vector<int> vec1;
    vec1 = vec;
    Digit_sort(vec1);
    REQUIRE(vec1[0] == 1);
    REQUIRE(vec1[0] != vec[0]);
    REQUIRE(vec1.size() == vec.size());
    REQUIRE(vec1[10] == 1000);
    REQUIRE(vec1[10] == vec[4]);
}
