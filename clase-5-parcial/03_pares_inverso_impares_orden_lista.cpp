#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;

    int datos[] = {10, 15, 20, 25, 30, 35, 0};

    int i = 0;
    int n = datos[i];

    while (n != 0)
    {
        if (n % 2 == 0)
        {
            l.push_front(n);
        }
        else
        {
            l.push_back(n);
        }
        i++;
        n = datos[i];
    }

    for (int x : l)
    {
        cout << x << endl;
    }

    return 0;
}
