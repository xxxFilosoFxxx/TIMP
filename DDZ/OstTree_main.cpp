#include <iostream>
#include "ctime"
#include "OstTree.h"

using namespace std;

int main()
{
    Graph g;
    srand(time(0));
    for (int i = 1; i < 10000000; i++)
    {
        g.add_node(rand()%10000000, rand()%10000000 ,rand()%100);
    }

//    g.add_node(1,2,10);
//    g.add_node(3,1,20);
//    g.add_node(3,4,30);
//    g.add_node(1,4,10);
//    g.add_node(2,3,15);
//    g.add_node(2,2,5);
//    g.add_node(5,4,40);
//    g.add_node(3,5,60);

    clock_t times;
    times = clock();
    g.KruskalPoisk();
    times = clock() - times;
    cout << (double)times/CLOCKS_PER_SEC << " what?!" << endl;

    return 0;
}
