#include <iostream>
#include "ctime"
#include "vector"

using namespace std;

int main()
{
    int **mas = new int*[20];
    for(int i = 0; i < 20; i++)
    {
        mas[i] = new int(i);
        cout << mas[i] << ' ';
    }
    for (int i = 0; i < 20; i++)
    {
        delete mas[i];
    }
    delete [] mas;

    return 0;
}