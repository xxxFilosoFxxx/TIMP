#include <iostream>
#include "vector"

using namespace std;

class Node
{
private:
    bool flag;
    int value;
    char key;
    vector<Node*> child;
    Node* find_child(char _find );
    Node* find_or_create_child(char _find );
    Node* find_prefix_node(Node* root, const char* prefix );
    void add_prefix_node(Node* node, const char* prefix, const int& value);
    void clear();
public:
    int height = 0;
    Node():flag(false), key() {}
    Node(char c):flag(false), key(c) {}
    ~Node() { clear(); }

    int _value() { return this->value;}
    void add_prefix(const char * prefix, const int& _value);
    Node* get_prefix_node(const char* prefix);
    bool get_prefix(const char* prefix, bool& _flag);

};

class Trie
{
private:
    Node root;
public:
    void insert(const char* s, int _value);
    Node* search_node(const char* s);
    bool search (const char* s);
    void print_search(const char* s);
    int tree_height();
};













