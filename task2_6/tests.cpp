#include <iostream>
#include "vector"
#include "algorithm"
#include "sstream"
#include "task2-6.h"
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
using namespace std;

TEST_CASE("Test1", "task2-6_Tests")
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

    Graph gr(vect_versh,vect_edge);
    gr.search_Prima();
    REQUIRE(gr.sum == 75);
    REQUIRE(gr.rezult[0].first == 1);
    REQUIRE(gr.rezult[0].second == 0);
    REQUIRE(gr.rezult[1].first == 2);
    REQUIRE(gr.rezult[1].second == 1);
    REQUIRE(gr.rezult[2].first == 3);
    REQUIRE(gr.rezult[2].second == 0);
    REQUIRE(gr.rezult[3].first == 4);
    REQUIRE(gr.rezult[3].second == 3);
}

TEST_CASE("Test2", "task2-6_Tests")
{
    string str = "";
    string str1 = str;
    vector<int> vect_versh;
    vector<int> vect_edge;
    vector<int> vect_weight;

    Graph gr(vect_versh,vect_edge);
    REQUIRE_THROWS(gr.search_Prima());
}

TEST_CASE("Test3", "task2-6_Tests")
{
    string str = "a,b,c,d,e,ab10,ac25,ad15,ae30,bc40,bd50,be20,ce15";
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

    Graph gr(vect_versh,vect_edge);
    gr.search_Prima();
    REQUIRE(gr.sum == 60);
    REQUIRE(gr.rezult[0].first == 1);
    REQUIRE(gr.rezult[0].second == 0);
    REQUIRE(gr.rezult[1].first == 2);
    REQUIRE(gr.rezult[1].second == 4);
    REQUIRE(gr.rezult[2].first == 3);
    REQUIRE(gr.rezult[2].second == 0);
    REQUIRE(gr.rezult[3].first == 4);
    REQUIRE(gr.rezult[3].second == 1);
}