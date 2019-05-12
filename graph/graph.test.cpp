#include <iostream>
#include "vector"
#include "algorithm"
#include "sstream"
#include "graph.h"

#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

using namespace std;

TEST_CASE("Test1", "[graph]")
{
    string str = "a,b,c,d,e,f,g,h,ab,ff,ca,be,fh";
    string str1 = str;
    vector<int> vertices;
    vector<int> edges;
    int mas[26];
    for (int i = 0; i < 26; i++)
    {
        mas[i] = i;
    }

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

        for (int j = 0; j < 26; j++)
        {
            if (mas[j] == ((int)i - 97))
                vertices.push_back(j);
        }
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
        for (int j = 0; j < 26; j++)
        {
            if (mas[j] == ((int)i - 97))
                edges.push_back(j);
        }
    }

    Graph g(vertices, edges);
    //g.print_list();
    vector<int> example = g.search_graph_wide(vertices[0]);
    REQUIRE(example[0] == 0);
    REQUIRE(example[1] == 1);
    REQUIRE(example[2] == 2);
    REQUIRE(example[3] == 4);
    example = g.search_graph_wide(vertices[3]);
    REQUIRE(example[0] == 3);
    int comp = g.find_components();
    REQUIRE(comp == 4);
}

TEST_CASE("Test2", "[graph]")
{
    string str = "a,b,c,d,e,f,g,h,ac,ad,eg,be,fh";
    string str1 = str;
    vector<int> vertices;
    vector<int> edges;
    int mas[26];
    for (int i = 0; i < 26; i++)
    {
        mas[i] = i;
    }

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

        for (int j = 0; j < 26; j++)
        {
            if (mas[j] == ((int)i - 97))
                vertices.push_back(j);
        }
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
        for (int j = 0; j < 26; j++)
        {
            if (mas[j] == ((int)i - 97))
                edges.push_back(j);
        }
    }

    Graph g(vertices, edges);
    //g.print_list();
    vector<int> example = g.search_graph_wide(vertices[0]);
    REQUIRE(example[0] == 0);
    REQUIRE(example[1] == 2);
    REQUIRE(example[2] == 3);
    example = g.search_graph_wide(vertices[5]);
    REQUIRE(example[0] == 5);
    REQUIRE(example[1] == 7);
    int comp = g.find_components();
    REQUIRE(comp == 3);
}
