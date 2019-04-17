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
    Node* find_child(char to_find );
    Node* find_or_create_child(char to_find );
    Node* find_postfix_in(Node* root, const char* postfix );
    void add_postfix_to( Node* node, const char* postfix, const int& value);
    void clear();
public:
    int height = 0;
    Node():flag(false), key() {}
    Node(char c):flag(false), key(c) {}
    ~Node() { clear(); }

    int _value() { return this->value;}
    void add_postfix(const char * postfix, const int& _value);
    Node* has_postfix(const char* postfix);
    bool has_postfix(const char* postfix, bool& _flag);

};

class Trie
{
private:
    Node root;
public:
    void insert(const char* s, int _value);
    Node* search_str(const char* s);
    bool search (const char* s);
    void print_search(const char* s);
    int tree_height();
};













