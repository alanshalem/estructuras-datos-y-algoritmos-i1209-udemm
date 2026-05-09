#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> c;

    int datos[] = {10, 15, 20, 25, 30, 35, 0};

    int i = 0;
    int n = datos[i];

    while (n != 0)
    {
        if (n % 2 != 0)
        {
            c.push(n);
        }
        i++;
        n = datos[i];
    }

    while (!c.empty())
    {
        cout << c.front() << endl;
        c.pop();
    }

    return 0;
}
