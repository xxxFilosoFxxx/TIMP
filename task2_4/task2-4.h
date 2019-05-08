#ifndef TIMP_TASK2_4_H
#define TIMP_TASK2_4_H

#endif //TIMP_TASK2_4_H

#include <iostream>
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

void Digit_sort(vector<int>& vec)
{
    auto *my_queue = new queue<int>[10]; // корзины (очереди) для хранения чисел

    int size = vec.size();
    auto it = max_element(vec.begin(), vec.end());
    int max = *it;
    int count = 1; // Потребуется для уменьшения разряда числа
    int bit = 0;  // Разрядность максимального числа
    while(max >0)
    {
        max = max / 10;
        bit++;
    }

    while (bit != 0)
    {
        auto it1 = vec.begin();
        for (; it1 != vec.end(); it1++)
        {
            int a = (*it1/count) % 10;
            for (int i = 0; i < 10; i++) {
                if (i == a) {
                    my_queue[i].push(*it1);
                }
            }
        }
        vec.clear();
        for (int i = 0; i < 10; i++)
        {
            while (!my_queue[i].empty()) {
                vec.push_back(my_queue[i].front());
                my_queue[i].pop();
            }
        }
        count *= 10;
        bit--;
    }
    delete []my_queue;
}