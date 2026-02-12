#ifndef HANOI_SOLVER_H
#define HANOI_SOLVER_H

#include <string>

/**
 * Abstract base class for Hanoi Tower solvers
 * Follows the Interface Segregation Principle (ISP) and Open/Closed Principle (OCP)
 * This class defines the contract that all Hanoi solvers must implement
 */
class HanoiSolver {
protected:
    int numDisks;
    char origin;
    char destination;
    char auxiliary;
    int moveCount;

public:
    /**
     * Constructor
     * @param n Number of disks
     * @param orig Origin tower
     * @param dest Destination tower
     * @param aux Auxiliary tower
     */
    HanoiSolver(int n, char orig = 'A', char dest = 'C', char aux = 'B')
        : numDisks(n), origin(orig), destination(dest), auxiliary(aux), moveCount(0) {}

    /**
     * Virtual destructor for proper cleanup in derived classes
     */
    virtual ~HanoiSolver() {}

    /**
     * Pure virtual method to solve the Hanoi puzzle
     * Must be implemented by derived classes (Open/Closed Principle)
     */
    virtual void solve() = 0;

    /**
     * Get the total number of moves performed
     * @return Total number of moves
     */
    virtual int getMoveCount() const {
        return moveCount;
    }

    /**
     * Get the name/type of the solver
     * @return String with the solver name
     */
    virtual std::string getSolverName() const = 0;

    /**
     * Reset the move counter
     */
    virtual void reset() {
        moveCount = 0;
    }
};

#endif // HANOI_SOLVER_H
