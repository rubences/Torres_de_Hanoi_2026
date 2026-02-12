#include "IterativeSolver.h"

void IterativeSolver::solve() {
    // Calculamos el número total de movimientos
    int totalMoves = (1 << numDisks) - 1; // 2^n - 1
    
    // Creamos tres pilas para representar las tres torres
    std::stack<int> towerOrigin, towerDestination, towerAuxiliary;
    
    // Inicializamos la torre origen con los discos
    for (int i = numDisks; i >= 1; i--) {
        towerOrigin.push(i);
    }
    
    // Determinar las torres según si n es par o impar
    std::stack<int>* towers[3];
    char names[3];
    
    if (numDisks % 2 == 0) {
        // Si n es par: origen -> auxiliar -> destino -> origen
        towers[0] = &towerOrigin;
        towers[1] = &towerAuxiliary;
        towers[2] = &towerDestination;
        names[0] = origin;
        names[1] = auxiliary;
        names[2] = destination;
    } else {
        // Si n es impar: origen -> destino -> auxiliar -> origen
        towers[0] = &towerOrigin;
        towers[1] = &towerDestination;
        towers[2] = &towerAuxiliary;
        names[0] = origin;
        names[1] = destination;
        names[2] = auxiliary;
    }
    
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            // Mover entre torre 0 y torre 1
            moveDisk(towers[0], towers[1], names[0], names[1]);
        } else if (i % 3 == 2) {
            // Mover entre torre 0 y torre 2
            moveDisk(towers[0], towers[2], names[0], names[2]);
        } else if (i % 3 == 0) {
            // Mover entre torre 1 y torre 2
            moveDisk(towers[1], towers[2], names[1], names[2]);
        }
    }
}

void IterativeSolver::moveDisk(std::stack<int>* tower1, std::stack<int>* tower2, 
                                char name1, char name2) {
    // Si ambas torres están vacías, no hacer nada
    if (tower1->empty() && tower2->empty()) {
        return;
    }
    
    // Si tower1 está vacía, mover de tower2 a tower1
    if (tower1->empty()) {
        int disk = tower2->top();
        tower2->pop();
        tower1->push(disk);
        moveCount++;
        std::cout << "Movimiento " << moveCount << ": Mover disco " << disk 
                  << " de " << name2 << " a " << name1 << std::endl;
    }
    // Si tower2 está vacía, mover de tower1 a tower2
    else if (tower2->empty()) {
        int disk = tower1->top();
        tower1->pop();
        tower2->push(disk);
        moveCount++;
        std::cout << "Movimiento " << moveCount << ": Mover disco " << disk 
                  << " de " << name1 << " a " << name2 << std::endl;
    }
    // Si ambas torres tienen discos, mover el más pequeño al tope de la más grande
    else {
        int disk1 = tower1->top();
        int disk2 = tower2->top();
        
        if (disk1 < disk2) {
            tower1->pop();
            tower2->push(disk1);
            moveCount++;
            std::cout << "Movimiento " << moveCount << ": Mover disco " << disk1 
                      << " de " << name1 << " a " << name2 << std::endl;
        } else {
            tower2->pop();
            tower1->push(disk2);
            moveCount++;
            std::cout << "Movimiento " << moveCount << ": Mover disco " << disk2 
                      << " de " << name2 << " a " << name1 << std::endl;
        }
    }
}
