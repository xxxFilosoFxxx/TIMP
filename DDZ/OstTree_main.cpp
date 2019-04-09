#include <iostream>
#include "time.h"
#include "OstTree.h"

using namespace std;

int main()
{
    Graph g;
    srand(time(0));
    for (int i = 1; i < 100000; i++)
    {
        g.add_node(rand()%100000, rand()%100000 ,rand()%100);
    }

//    g.add_node(1,2,10);
//    g.add_node(3,1,20);
//    g.add_node(3,4,30);
//    g.add_node(1,4,10);
//    g.add_node(2,3,15);
//    g.add_node(2,2,5);
//    g.add_node(5,4,40);
//    g.add_node(3,5,60);

    clock_t time;
    time = clock();
    g.KruskalPoisk();
    time = clock() - time;
    cout << (double)time/CLOCKS_PER_SEC << " what?!" << endl;

    return 0;
}
