

#ifndef TASK2_2_TASK2_2_H
#define TASK2_2_TASK2_2_H

#endif //TASK2_2_TASK2_2_H

#include <iostream>
#include "ctime"

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
    int heap_size();
    int max_key();

    void Max_Heapify(Node* A);
    void Build_Max_Heap(Node* A);
    void Heap_Increase_Key(Node* A, int i);
    void Max_Heap_Insert(Node* A, int i);
    int Heap_Extract_Max(Node* A);
    void Heap_Change_key(Node* A);
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
    Node* largest;
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
        A->key = A->parent->key;
        A->parent->key = tmp;
        Max_Heapify(largest);
    }
}


void Heap::Build_Max_Heap(Node* A) {
    while (A != nullptr) {
        Max_Heapify(A);
        A = A->parent;
    }
}


void Heap::Heap_Increase_Key(Node* A, int i) {
    if(i < A->key) throw "Новый ключ меньше текущего!";

    A->key = i;
    while (A->parent != nullptr && A->parent->key < A->key)
    {
        int tmp;
        tmp = A->key;
        A->key = A->parent->key;
        A->parent->key = tmp;

    }
}


void Heap::Max_Heap_Insert(Node* A, int i) {
    if (top == 0)
    {
        Node* node = new Node(i);
        root = node;
    }
    if(top == 1)
    {
        Node* node = new Node(root, i);
        if(node->key > root->key)
        {
            node->parent =  root;
            root->left = node;
        }
        else {
            node->parent = root;
            root->right = node;
        }

    }
    if(top > 1)
    {
        Node* node = new Node(i);
        if (A->left != nullptr && A->right != nullptr)
            A = A->left;
        if(A->left != nullptr && A->right != nullptr && A->parent->right->left == nullptr && A->parent->right->right == nullptr)
            A = A->parent->right;
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
    }

   // Heap_Increase_Key(A, i);
    top++;
}


int Heap::Heap_Extract_Max(Node* A) {
    if (top == 0) throw "Куча пуста!";

    Node* pop = root;
    int max = pop->key;
    root = root->left;
    delete pop;
    top--;
    Max_Heapify(A);
    return max;
}


void Heap::Heap_Change_key(Node *A) {
    //TODO Дописать смену ключа

}








