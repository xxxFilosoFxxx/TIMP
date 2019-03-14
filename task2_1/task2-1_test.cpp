/*Тесты для очереди на основе связного списка*/
#include <iostream>
#include "cstdio"
#include "ctime"

#include "task2-1.h"

#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

TEST_CASE("Test1", "task2-1_Tests")
{
    Queue<int> pQueue;
    pQueue.push(5);
    pQueue.push(10);
    pQueue.push(15);
    REQUIRE(pQueue.size() == 3 );
}

TEST_CASE("Test2", "task2-1_Tests")
{
    Queue<int> pQueue;
    REQUIRE_THROWS(pQueue.pop());
}

TEST_CASE("Test3", "task2-1_Tests")
{
    Queue<int> pQueue;
    REQUIRE(pQueue.size() == 0);
}

TEST_CASE("Test4", "task2-1_Tests")
{
    Queue<int> pQueue;
    pQueue.push(10);
    pQueue.push(15);
    pQueue.push(1000);
    pQueue.push(-30);
    pQueue.clear();
    REQUIRE(pQueue.size() == 0);
}

TEST_CASE("Test5", "task2-1_Tests")
{
    Queue<int> pQueue;
    pQueue.push(10);
    pQueue.push(20);
    pQueue.pop();
    REQUIRE(pQueue.size() == 1);
}

TEST_CASE("Test6", "task2-1_Tests")
{
    Queue<int> pQueue;
    pQueue.push(10);
    pQueue.push(20);
    REQUIRE(pQueue.pop() == 10);
}

TEST_CASE("Test7", "task2-1_Tests")
{
    srand(time(NULL));
    Queue<int> pQueue;
    pQueue.push(rand()%1000);
    pQueue.push(rand()%1000);
    pQueue.push(rand()%1000);
    pQueue.clear();
    pQueue.push(rand()%1000);
    pQueue.push(rand()%1000);
    pQueue.clear();
    pQueue.push(rand()%1000);
    REQUIRE(pQueue.size() == 1);
}

TEST_CASE("Test8", "task2-1_Tests")
{
    Queue<double> pQueue;
    pQueue.push(rand()%1000);
    pQueue.push(rand()%1000);
    pQueue.push(rand()%1000);
    pQueue.pop();
    pQueue.pop();
    pQueue.push(rand()%1000);
    pQueue.clear();
    pQueue.push(15.5);
    pQueue.push(1000.15);
    pQueue.push(rand()%1000);
    pQueue.pop();
    REQUIRE(pQueue.pop() == 1000.15);
}

TEST_CASE("Test9", "task2-1_Tests")
{
    Queue<std::string> pQueue;
    pQueue.push("Privet ");
    pQueue.push("kak dela?");
    pQueue.pop();
    REQUIRE(pQueue.pop() == "kak dela?");
}


