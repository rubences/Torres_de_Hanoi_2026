#ifndef ITERATIVE_SOLVER_H
#define ITERATIVE_SOLVER_H

#include "HanoiSolver.h"
#include <stack>
#include <iostream>

/**
 * Iterative implementation of the Hanoi Tower solver
 * Follows the Single Responsibility Principle (SRP) - only handles iterative solving
 * Follows the Liskov Substitution Principle (LSP) - can substitute HanoiSolver
 */
class IterativeSolver : public HanoiSolver {
private:
    /**
     * Helper method to move a disk between two towers
     * @param tower1 First tower
     * @param tower2 Second tower
     * @param name1 Name of first tower
     * @param name2 Name of second tower
     */
    void moveDisk(std::stack<int>* tower1, std::stack<int>* tower2, 
                  char name1, char name2);

public:
    /**
     * Constructor
     * @param n Number of disks
     * @param orig Origin tower
     * @param dest Destination tower
     * @param aux Auxiliary tower
     */
    IterativeSolver(int n, char orig = 'A', char dest = 'C', char aux = 'B')
        : HanoiSolver(n, orig, dest, aux) {}

    /**
     * Solve the puzzle using iterative algorithm
     */
    void solve() override;

    /**
     * Get the solver name
     * @return Name of the solver
     */
    std::string getSolverName() const override {
        return "Iterativo";
    }
};

#endif // ITERATIVE_SOLVER_H
