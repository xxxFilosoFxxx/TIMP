#include <iostream>
#include "task2-3.h"

using namespace std;

int main()
{
    Trie trie;
    trie.insert("arrow", 1);
    trie.insert("morda", 2);
    trie.insert("krash", 3);
    trie.insert("avto", 4);
    trie.insert("privet", 5);
    trie.insert("parkovka", 6);
    trie.print_search("arrow");
    trie.print_search("privet");
    trie.print_search("");
    cout << trie.search("avto") << endl;
    cout << trie.search("") << endl;

    return 0;
}
