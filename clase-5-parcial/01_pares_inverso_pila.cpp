#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> p;

    int datos[] = {10, 15, 20, 25, 30, 35, 0};

    int i = 0;
    int n = datos[i];

    while (n != 0)
    {
        if (n % 2 == 0)
        {
            p.push(n);
        }
        i++;
        n = datos[i];
    }

    while (!p.empty())
    {
        cout << p.top() << endl;
        p.pop();
    }

    return 0;
}
