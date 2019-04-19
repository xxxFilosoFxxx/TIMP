#include <iostream>
#include "vector"
#include "task2-3.h"

using namespace std;

//For class Node (private)
Node *Node::find_child(const char _find) {
    for (auto &i : child) {
        if(i->key == _find )
            return i;
    }
    return nullptr;
}

Node *Node::find_prefix_node(Node *root, const char *prefix) {
    while(*prefix != 0 && root != nullptr) {
        root = root->find_child(*prefix++ );
    }
    return root;
}

Node *Node::find_or_create_child(const char _find)
{
    Node* node = find_child(_find);
    if (node == nullptr) {
        node = new Node(_find);
        child.push_back(node);
    }
    return node;
}

void Node::add_prefix_node(Node *node, const char *prefix, const int& value)
{
    int max = 0;
    while(*prefix != 0) {
        node = node->find_or_create_child(*prefix++ );
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

void Node::add_prefix(const char *prefix, const int& _value) {
     add_prefix_node(this, prefix, _value);
}

Node* Node::get_prefix_node(const char *prefix) {
    return find_prefix_node(this, prefix);
}

bool Node::get_prefix(const char *prefix, bool& _flag) {
    Node* node = find_prefix_node(this, prefix);
    if( node == nullptr )
        return false;
    _flag = node->flag;
    return true;
}
//For class Trie

void Trie::insert(const char* s, int _value) {
    root.add_prefix(s, _value);
}

Node* Trie::search_node(const char* s) {
    if (root.get_prefix_node(s) == nullptr) throw "Ошибка поиска!";
    return root.get_prefix_node(s);
}

bool Trie::search(const char* s) {
    bool _flag = false;
    return root.get_prefix(s, _flag) && _flag;
}

void Trie::print_search(const char *s) {
    if (search(s))
    {
        Node* node = search_node(s);
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
