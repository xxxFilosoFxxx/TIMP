#include <iostream>
#include "trie.h"

using namespace std;

int main()
{
    Trie trie;
    trie.insert("arrow", 1);
    trie.insert("face", 2);
    trie.insert("crash", 3);
    trie.insert("car", 4);
    trie.insert("hello", 5);
    trie.insert("parking", 6);

    trie.print_search("arrow");
    trie.print_search("hello");
    trie.print_search("");

    cout << trie.search("car") << endl;
    cout << trie.search("") << endl;
    cout << trie.tree_height() << endl;

    // Node* node;
    // node = trie.search_node("avk");
    // cout << node->_value();

    return 0;
}
