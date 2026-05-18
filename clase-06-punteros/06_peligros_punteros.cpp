// PELIGROS DE LOS PUNTEROS (que NO hay que hacer)
//
// Ejemplo original de la clase. Muestra errores comunes para
// entender POR QUE son peligrosos. NO usar este codigo como modelo.
//
// Problemas que aparecen aca:
//   1) Puntero sin inicializar: 'c' no apunta a nada -> usar *c es
//      comportamiento indefinido (puede imprimir basura o crashear).
//   2) Aritmetica de puntero que se va de la variable: c = &b; c++;
//      ahora c apunta a memoria que NO es nuestra.
//   3) Escribir ahi (*c = 'Z') pisa memoria de otra variable:
//      por eso 'a' puede cambiar sin que lo toquemos directo.
//
// Lección: un puntero solo es seguro si apunta a memoria valida nuestra.

#include <iostream>
using namespace std;

int main()
{
    int a = 72;
    char b = 'A';
    char* c;        // PELIGRO: puntero sin inicializar (no apunta a nada)

    cout << "&a=" << &a << " --- a=" << a << endl;
    cout << "&b=" << (void*)&b << " --- b=" << b << endl;
    // Usar *c aca es comportamiento indefinido (c no apunta a nada valido)
    cout << "c=" << (void*)c << endl;

    c = &b;         // ahora c apunta a b (esto si es valido)
    c++;            // PELIGRO: c ya no apunta a b, se fue afuera
    cout << "c=" << (void*)c << " --- *c=" << *c << endl; // basura

    *c = 'Z';       // PELIGRO: escribimos en memoria que no es nuestra
    cout << "a=" << a << endl; // puede haber cambiado por el efecto colateral

    return 0;
}
