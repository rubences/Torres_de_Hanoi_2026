#include <iostream>
#include <stack>

using namespace std;

// Declaración anticipada de la función auxiliar
void moverDisco(stack<int>* torre1, stack<int>* torre2, char nombre1, char nombre2, int& movimientos);

// Función recursiva para resolver las Torres de Hanoi
void hanoiRecursivo(int n, char origen, char destino, char auxiliar, int& movimientos) {
    if (n == 1) {
        movimientos++;
        cout << "Movimiento " << movimientos << ": Mover disco 1 de " << origen << " a " << destino << endl;
        return;
    }
    
    // Mover n-1 discos de origen a auxiliar usando destino
    hanoiRecursivo(n - 1, origen, auxiliar, destino, movimientos);
    
    // Mover el disco n de origen a destino
    movimientos++;
    cout << "Movimiento " << movimientos << ": Mover disco " << n << " de " << origen << " a " << destino << endl;
    
    // Mover n-1 discos de auxiliar a destino usando origen
    hanoiRecursivo(n - 1, auxiliar, destino, origen, movimientos);
}

// Función iterativa para resolver las Torres de Hanoi
void hanoiIterativo(int n, char origen, char destino, char auxiliar) {
    // Calculamos el número total de movimientos
    int totalMovimientos = (1 << n) - 1; // 2^n - 1
    
    // Creamos tres pilas para representar las tres torres
    stack<int> torreOrigen, torreDestino, torreAuxiliar;
    
    // Inicializamos la torre origen con los discos
    for (int i = n; i >= 1; i--) {
        torreOrigen.push(i);
    }
    
    // Determinar las torres según si n es par o impar
    stack<int>* torres[3];
    char nombres[3];
    
    if (n % 2 == 0) {
        // Si n es par: origen -> auxiliar -> destino -> origen
        torres[0] = &torreOrigen;
        torres[1] = &torreAuxiliar;
        torres[2] = &torreDestino;
        nombres[0] = origen;
        nombres[1] = auxiliar;
        nombres[2] = destino;
    } else {
        // Si n es impar: origen -> destino -> auxiliar -> origen
        torres[0] = &torreOrigen;
        torres[1] = &torreDestino;
        torres[2] = &torreAuxiliar;
        nombres[0] = origen;
        nombres[1] = destino;
        nombres[2] = auxiliar;
    }
    
    int movimientos = 0;
    
    for (int i = 1; i <= totalMovimientos; i++) {
        if (i % 3 == 1) {
            // Mover entre torre 0 y torre 1
            moverDisco(torres[0], torres[1], nombres[0], nombres[1], movimientos);
        } else if (i % 3 == 2) {
            // Mover entre torre 0 y torre 2
            moverDisco(torres[0], torres[2], nombres[0], nombres[2], movimientos);
        } else if (i % 3 == 0) {
            // Mover entre torre 1 y torre 2
            moverDisco(torres[1], torres[2], nombres[1], nombres[2], movimientos);
        }
    }
}

// Función auxiliar para mover un disco entre dos torres (para iterativo)
void moverDisco(stack<int>* torre1, stack<int>* torre2, char nombre1, char nombre2, int& movimientos) {
    // Si ambas torres están vacías, no hacer nada
    if (torre1->empty() && torre2->empty()) {
        return;
    }
    
    // Si torre1 está vacía, mover de torre2 a torre1
    if (torre1->empty()) {
        int disco = torre2->top();
        torre2->pop();
        torre1->push(disco);
        movimientos++;
        cout << "Movimiento " << movimientos << ": Mover disco " << disco << " de " << nombre2 << " a " << nombre1 << endl;
    }
    // Si torre2 está vacía, mover de torre1 a torre2
    else if (torre2->empty()) {
        int disco = torre1->top();
        torre1->pop();
        torre2->push(disco);
        movimientos++;
        cout << "Movimiento " << movimientos << ": Mover disco " << disco << " de " << nombre1 << " a " << nombre2 << endl;
    }
    // Si ambas torres tienen discos, mover el más pequeño al tope de la más grande
    else {
        int disco1 = torre1->top();
        int disco2 = torre2->top();
        
        if (disco1 < disco2) {
            torre1->pop();
            torre2->push(disco1);
            movimientos++;
            cout << "Movimiento " << movimientos << ": Mover disco " << disco1 << " de " << nombre1 << " a " << nombre2 << endl;
        } else {
            torre2->pop();
            torre1->push(disco2);
            movimientos++;
            cout << "Movimiento " << movimientos << ": Mover disco " << disco2 << " de " << nombre2 << " a " << nombre1 << endl;
        }
    }
}

int main() {
    int n;
    int opcion;
    
    cout << "==================================================" << endl;
    cout << "         TORRES DE HANOI EN C++                  " << endl;
    cout << "==================================================" << endl;
    cout << endl;
    
    cout << "Ingrese el número de discos: ";
    cin >> n;
    
    if (cin.fail() || n <= 0) {
        cout << "Error: El número de discos debe ser mayor que 0." << endl;
        return 1;
    }
    
    cout << endl;
    cout << "Seleccione el método de solución:" << endl;
    cout << "1. Recursivo" << endl;
    cout << "2. Iterativo" << endl;
    cout << "Opción: ";
    cin >> opcion;
    
    if (cin.fail() || opcion < 1 || opcion > 2) {
        cout << "Error: Opción inválida. Debe ser 1 o 2." << endl;
        return 1;
    }
    
    cout << endl;
    
    char origen = 'A', destino = 'C', auxiliar = 'B';
    
    if (opcion == 1) {
        cout << "=== SOLUCIÓN RECURSIVA ===" << endl;
        cout << "Moviendo " << n << " disco(s) de torre " << origen << " a torre " << destino << endl;
        cout << endl;
        int movimientos = 0;
        hanoiRecursivo(n, origen, destino, auxiliar, movimientos);
        cout << endl;
        cout << "Total de movimientos: " << movimientos << endl;
    } else {
        cout << "=== SOLUCIÓN ITERATIVA ===" << endl;
        cout << "Moviendo " << n << " disco(s) de torre " << origen << " a torre " << destino << endl;
        cout << endl;
        hanoiIterativo(n, origen, destino, auxiliar);
        int totalMovimientos = (1 << n) - 1;
        cout << endl;
        cout << "Total de movimientos: " << totalMovimientos << endl;
    }
    
    return 0;
}
