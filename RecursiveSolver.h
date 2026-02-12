#ifndef RECURSIVE_SOLVER_H
#define RECURSIVE_SOLVER_H

#include "HanoiSolver.h"
#include <iostream>

/**
 * Recursive implementation of the Hanoi Tower solver
 * Follows the Single Responsibility Principle (SRP) - only handles recursive solving
 * Follows the Liskov Substitution Principle (LSP) - can substitute HanoiSolver
 */
class RecursiveSolver : public HanoiSolver {
private:
    /**
     * Recursive helper method to solve Hanoi puzzle
     * @param n Number of disks to move
     * @param orig Origin tower
     * @param dest Destination tower
     * @param aux Auxiliary tower
     */
    void solveRecursive(int n, char orig, char dest, char aux);

public:
    /**
     * Constructor
     * @param n Number of disks
     * @param orig Origin tower
     * @param dest Destination tower
     * @param aux Auxiliary tower
     */
    RecursiveSolver(int n, char orig = 'A', char dest = 'C', char aux = 'B')
        : HanoiSolver(n, orig, dest, aux) {}

    /**
     * Solve the puzzle using recursive algorithm
     */
    void solve() override;

    /**
     * Get the solver name
     * @return Name of the solver
     */
    std::string getSolverName() const override {
        return "Recursivo";
    }
};

#endif // RECURSIVE_SOLVER_H
