#include <iostream>
#include "ctime"
#include "string.h"
#include "vector"

using namespace std;


class Node
{
private:

public:
    bool flag;
    int value;
    char* key;
 //   Node* parent;
    vector<Node*> child;
    Node():flag(false) { key = nullptr; }

    Node(const char* c):flag(false) { strcat(key, c); }

    Node(const char* c, const int value):flag(false) {
        strcat(key, c);
        this->value = value;
    }

    Node* find_child(const char* to_find );
    Node* find_postfix_in(Node* root, const char* postfix );
    Node* find_or_create_child(const char* to_find );
    void add_postfix_to( Node* dst, const char* postfix, const int& value);

};

Node *Node::find_child(const char *to_find) {
    for( int i = 0; i < child.size(); i++ ) {
        if( to_find == child[i]->key)
            return child[i];
    }
    return nullptr;
}

Node *Node::find_postfix_in(Node *root, const char *postfix) {
    if (postfix == nullptr) throw "Ошибка проверки постфикса!";
    while( postfix != nullptr && root != nullptr) {
        root = root->find_child( postfix++ );
    }
    return root;
}

Node *Node::find_or_create_child(const char *to_find)
{
    Node* node = find_child(to_find );
    if( node == nullptr) {
        node = new Node( to_find );
        child.push_back( node);
    }
    return node;
}

void Node::add_postfix_to(Node *dst, const char *postfix, const int& value)
{
    if (postfix == nullptr) throw "Ошибка проверки постфикса!";
    while( postfix != nullptr) {
        dst = dst->find_or_create_child( postfix++ );
    }
    dst->flag = true;
    dst->value = value;
}


class Trie
{
private:
    Node *root;
public:

    Trie() { root = new Node(); }
    Trie* creatRoot();
    void insert(const string& s, int _value);
};

Trie *Trie::creatRoot() {
    Trie* trie = new Trie();
    return trie;
}


void Trie::insert(const string &s, int _value) {
    if (root == nullptr) { creatRoot(); }

    //TODO
}










