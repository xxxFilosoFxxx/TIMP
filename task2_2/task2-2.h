

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
    void Heap_Increase_Key(Node* A, int i);
    void Max_Heap_Insert(Node* A, int i);
    int Heap_Extract_Max();
    void Heap_Change_key(Node* A, int i);
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
    if (l != nullptr && l->key > A->key)
    {
        largest->key = l->key;
    } else {
        largest->key = A->key;
    }

    if (r != nullptr && r->key > largest->key) {
        largest->key = r->key;
    }
    if (largest->key != A->key) {
        if(A->parent != nullptr)
        {
            int tmp;
            tmp = A->key;
            A->key = largest->key;
            largest->key = tmp;
        }
        else
        {
            int tmp;
            tmp = A->key;
            A->key = root->key;
            root->key = tmp;
        }
        Max_Heapify(largest);
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


void Heap::Max_Heap_Insert(Node* A, int i) {
    if(top > 1 && A->parent == nullptr && A->left == nullptr && A->right == nullptr)
        throw "Ошибка вставки элемента!";
    if (top == 0)
    {
        Node* node = new Node(i);
        root = node;
    }
    if(top == 1)
    {
        Node* node = new Node(root, i);
        if(root->left == nullptr)
        {
            root->left = node;
        }
        else {
            root->right = node;
        }
        //TODO можно убрать правый указатель
    }

    if(top > 1)
    {
        Node* node = new Node(i);
        if (A->left != nullptr && A->right != nullptr)
            A = A->left;
        if (A->left != nullptr && A->right != nullptr && A->parent->right->left == nullptr && A->parent->right->right == nullptr)
            A = A->parent->right;
        if (A->left != nullptr && A->right == nullptr)
        {
            node->parent = A;
            A->right = node;
        }
       /* if (A->left == nullptr && A->right != nullptr)
        {
            node->parent = A;
            A->left = node;
        }*/
        if (A->left == nullptr && A->right == nullptr)
        {
            node->parent = A;
            A->left = node;
        }
    }

    top++;
    Heap_Increase_Key(A, i);
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
    if (root->left != nullptr && root->right == nullptr)
        root = root->left;
   /* if (root->left == nullptr && root->right != nullptr)
        root = root->right;*/
    if (root->left != nullptr && root->right != nullptr)
    {
        if(root->left->key >= root->right->key)
        {
            root->right->parent = root->left;
            root = root->left;
            root->parent = nullptr;
            delete pop;

        }
        else
        {
            root->left->parent = root->right;
            root = root->right;
            root->parent = nullptr;
            delete pop;
        }
    }
    Max_Heapify(root);
    top--;
    return max;
}

void Heap::Heap_Change_key(Node *A, int i) {
    //TODO Дописать смену ключа

}
