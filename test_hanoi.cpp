#include <iostream>
#include <sstream>
#include <cassert>
#include "HanoiSolver.h"
#include "RecursiveSolver.h"
#include "IterativeSolver.h"

using namespace std;

/**
 * Test helper function to capture output
 */
string captureOutput(HanoiSolver* solver) {
    // Redirect cout to a stringstream
    streambuf* oldCout = cout.rdbuf();
    ostringstream capturedOutput;
    cout.rdbuf(capturedOutput.rdbuf());
    
    solver->solve();
    
    // Restore cout
    cout.rdbuf(oldCout);
    
    return capturedOutput.str();
}

/**
 * Test that the number of moves matches the expected formula (2^n - 1)
 */
void testMoveCount(int n, HanoiSolver* solver, const string& solverName) {
    int expectedMoves = (1 << n) - 1; // 2^n - 1
    
    captureOutput(solver);
    int actualMoves = solver->getMoveCount();
    
    cout << "Test " << solverName << " con " << n << " disco(s): ";
    assert(actualMoves == expectedMoves);
    cout << "OK (Movimientos: " << actualMoves << "/" << expectedMoves << ")" << endl;
}

/**
 * Test edge case with 1 disk
 */
void testSingleDisk() {
    cout << "\n=== Test: Un solo disco ===" << endl;
    
    RecursiveSolver recursiveSolver(1);
    testMoveCount(1, &recursiveSolver, "Recursivo");
    
    IterativeSolver iterativeSolver(1);
    testMoveCount(1, &iterativeSolver, "Iterativo");
}

/**
 * Test with small number of disks (2-5)
 */
void testSmallNumbers() {
    cout << "\n=== Test: Números pequeños (2-5 discos) ===" << endl;
    
    for (int n = 2; n <= 5; n++) {
        RecursiveSolver recursiveSolver(n);
        testMoveCount(n, &recursiveSolver, "Recursivo");
        
        IterativeSolver iterativeSolver(n);
        testMoveCount(n, &iterativeSolver, "Iterativo");
    }
}

/**
 * Test with larger numbers (6-10)
 */
void testLargeNumbers() {
    cout << "\n=== Test: Números grandes (6-10 discos) ===" << endl;
    
    for (int n = 6; n <= 10; n++) {
        RecursiveSolver recursiveSolver(n);
        testMoveCount(n, &recursiveSolver, "Recursivo");
        
        IterativeSolver iterativeSolver(n);
        testMoveCount(n, &iterativeSolver, "Iterativo");
    }
}

/**
 * Test that both solvers produce the same results
 */
void testConsistency() {
    cout << "\n=== Test: Consistencia entre solvers ===" << endl;
    
    for (int n = 1; n <= 5; n++) {
        RecursiveSolver recursiveSolver(n);
        IterativeSolver iterativeSolver(n);
        
        string recursiveOutput = captureOutput(&recursiveSolver);
        string iterativeOutput = captureOutput(&iterativeSolver);
        
        cout << "Test consistencia con " << n << " disco(s): ";
        assert(recursiveSolver.getMoveCount() == iterativeSolver.getMoveCount());
        assert(recursiveOutput == iterativeOutput);
        cout << "OK" << endl;
    }
}

/**
 * Test different tower configurations
 */
void testDifferentTowerConfigurations() {
    cout << "\n=== Test: Diferentes configuraciones de torres ===" << endl;
    
    // Test A->B using C
    RecursiveSolver solver1(3, 'A', 'B', 'C');
    captureOutput(&solver1);
    cout << "Test A->B usando C: ";
    assert(solver1.getMoveCount() == 7);
    cout << "OK" << endl;
    
    // Test B->C using A
    RecursiveSolver solver2(3, 'B', 'C', 'A');
    captureOutput(&solver2);
    cout << "Test B->C usando A: ";
    assert(solver2.getMoveCount() == 7);
    cout << "OK" << endl;
    
    // Test C->A using B
    RecursiveSolver solver3(3, 'C', 'A', 'B');
    captureOutput(&solver3);
    cout << "Test C->A usando B: ";
    assert(solver3.getMoveCount() == 7);
    cout << "OK" << endl;
}

/**
 * Test reset functionality
 */
void testReset() {
    cout << "\n=== Test: Funcionalidad de reset ===" << endl;
    
    RecursiveSolver solver(3);
    
    // First solve
    captureOutput(&solver);
    int firstCount = solver.getMoveCount();
    
    // Reset
    solver.reset();
    cout << "Test reset: ";
    assert(solver.getMoveCount() == 0);
    
    // Solve again
    captureOutput(&solver);
    int secondCount = solver.getMoveCount();
    
    assert(firstCount == secondCount);
    assert(secondCount == 7);
    cout << "OK" << endl;
}

/**
 * Test solver name retrieval
 */
void testSolverNames() {
    cout << "\n=== Test: Nombres de solvers ===" << endl;
    
    RecursiveSolver recursiveSolver(3);
    IterativeSolver iterativeSolver(3);
    
    cout << "Test nombre recursivo: ";
    assert(recursiveSolver.getSolverName() == "Recursivo");
    cout << "OK" << endl;
    
    cout << "Test nombre iterativo: ";
    assert(iterativeSolver.getSolverName() == "Iterativo");
    cout << "OK" << endl;
}

/**
 * Stress test with very large number (15 disks = 32767 moves)
 */
void testStress() {
    cout << "\n=== Test: Stress test (15 discos) ===" << endl;
    
    RecursiveSolver recursiveSolver(15);
    captureOutput(&recursiveSolver);
    cout << "Test stress recursivo: ";
    assert(recursiveSolver.getMoveCount() == 32767);
    cout << "OK" << endl;
    
    IterativeSolver iterativeSolver(15);
    captureOutput(&iterativeSolver);
    cout << "Test stress iterativo: ";
    assert(iterativeSolver.getMoveCount() == 32767);
    cout << "OK" << endl;
}

int main() {
    cout << "==================================================" << endl;
    cout << "    TESTS DE ROBUSTEZ - TORRES DE HANOI          " << endl;
    cout << "==================================================" << endl;
    
    try {
        testSingleDisk();
        testSmallNumbers();
        testLargeNumbers();
        testConsistency();
        testDifferentTowerConfigurations();
        testReset();
        testSolverNames();
        testStress();
        
        cout << "\n==================================================" << endl;
        cout << "    TODOS LOS TESTS PASARON EXITOSAMENTE!        " << endl;
        cout << "==================================================" << endl;
        
        return 0;
    } catch (const exception& e) {
        cerr << "\n¡ERROR! Test falló: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "\n¡ERROR! Test falló con excepción desconocida" << endl;
        return 1;
    }
}
