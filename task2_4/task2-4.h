#ifndef TIMP_TASK2_4_H
#define TIMP_TASK2_4_H

#endif //TIMP_TASK2_4_H

#include <iostream>
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

vector<int> Digit_sort(vector<int> vec)
{
    auto *my_queue = new queue<int>[10]; // корзины (очереди) для хранения чисел

    auto it = max_element(vec.begin(), vec.end());
    int bit = 0;  // Разрядность максимального числа
    while(*it >0)
    {
        *it = *it / 10;
        bit++;
    }


    for (int i = 0; i < bit; i++)  // количество проходов
    {
        //TODO
    }

    delete(my_queue);

}