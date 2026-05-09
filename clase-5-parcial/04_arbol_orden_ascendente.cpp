#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> a;

    int datos[] = {20, 35, 10, 15, 0};

    int i = 0;
    int n = datos[i];

    while (n != 0)
    {
        a.insert(n);

        for (int x : a)
        {
            cout << x << " ";
        }
        cout << endl;

        i++;
        n = datos[i];
    }

    return 0;
}
