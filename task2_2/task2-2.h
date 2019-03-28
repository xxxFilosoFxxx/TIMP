// 9. Куча на основе указателей с операциями:
// Вставки элемента, извлечение элемента и изменение приоритета элемента.

#ifndef TASK2_2_TASK2_2_H
#define TASK2_2_TASK2_2_H

#endif //TASK2_2_TASK2_2_H

#include <iostream>
#include "ctime"
#include "vector"

using namespace std;

template <typename T>
struct Node
{
    Node* parent;
    Node* right;
    Node* left;
    T value;
    int key;

    Node():left(nullptr), right(nullptr), parent(nullptr) {}
    Node(int _key, T _value):key(_key), value(_value), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(Node* par, int _key, T _value):key(_key), value(_value), left(nullptr), right(nullptr), parent(par) {}
};

template <typename T>
class Heap
{
public:
    int top = 0;
    Node<T>* root;

    Heap():top(0) {}
    Heap(int _key, T _value):top(1) { root = new Node<T>(_key, _value); }
    ~Heap();
    int heap_size();
    int max_key();
    T max_value();

    void Max_Heapify(Node<T>* A);
    void Heap_Increase_Key(Node<T>* A, int i);
    void Max_Heap_Insert(int i, T _value);
    int Heap_Extract_Max();
    void Heap_Change_key(Node<T>* A, int i);
    vector<bool> to_bin (int n);
};

//Реализация методов класса Кучи

template <typename T>
int Heap<T>::heap_size()
{
    return top;
}

template<typename T>
T Heap<T>::max_value() {
    if (top == 0)
        throw "Nedopustimo!";
    return root->value;

}


template <typename T>
int Heap<T>::max_key() {
    return root->key;
}

template <typename T>
void Heap<T>::Max_Heapify(Node<T>* A)
{
    Node<T>* l = A->left;
    Node<T>* r = A->right;
    Node<T>* largest = new Node<T>();
    if (l != nullptr || r != nullptr)
    {
        if(l != nullptr) {
            if (l->key > A->key)
            {
                largest = l;
            }
            else
            {
                largest = A;
            }
        }
        if (r != nullptr && r->key > largest->key) {
            largest = r;
        }
        if (largest->key != A->key) {
            int tmp;
            tmp = A->key;
            A->key = largest->key;
            largest->key = tmp;

            T _tmp;
            _tmp = A->value;
            A->value = largest->value;
            largest->value = _tmp;
            Max_Heapify(largest);
        }
    }
}

template <typename T>
void Heap<T>::Heap_Increase_Key(Node<T>* A, int i) {
    while (A->parent != nullptr && A->key < i )
    {
        int tmp;

        if (A->left->key == i)
        {
            tmp = A->left->key;
            A->left->key = A->key;
            A->key = tmp;

            T _tmp = A->left->value;
            A->left->value = A->value;
            A->value = _tmp;


            if(A->left->key > A->parent->right->key)
            {
                int tmp1 = A->left->key;
                A->left->key = A->parent->right->key;
                A->parent->right->key = tmp1;

                T tmp2 = A->left->value;
                A->left->value = A->parent->right->value;
                A->parent->right->value = tmp2;
            }
        }
        if (A->right != nullptr && A->right->key == i)
        {
            tmp = A->right->key;
            A->right->key = A->key;
            A->key = tmp;

            T _tmp = A->right->value;
            A->right->value = A->value;
            A->value = _tmp;
            if(A->right->key > A->parent->right->key)
            {
                int tmp1 = A->right->key;
                A->right->key = A->parent->right->key;
                A->parent->right->key = tmp1;

                T tmp2 = A->right->value;
                A->right->value = A->parent->right->value;
                A->parent->right->value = tmp2;
            }
        }
        //  Max_Heapify(root);
        A = A->parent;
    }
    if (A->parent == nullptr && A->right != nullptr )
    {
        if(root->key < A->right->key)
        {
            int tmp;
            tmp = A->right->key;
            A->right->key = root->key;
            root->key = tmp;

            T _tmp;
            _tmp = A->right->value;
            A->right->value = root->value;
            root->value = _tmp;
        }
    }
    if (A->parent == nullptr && A->left != nullptr )
    {
        if(root->key < A->left->key)
        {
            int tmp;
            tmp = A->left->key;
            A->left->key = root->key;
            root->key = tmp;

            T _tmp;
            _tmp = A->left->value;
            A->left->value = root->value;
            root->value = _tmp;
        }
    }
}

template <typename T>
vector<bool> Heap<T>::to_bin(int n)
{
    vector<bool> vec;
    while (n > 0)
    {
        vec.push_back(n % 2);
        n/= 2;
    }
    return vec;
}

template <typename T>
void Heap<T>::Max_Heap_Insert(int i, T _value) {
    if (top == 0)
    {
        Node<T>* node = new Node<T>(i, _value);
        root = node;
    }
    top++;

    if (top > 1)
    {
        Node<T>* node = root;
        vector<bool> v = to_bin(top);
        for (int i = v.size() - 2; i > 0; --i) {
            if (v[i] == 1)
                node = node->right;
            else
                node = node->left;
        }

        Node<T>* new_node = new Node<T>(node, i, _value);
        if (v[0] == 1)
            node->right = new_node;
        else
            node->left = new_node;

        Heap_Increase_Key(node, i);
    }
}

template <typename T>
int Heap<T>::Heap_Extract_Max() {
    if (!top) throw "Куча пуста!";
    int max = root->key;

    if (top == 1)
    {
        delete root;
        top--;
        return max;
    }
    Node<T>* pop = root;
    vector<bool> v = to_bin(top);

    if (root->left != nullptr && root->right == nullptr)
        root = root->left;
    if (root->left != nullptr && root->right != nullptr)
    {
        for (int i = v.size() - 2; i > 0; --i)
        {
            if (v[i] == 1)
                pop = pop->right;
            else
                pop = pop->left;
        }

        bool flag;
        if(pop->right != nullptr)
        {
            pop = pop->right;
            flag = true;
        }
        else
        {
            pop = pop->left;
            flag = false;
        }
        int tmp = pop->key;
        pop->key = root->key;
        root->key = tmp;

        T _tmp = pop->value;
        pop->value = root->value;
        root->value = _tmp;

        Node<T>* parent = pop->parent;
        if(flag)
            parent->right = nullptr;
        else
            parent->left = nullptr;
    }
    delete pop;
    Max_Heapify(root);
    top--;
    return max;
}

template <typename T>
Heap<T>::~Heap()
{
    while (top != 0)
        Heap_Extract_Max();
}

template <typename T>
void Heap<T>::Heap_Change_key(Node<T>* A, int i)
{
    if (!top) throw "Куча пуста!";

    A->key = i;
    if (A->parent != nullptr)
        Heap_Increase_Key(A->parent, i);
    else
        Heap_Increase_Key(A, i);

}

