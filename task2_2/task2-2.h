

#ifndef TASK2_2_TASK2_2_H
#define TASK2_2_TASK2_2_H

#endif //TASK2_2_TASK2_2_H

#include <iostream>
#include "ctime"

template <typename T>
struct Node
{
    Node<T>* parent;
    Node<T>* right;
    Node<T>* left;
    T value;
    int key;

    Node():left(nullptr), right(nullptr), parent(nullptr) {}
    Node(int _key, T znach):value(znach), key(_key), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(Node<T>* par, int _key, T znach);

    Node<T>* Parent(Node<T>* p) {
        return p->parent;
    }
    Node<T>* Left(Node<T>* l) {
        return l->left;
    }
    Node<T>* Right(Node<T>* r) {
        return r->right;
    }
};

template <typename T>
class Heap : Node<T>
{
private:
    Node<T>* root;
    int top;

public:
    Heap():top(0) {}
    Heap(int _key, T znach):top(1) { root = new Node<T>(_key,znach); }
    int heap_size();
    T max_key();

    void Max_Heapify(Node<T>* A);
    void Build_Max_Heap(Node<T>* A);
    void Heap_Increase_Key(Node<T>* A, int i);
    void Max_Heap_Insert(Node<T>* A, int i, T value);
    int Heap_Extract_Max(Node<T>* A);
    void Heap_Change_key(Node<T>* A);
};

template <typename T>
int Heap<T>::heap_size()
{
    return top;
}

template<typename T>
T Heap<T>::max_key() {
    return root->key;
}

template <typename T>
void Heap<T>::Max_Heapify(Node<T>* A)
{
    Node<T>* l = Left(A);
    Node<T>* r = Right(A);
    Node<T>* largest;
    if ((l != nullptr) && (l->key > A->key))
    {
        largest = l;
    } else {
        largest = A;
    }

    if ((r != nullptr) && (r->key > largest->key)) {
        largest = r;
    }
    if (largest != A) {
        int tmp;
        tmp = A->key;
        A->key = Parent(A)->key;
        Parent(A)->key = tmp;

        T element;
        element = A->value;
        A->value = Parent(A)->value;
        Parent(A)->value = element;
        Max_Heapify(largest);
    }
}

template <typename T>
void Heap<T>::Build_Max_Heap(Node<T>* A) {
    while (A != nullptr) {
        Max_Heapify(A);
        A = Parent(A);
    }
}

template<typename T>
void Heap<T>::Heap_Increase_Key(Node<T>* A, int i) {
    if(i < A->key) throw "Новый ключ меньше текущего!";

    A->key = i;
    while (Parent(A) != nullptr && Parent(A)->key < A->key) {
        int tmp;
        tmp = A->key;
        A->key = Parent(A)->key;
        Parent(A)->key = tmp;

        T element;
        element = A->value;
        A->value = Parent(A)->value;
        Parent(A)->value = element;
   //     A = Parent(A);
    }
}

template<typename T>
void Heap<T>::Max_Heap_Insert(Node<T> *A, int i, T value) {
    if (top == 0)
    {
        Node<T> node(i, value);
        root = &node;
        top++;
    }
    if(top == 1)
    {
        Node<T>* node(root, i, value);
        if(node->key > root->key)
        {
            node->parent =  root;
            root->left = node;
        }
        else
        {
            node->parent = root;
            root->right = node;
        }

        Heap_Increase_Key(A, i);
        top++;
    }
    if(top > 1)
    {
        Node<T>* node(A, i, value);
        if (A->left != nullptr && A->right != nullptr)
            A = A->left;
        if(A->left != nullptr && A->right != nullptr && Parent(A)->right->left == nullptr && Parent(A)->right->right == nullptr)
            A = Parent(A)->right;
        if (node->key <= A->key) {
            if (A->right != nullptr) {
                A = A->left;
                node->parent = A;
                A->left = node;
            } else {
                node->parent = A;
                A->right = node;
            }
        }
        if (node->key > A->key)
        {
            if (A->left != nullptr)
            {
                node->parent = A;
                A->left = node;
            }
            else
            {
                node->parent = A;
                A->left = node;
            }
        }

        Heap_Increase_Key(A, i);
        top++;
    }
}

template<typename T>
int Heap<T>::Heap_Extract_Max(Node<T> *A) {
    if (top == 0) throw "Куча пуста!";

    Node<T>* pop = root;
    int max = pop->key;
    root = root->left;
    delete pop;
    top--;
    Max_Heapify(A);
    return max;
}

template<typename T>
void Heap<T>::Heap_Change_key(Node<T> *A) {
    //TODO Дописать смену ключа

}








