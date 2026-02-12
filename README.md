# Torres_de_Hanoi_2026

Torres de Hanoi en C++ con Arquitectura OOP y Principios SOLID

## Descripción

Este proyecto implementa el clásico problema de las Torres de Hanoi en C++ usando una arquitectura orientada a objetos que sigue los principios SOLID. El código está modularizado en componentes independientes:

- **Solución Recursiva**: Implementación elegante usando recursividad
- **Solución Iterativa**: Implementación usando pilas (stacks) y un algoritmo iterativo
- **Arquitectura OOP**: Clase base abstracta con implementaciones concretas
- **Principios SOLID**: Código mantenible, extensible y testeable

## Arquitectura del Proyecto

### Estructura de Archivos

```
├── HanoiSolver.h          # Clase base abstracta (Interfaz)
├── RecursiveSolver.h      # Declaración del solver recursivo
├── RecursiveSolver.cpp    # Implementación del solver recursivo
├── IterativeSolver.h      # Declaración del solver iterativo
├── IterativeSolver.cpp    # Implementación del solver iterativo
├── main.cpp               # Punto de entrada de la aplicación
└── Makefile               # Sistema de compilación
```

### Principios SOLID Aplicados

1. **Single Responsibility Principle (SRP)**: Cada clase tiene una única responsabilidad
   - `RecursiveSolver`: Solo maneja la solución recursiva
   - `IterativeSolver`: Solo maneja la solución iterativa
   - `main.cpp`: Solo maneja la entrada/salida y coordinación

2. **Open/Closed Principle (OCP)**: Las clases están abiertas a extensión pero cerradas a modificación
   - Se pueden añadir nuevos tipos de solvers sin modificar el código existente
   - Solo se necesita heredar de `HanoiSolver` y implementar `solve()`

3. **Liskov Substitution Principle (LSP)**: Las clases derivadas pueden sustituir a la base
   - `RecursiveSolver` y `IterativeSolver` son intercambiables
   - Ambos cumplen el contrato definido por `HanoiSolver`

4. **Interface Segregation Principle (ISP)**: Interfaces específicas y cohesivas
   - `HanoiSolver` define solo los métodos necesarios para resolver el problema
   - No hay métodos innecesarios que las clases derivadas deban implementar

5. **Dependency Inversion Principle (DIP)**: Depender de abstracciones, no de implementaciones
   - `main.cpp` depende de `HanoiSolver` (abstracción), no de las clases concretas
   - Se usa polimorfismo para trabajar con diferentes implementaciones

## El Problema de las Torres de Hanoi

Las Torres de Hanoi es un rompecabezas matemático que consiste en tres torres y varios discos de diferentes tamaños que pueden deslizarse en cualquier torre. El rompecabezas comienza con los discos apilados en orden ascendente de tamaño en una torre, el más pequeño en la parte superior.

**Reglas:**
1. Solo se puede mover un disco a la vez
2. Un disco más grande nunca puede colocarse sobre uno más pequeño
3. Solo se puede mover el disco superior de cualquier torre

**Objetivo:** Mover toda la pila de discos de la torre inicial (A) a la torre final (C), usando una torre auxiliar (B).

## Compilación

El proyecto incluye un Makefile para facilitar la compilación:

```bash
make
```

O compilar manualmente:

```bash
g++ -std=c++11 -Wall -Wextra -O2 -o hanoi hanoi.cpp
```

## Uso

Ejecutar el programa:

```bash
./hanoi
```

El programa solicitará:
1. El número de discos (debe ser mayor que 0)
2. El método de solución (1 para Recursivo, 2 para Iterativo)

### Ejemplo de Uso

```
==================================================
         TORRES DE HANOI EN C++                  
==================================================

Ingrese el número de discos: 3

Seleccione el método de solución:
1. Recursivo
2. Iterativo
Opción: 1

=== SOLUCIÓN RECURSIVA ===
Moviendo 3 disco(s) de torre A a torre C

Movimiento 1: Mover disco 1 de A a C
Movimiento 2: Mover disco 2 de A a B
Movimiento 3: Mover disco 1 de C a B
Movimiento 4: Mover disco 3 de A a C
Movimiento 5: Mover disco 1 de B a A
Movimiento 6: Mover disco 2 de B a C
Movimiento 7: Mover disco 1 de A a C

Total de movimientos: 7
```

## Complejidad

El número mínimo de movimientos para resolver el problema con n discos es **2^n - 1**.

| Discos | Movimientos |
|--------|-------------|
| 1      | 1           |
| 2      | 3           |
| 3      | 7           |
| 4      | 15          |
| 5      | 31          |
| n      | 2^n - 1     |

## Características Técnicas

- **Lenguaje:** C++11
- **Estructuras de datos:** Stack (para solución iterativa)
- **Paradigmas:** Recursividad y programación iterativa
- **Entrada/Salida:** Consola interactiva

## Limpieza

Para eliminar los archivos compilados:

```bash
make clean
```

## Autor

2026
