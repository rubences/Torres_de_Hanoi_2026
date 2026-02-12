#include <iostream>
#include <memory>
#include "HanoiSolver.h"
#include "RecursiveSolver.h"
#include "IterativeSolver.h"

using namespace std;

/**
 * Main function - Entry point of the application
 * Demonstrates Dependency Inversion Principle (DIP):
 * - Depends on HanoiSolver abstraction, not concrete implementations
 * - Uses polymorphism to work with different solver strategies
 */
int main() {
    int n;
    int option;
    
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
    cin >> option;
    
    if (cin.fail() || option < 1 || option > 2) {
        cout << "Error: Opción inválida. Debe ser 1 o 2." << endl;
        return 1;
    }
    
    cout << endl;
    
    char origin = 'A', destination = 'C', auxiliary = 'B';
    
    // Dependency Inversion: Using pointer to base class (abstraction)
    // Factory pattern: Creating appropriate solver based on user choice
    unique_ptr<HanoiSolver> solver;
    
    if (option == 1) {
        solver.reset(new RecursiveSolver(n, origin, destination, auxiliary));
    } else {
        solver.reset(new IterativeSolver(n, origin, destination, auxiliary));
    }
    
    cout << "=== SOLUCIÓN " << solver->getSolverName() << " ===" << endl;
    cout << "Moviendo " << n << " disco(s) de torre " << origin 
         << " a torre " << destination << endl;
    cout << endl;
    
    // Polymorphism: Call solve() on base class pointer
    solver->solve();
    
    cout << endl;
    cout << "Total de movimientos: " << solver->getMoveCount() << endl;
    
    return 0;
}
