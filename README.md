# Estructuras de Datos y Algoritmos - UdeMM

Repositorio de ejercicios de la materia **Estructuras de Datos y Algoritmos** (i1209) de la Universidad de la Marina Mercante.

## Contenido

| Carpeta | Temas |
|---------|-------|
| [clase-00-fundamentos-cpp/](clase-00-fundamentos-cpp/) | Variables, tipos, cin/cout, operadores, if/else, while, for, funciones |
| [clase-1-pilas-stack/](clase-1-pilas-stack/) | Stack (LIFO), operaciones básicas, ejercicios con entrada de usuario |
| [clase-2-colas-queues-structs/](clase-2-colas-queues-structs/) | Queue (FIFO), Struct, constructor, push vs emplace |
| [clase-3-listas/](clase-3-listas/) | std::list, push/pop, remove_if, sort, merge, splice, iteradores y advance |
| [clase-4-arboles/](clase-4-arboles/) | std::set (BST balanceado): inserción, find, recorridos pre/post, lower/upper_bound, erase y clear |
| [clase-06-punteros/](clase-06-punteros/) | Punteros desde cero: `&` y `*`, modificar via puntero, arrays y aritmética, pasaje por puntero, memoria dinámica `new`/`delete` |

## Cómo compilar y ejecutar

### Requisito: tener instalado g++

**Linux (Ubuntu/Debian)**
```bash
sudo apt install g++
```

**Mac**
```bash
xcode-select --install
```

**Windows** — instalar [MinGW](https://www.mingw-w64.org/) o usar el compilador del VS Code con la extensión C/C++.

---

### Linux / Mac

```bash
# Compilar
g++ nombre_del_archivo.cpp -o programa

# Ejecutar
./programa
```

### Windows (PowerShell)

```powershell
# Compilar
g++ nombre_del_archivo.cpp -o programa.exe

# Ejecutar
.\programa.exe
```

### Ejemplo completo

```bash
cd clase-1-pilas-stack
g++ 03_mostrar_en_orden_inverso.cpp -o programa
./programa
# Escribir: 10 20 30 0  (y presionar Enter)
# Salida:
# 30
# 20
# 10
```

---

## Conceptos clave

### Stack vs Queue

| | Stack (Pila) | Queue (Cola) |
|---|---|---|
| Principio | LIFO — último en entrar, primero en salir | FIFO — primero en entrar, primero en salir |
| Analogía | Pila de platos | Fila en un banco |
| Header | `#include <stack>` | `#include <queue>` |
| Ver elemento | `top()` | `front()` / `back()` |
| Agregar | `push(x)` | `push(x)` / `emplace(...)` |
| Eliminar | `pop()` | `pop()` |

### Struct

Permite crear tipos de datos personalizados agrupando campos:

```cpp
struct Persona {
    int dni;
    int edad;
};
```

Con constructor para inicializar más cómodamente:

```cpp
struct Persona {
    int dni;
    int edad;
    Persona(int e, int d) { this->edad = e; this->dni = d; }
};
```
