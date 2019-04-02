#include <iostream>
#include "ctime"
#include "string.h"
#include "map"

using namespace std;


class Node
{
public:
    bool flag;
    int znach;
   // int len;
    char* key;
    Node* child;
    Node(char* x, int n):flag(false)/*, len(0)*/, child(nullptr) {}
    int prefix(const char* x, int n, const char* key, int m);

};

int Node::prefix(const char *x, int n, const char *key, int m) {
    for (int i = 0; i < n; i++)
    {
        if (i == m || x[i]!= key[i])
            return i;
    }
    return n;
}









