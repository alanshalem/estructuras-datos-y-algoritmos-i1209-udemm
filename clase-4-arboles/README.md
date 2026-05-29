# Clase 4 - Árboles (std::set) en C++

Ejercicios de la materia **Estructuras de Datos y Algoritmos** - UdeMM.

## ¿Qué es un árbol (std::set)?

`std::set` es un **árbol binario de búsqueda balanceado** (normalmente un Red-Black Tree).

```
            30
          /    \
        15      40
       /  \       \
      10   20      50
```

Propiedades clave:

- Mantiene los elementos **siempre ordenados** de menor a mayor.
- **NO permite duplicados**: insertar un valor repetido no hace nada.
- `insert`, `find` y `erase` son **O(log n)**.
- Recorrerlo con for-range visita los elementos en **orden ascendente**.

## Operaciones principales

| Operación | Descripción |
|-----------|-------------|
| `a.insert(x)` | Inserta `x` en la posición que mantiene el orden |
| `a.find(x)` | Devuelve un iterador al nodo, o `a.end()` si no existe |
| `a.erase(x)` | Borra el nodo con valor `x` |
| `a.erase(it)` | Borra el nodo apuntado por el iterador `it` |
| `a.lower_bound(x)` | Iterador al primer elemento `>= x` |
| `a.upper_bound(x)` | Iterador al primer elemento `> x` |
| `a.clear()` | Vacía todo el árbol |
| `a.size()` | Cantidad de elementos |
| `*it` | Desreferencia un iterador para obtener el valor |
| `advance(it, n)` | Mueve el iterador `n` posiciones (negativo = retroceder) |

> En la cursada: recorrer de `begin()` a `end()` = **pre orden** (ascendente);
> de `end()` a `begin()` = **post orden** (descendente). `end()` apunta a "una
> posición después del último", no es un elemento válido.

## Archivos

| Archivo | Descripción |
|---------|-------------|
| `01-arboles-ordenados.cpp` | El set ordena solo; `insert` ubica en su lugar |
| `02-busqueda-find.cpp` | `find` y comparación contra `end()` |
| `03-recorridos-pre-y-post-orden.cpp` | Recorrido ascendente y descendente con `advance` |
| `04-lower-y-upper-bound.cpp` | `lower_bound` y `upper_bound` para acotar |
| `05-erase-y-clear.cpp` | Borrar por valor, por iterador, y vaciar con `clear` |
| `06-insertar-ordenado-hasta-cero.cpp` | Ingresar hasta 0 y mostrar ordenado cada vez |

## Cómo compilar y ejecutar

### En Linux / Mac (terminal)

```bash
g++ nombre_del_archivo.cpp -o programa
./programa
```

### En Windows (PowerShell o CMD)

```powershell
g++ nombre_del_archivo.cpp -o programa.exe
.\programa.exe
```

### Ejemplo concreto

```bash
# El archivo 06 lee datos por teclado hasta ingresar 0
g++ 06-insertar-ordenado-hasta-cero.cpp -o programa
./programa
# Ingresar: 20 35 10 15 0
# Salida:   20
#           20 35
#           10 20 35
#           10 15 20 35
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

## Header necesario para usar set

```cpp
#include <set>
```
