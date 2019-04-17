#include <iostream>
#include "vector"
#include "task2-3.h"

using namespace std;

//For class Node (private)
Node *Node::find_child(const char to_find) {
    for (auto &i : child) {
        if(i->key == to_find )
            return i;
    }
    return nullptr;
}

Node *Node::find_postfix_in(Node *root, const char *postfix) {
    if (postfix == nullptr) throw "Ошибка проверки постфикса!";
    while(*postfix != 0 && root != nullptr) {
        root = root->find_child(*postfix++ );
    }
    return root;
}

Node *Node::find_or_create_child(const char to_find)
{
    Node* node = find_child(to_find);
    if (node == nullptr) {
        node = new Node(to_find);
        child.push_back(node);
    }
    return node;
}

void Node::add_postfix_to(Node *node, const char *postfix, const int& value)
{
    if (postfix == nullptr) throw "Ошибка проверки постфикса!";
    int max = 0;
    while(*postfix != 0) {
        node = node->find_or_create_child(*postfix++ );
        max++;
    }
    if (height < max)
        height = max;
    node->flag = true;
    node->value = value;
}

void Node::clear() {
    for (auto &i : child)
        delete i;
    child.clear();
}

//For class Node (public)

void Node::add_postfix(const char *postfix, const int& _value) {
     add_postfix_to(this, postfix, _value);
}

Node* Node::has_postfix(const char *postfix) {
    return find_postfix_in(this, postfix);
}

bool Node::has_postfix(const char *postfix, bool &_flag) {
    Node* node = find_postfix_in(this, postfix);
    if( node == nullptr )
        return false;
    _flag = node->flag;
    return true;
}
//For class Trie

void Trie::insert(const char* s, int _value) {
    root.add_postfix(s, _value);
}

Node* Trie::search_str(const char* s) {
    return root.has_postfix(s);
}

bool Trie::search(const char* s) {
    bool _flag = false;
    return root.has_postfix(s, _flag) && _flag;
}

void Trie::print_search(const char *s) {
    if (search(s))
    {
        Node* node = search_str(s);
        for ( int i = 0; '\0' !=  s[i]; i++ )
        {
            cout << s[i];
        }
        cout << " " << node->_value() << endl;
    }
    else
    {
        cout << "Not found word!" << endl;
    }
}

int Trie::tree_height() {
    return root.height;
}
