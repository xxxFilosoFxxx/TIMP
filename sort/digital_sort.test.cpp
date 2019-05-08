#include <iostream>
#include "vector"
#include "fstream"
#include "algorithm"
#include "digital_sort.h"

#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

using namespace std;

TEST_CASE("Test1", "[sort]")
{
    vector<int> vec;
    int number;

    fstream fin;
    #ifdef _WIN32
      fin.open("..\\sort\\in.txt", std::ios_base::in);
    #else
      fin.open("../sort/in.txt", std::ios_base::in);
    #endif

    // if (!fin.is_open())
    // {
    //     cout << "Error opening file!" << endl;
    //     return -1;
    // }

    while(!fin.eof())
    {
        fin >> number;
        vec.push_back(number);
    }
    fin.close();

    vector<int> vec1;
    vec1 = vec;
    digit_sort(vec1);
    REQUIRE(vec1[0] == 1);
    REQUIRE(vec1[0] != vec[0]);
    REQUIRE(vec1.size() == vec.size());
    REQUIRE(vec1[10] == 1000);
    REQUIRE(vec1[10] == vec[4]);
}
