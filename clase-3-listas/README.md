# Clase 3 - Listas (std::list) en C++

Ejercicios de la materia **Estructuras de Datos y Algoritmos** - UdeMM.

## ¿Qué es una lista?

`std::list` es una **lista doblemente enlazada**: cada nodo guarda un valor y los punteros al anterior y al siguiente.

```
   nullptr ← ┌────┐ ⇄ ┌────┐ ⇄ ┌────┐ → nullptr
             │ 10 │   │ 20 │   │ 5  │
   front() → └────┘   └────┘   └────┘ ← back()
```

- Insertar y eliminar en **cualquier posición** es O(1) (solo re-enlaza nodos).
- **NO** permite acceso por índice: no existe `l[2]`. Para navegar se usan iteradores + `advance()`.

## Operaciones principales

| Operación | Descripción |
|-----------|-------------|
| `l.push_back(x)` | Agrega `x` al final |
| `l.push_front(x)` | Agrega `x` al inicio |
| `l.pop_back()` | Elimina el último |
| `l.pop_front()` | Elimina el primero |
| `l.front()` / `l.back()` | Devuelve el primero / el último |
| `l.remove_if(pred)` | Elimina todos los que cumplen un predicado (lambda) |
| `l.sort()` | Ordena la lista de menor a mayor |
| `l.merge(l2)` | Fusiona dos listas **ordenadas** (deja `l2` vacía) |
| `l.splice(pos, l2)` | Mueve los nodos de `l2` dentro de `l` antes de `pos` (O(1), deja `l2` vacía) |
| `advance(it, n)` | Avanza el iterador `it` en `n` posiciones |

## Archivos

| Archivo | Descripción |
|---------|-------------|
| `01_creacion_y_push_back.cpp` | Crear una lista e insertar al final con `push_back` |
| `02_operaciones_basicas.cpp` | `push_front/back`, `front/back`, `pop`, `remove_if` con lambda |
| `03_merge_sin_ordenar.cpp` | `merge` sobre listas SIN ordenar (resultado desordenado) |
| `04_splice_al_inicio.cpp` | `splice` en `begin()` para insertar `l2` al principio |
| `05_splice_con_advance.cpp` | `splice` en posición intermedia usando `advance` |
| `06_iterador_y_advance.cpp` | Recorrido manual con iterador vs. for-range |
| `07_pares_y_impares_separados.cpp` | Impares al inicio y pares al final con `push_front`/`push_back` |

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
# El archivo 07 lee datos por teclado hasta ingresar 0
g++ 07_pares_y_impares_separados.cpp -o programa
./programa
# Ingresar: 10 15 30 7 0
# Salida:   7 15 10 30
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

## Header necesario para usar list

```cpp
#include <list>
```
