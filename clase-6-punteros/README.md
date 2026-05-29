# Clase 6 - Punteros en C++

Ejercicios de la materia **Estructuras de Datos y Algoritmos** - UdeMM.

## ¿Qué es un puntero?

Un **puntero** es una variable que guarda la **dirección de memoria** de otra variable, en lugar de guardar un valor común.

```
   variable a            puntero c
  ┌──────────┐          ┌──────────────┐
  │   10     │  ◄────── │ 0x7ffe...a14 │   c guarda la direccion de a
  └──────────┘          └──────────────┘
   dir: 0x7ffe...a14

  *c  ->  10   (contenido: el valor guardado en esa direccion)
   c  ->  0x7ffe...a14   (la direccion en si)
```

## Operadores clave

| Operador | Nombre | Qué hace |
|----------|--------|----------|
| `&a` | dirección de | Devuelve la dirección de memoria donde vive `a` |
| `int* c` | declaración de puntero | `c` es una variable que guarda una dirección de un `int` |
| `*c` | contenido de (desreferencia) | Devuelve o modifica el valor guardado en la dirección a la que apunta `c` |
| `nullptr` | puntero nulo | El puntero no apunta a nada todavía |

## Aritmética de punteros

Sumar o restar a un puntero **no avanza de a 1 byte**, avanza del **tamaño del tipo**:

| Tipo | `c++` avanza |
|------|--------------|
| `char*` | 1 byte |
| `int*` | 4 bytes |
| `double*` | 8 bytes |

Por eso un puntero sirve para recorrer un arreglo: sus elementos están en memoria contigua.

## Archivos

| Archivo | Descripción |
|---------|-------------|
| `01_direccion_y_puntero.cpp` | `&` (dirección), `int*` y `*` (contenido); asignar `c = &a` |
| `02_modificar_memoria_con_puntero.cpp` | Modificar memoria con `*c = valor` |
| `03_puntero_a_double.cpp` | Mismo concepto con `double*` (aritmética de 8 bytes) |
| `04_puntero_a_arreglo.cpp` | Apuntar al primer elemento de un arreglo con `p = &v[0]` |
| `05_recorrer_arreglo_con_puntero.cpp` | Recorrer un arreglo con índice y con puntero (`p++`) |
| `06_puntero_a_char.cpp` | `char*`, ASCII y casteo a `(void*)` para ver la dirección |

> Nota: algunos ejemplos leen o escriben posiciones fuera del arreglo o desreferencian
> punteros sin inicializar **a propósito**, para mostrar que ahí hay "basura" (memoria
> que no nos pertenece). En un programa real eso se evita.

## Cómo compilar y ejecutar

### En Linux / Mac (terminal)

```bash
# Compilar (genera el ejecutable llamado "programa")
g++ nombre_del_archivo.cpp -o programa

# Ejecutar
./programa
```

### En Windows (PowerShell o CMD)

```powershell
# Compilar
g++ nombre_del_archivo.cpp -o programa.exe

# Ejecutar
.\programa.exe
```

### Ejemplo concreto

```bash
g++ 01_direccion_y_puntero.cpp -o programa
./programa
```

## Requisito: tener instalado g++

### Linux (Ubuntu/Debian)
```bash
sudo apt install g++
```

### Mac
```bash
xcode-select --install
```

### Windows
Instalar [MinGW](https://www.mingw-w64.org/) o usar el compilador que viene con VS Code + extensión C/C++.

## Header necesario

Los punteros son parte del lenguaje, no necesitan ningún header especial:

```cpp
#include <iostream>
```
