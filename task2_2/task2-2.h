// Куча на основе указателей с операциями:
// Вставки элемента, извлечение элемента и изменение приоритета элемента.

#ifndef TASK2_2_TASK2_2_H
#define TASK2_2_TASK2_2_H

#endif //TASK2_2_TASK2_2_H

#include <iostream>
#include "ctime"
#include "vector"

using namespace std;

struct Node
{
    Node* parent;
    Node* right;
    Node* left;
    int key;

    Node():left(nullptr), right(nullptr), parent(nullptr) {}
    Node(int _key):key(_key), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(Node* par, int _key):key(_key), left(nullptr), right(nullptr), parent(par) {}
};

class Heap
{
public:
    int top = 0;
    Node* root;

    Heap():top(0) {}
    Heap(int _key):top(1) { root = new Node(_key); }
    ~Heap();
    int heap_size();
    int max_key();

    void Max_Heapify(Node* A);
    void Heap_Increase_Key(Node* A, int i);
    void Max_Heap_Insert(int i);
    int Heap_Extract_Max();
    void Heap_Change_key(Node* A, int i);
    vector<bool> to_bin (int n);
};

int Heap::heap_size()
{
    return top;
}


int Heap::max_key() {
    return root->key;
}


void Heap::Max_Heapify(Node* A)
{
    Node* l = A->left;
    Node* r = A->right;
    Node* largest = new Node();
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
            Max_Heapify(largest);
        }
    }
}

void Heap::Heap_Increase_Key(Node* A, int i) {
    while (A->parent != nullptr && A->key < i )
    {
        int tmp;

        if (A->left->key == i)
        {
            tmp = A->left->key;
            A->left->key = A->key;
            A->key = tmp;
            if(A->left->key > A->parent->right->key)
            {
                int tmp1 = A->left->key;
                A->left->key = A->parent->right->key;
                A->parent->right->key = tmp1;
            }
        }
        if (A->right != nullptr && A->right->key == i)
        {
            tmp = A->right->key;
            A->right->key = A->key;
            A->key = tmp;
            if(A->right->key > A->parent->right->key)
            {
                int tmp1 = A->right->key;
                A->right->key = A->parent->right->key;
                A->parent->right->key = tmp1;
            }
        }
        Max_Heapify(root);
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
        }
    }
}

vector<bool> Heap::to_bin(int n)
{
    vector<bool> vec;
    while (n > 0)
    {
        vec.push_back(n % 2);
        n/= 2;
    }
    return vec;
}

void Heap::Max_Heap_Insert(int i) {
    if (top == 0)
    {
        Node* node = new Node(i);
        root = node;
    }
    top++;

    if (top > 1)
    {
        Node* node = root;
        vector<bool> v = to_bin(top);
        for (int i = v.size() - 2; i > 0; --i) {
            if (v[i] == 1)
                node = node->right;
            else
                node = node->left;
        }

        Node* new_node = new Node(node, i);
        if (v[0] == 1)
            node->right = new_node;
        else
            node->left = new_node;

        Heap_Increase_Key(node, i);
    }
}

int Heap::Heap_Extract_Max() {
    if (!top) throw "Куча пуста!";
    int max = root->key;

    if (top == 1)
    {
        delete root;
        top--;
        return max;
    }
    Node* pop = root;
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

        Node* parent = pop->parent;
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

Heap::~Heap()
{
    while (top != 0)
        Heap_Extract_Max();
}

void Heap::Heap_Change_key(Node *A, int i)
{
    if (!top) throw "Куча пуста!";

    A->key = i;
    if (A->parent != nullptr)
        Heap_Increase_Key(A->parent, i);
    else
        Heap_Increase_Key(A, i);

}






