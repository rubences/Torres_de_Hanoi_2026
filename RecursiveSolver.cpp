#include "RecursiveSolver.h"

void RecursiveSolver::solve() {
    solveRecursive(numDisks, origin, destination, auxiliary);
}

void RecursiveSolver::solveRecursive(int n, char orig, char dest, char aux) {
    if (n == 1) {
        moveCount++;
        std::cout << "Movimiento " << moveCount << ": Mover disco 1 de " 
                  << orig << " a " << dest << std::endl;
        return;
    }
    
    // Mover n-1 discos de origen a auxiliar usando destino
    solveRecursive(n - 1, orig, aux, dest);
    
    // Mover el disco n de origen a destino
    moveCount++;
    std::cout << "Movimiento " << moveCount << ": Mover disco " << n 
              << " de " << orig << " a " << dest << std::endl;
    
    // Mover n-1 discos de auxiliar a destino usando origen
    solveRecursive(n - 1, aux, dest, orig);
}
