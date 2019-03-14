/*Реализация очереди на основе связного списка (шаблонный)*/
#ifndef TASK2_1_TASK2_1_H
#define TASK2_1_TASK2_1_H

#endif //TASK2_1_TASK2_1_H

#include <iostream>
#include <ctime>

template<typename T>
class Queue {
private:
    struct DataElement {
        T value;
        DataElement *next;
    };
    DataElement *Head;
    DataElement *tail;
    int top;      //number of the current queue element

public:
    Queue();
    ~Queue();

    T pop();
    void push(T);
    void print(); //print queue
    void clear(); //delete queue
    int size();   //size of queue
};

template<typename T>
Queue<T>::Queue() {
    Head = NULL;
    tail = NULL;
    top = 0;
}

template<typename T>
Queue<T>::~Queue() {
   this->clear();
}

template<typename T>
void Queue<T>::push(T value) {
    DataElement *d = new DataElement();
    d->next = NULL;
    d->value = value;
    if (Head == NULL) {
        Head = d;
    }
    else {
        tail->next = d;
    }
    tail = d;
    top++;
}

template<typename T>
T Queue<T>::pop() {
    if (Head == NULL) {
        tail = NULL;
        throw "Queue is empty";
    }
    DataElement *d = Head;
    T tmp = d->value;
    Head = Head->next;
    delete d;
    top--;
    return tmp;
}

template<typename T>
void Queue<T>::print() {
    if (Head == NULL) throw "Queue is empty";
    DataElement *f = Head;
    int i = 1;
    while (f != NULL) {
        std::cout << i << ". " << f->value << std::endl;
        f = f->next;
        i++;
    }
}

template<typename T>
int Queue<T>::size() {
    return top;
}

template<typename T>
void Queue<T>::clear() {
    while (Head != NULL){
        pop();
    }
}

