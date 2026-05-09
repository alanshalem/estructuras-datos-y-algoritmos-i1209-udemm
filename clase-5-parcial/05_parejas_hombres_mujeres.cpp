#include <iostream>
#include <queue>
#include <stack>
#include <list>
using namespace std;

struct strucPersona
{
    int dni;
    int edad;
};

struct strucPareja
{
    strucPersona hombre;
    strucPersona mujer;
};

int main()
{
    queue<strucPersona> hombres;
    stack<strucPersona> mujeres;
    list<strucPareja>   parejas;

    int datosHombres[] = {40000001, 25, 40000002, 27, 40000003, 29, 0};
    int datosMujeres[] = {39000002, 25, 39000001, 23, 0};

    int i = 0;
    while (datosHombres[i] != 0)
    {
        strucPersona p;
        p.dni  = datosHombres[i];
        p.edad = datosHombres[i + 1];
        hombres.push(p);
        i += 2;
    }

    i = 0;
    while (datosMujeres[i] != 0)
    {
        strucPersona p;
        p.dni  = datosMujeres[i];
        p.edad = datosMujeres[i + 1];
        mujeres.push(p);
        i += 2;
    }

    while (!hombres.empty() && !mujeres.empty())
    {
        strucPareja par;
        par.hombre = hombres.front();
        par.mujer  = mujeres.top();
        parejas.push_back(par);

        hombres.pop();
        mujeres.pop();
    }

    for (strucPareja p : parejas)
    {
        cout << p.hombre.dni  << ", " << p.hombre.edad << ", "
             << p.mujer.dni   << ", " << p.mujer.edad  << endl;
    }

    return 0;
}
