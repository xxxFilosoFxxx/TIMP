

#ifndef TASK2_2_TASK2_2_H
#define TASK2_2_TASK2_2_H

#endif //TASK2_2_TASK2_2_H

#include <iostream>
#include "ctime"

template <typename T>
class Node
{
private:
    Node<T>* parent;
    Node<T>* right;
    Node<T>* left;
    T value;
    int key;

public:

    Node():left(NULL), right(NULL), parent(NULL) {}
    Node(const int& _key, const T& znach):value(znach), key(_key), left(NULL), right(NULL), parent(NULL) {}
    Node(Node* par, const int& _key, const T& znach):value(znach), key(_key), left(NULL), right(NULL), parent(par) {}
    void Max_Heapify(int i, Node* A);
    void Build_Max_Heap(Node* A);
    void Heap_Increase_Key(Node* A, int i);
    void Max_Heap_Insert(Node* A, int i, T value);
    T Heap_Extract_Max(Node* A);

};

template <typename T>
class Heap
{
private:
    Node<T>* root;
    int top;

public:
    Heap():top(0) {}
    Heap(const int& _key, const T& znach):top(1) { root = new Node<T>(_key,znach); }
    int heap_size();

};

template <typename T>
int Heap<T>::heap_size()
{
    return top;
}

//функция корректна для int и double
template <typename T>
void Node<T>::Max_Heapify(int i, Node *A)
{
    int largest;
    int l = left(i); //TODO i->left
    int r = right(i);
    if ((A->l > A->i) && (l <= Heap<T>::heap_size()) )
    {
        largest = l;
    } else {
        largest = i;
    }

    if ((r <= Heap<T>::heap_size()) && (A->r > A->largest) ) {
        largest = r;
    }
    if (largest != i) {
     Node* tmp;
     tmp = A->i;
     A->i = A->largest;
     A->largest = tmp;
     Max_Heapify(largest, A);
    }
}

template <typename T>
void Node<T>::Build_Max_Heap(Node *A) {
    for(int i = Heap<T>::heap_size()/2;i >= 1;i--)
    {
        Max_Heapify(i,A);
    }
}

template<typename T>
void Node<T>::Heap_Increase_Key(Node *A, int i) {
    if(key < A->key) throw "Новый ключ меньше текущего!";

    A->key = i;
    while (A->parent != NULL && A->parent->key < A->key) {
            Node* tmp;
            tmp = A->key;
            A->key = A->parent->key;
            A->parent->key = tmp;
            key = parent->key;
    }
}

template<typename T>
void Node<T>::Max_Heap_Insert(Node *A, int i, T value) {
    Heap<T>::top++;
    A->key = i;
    A->value = value;
    Heap_Increase_Key(A, A->key) ;
    Max_Heapify(A->key,A);
}

template<typename T>
T Node<T>::Heap_Extract_Max(Node *A) {
    if (heap_size() < 1) throw "Куча пуста!";
    T max = A[1];
    A[1] = A->heap_size();
    top--;
    Max_Heapify(1,A);
    return  max;
}






