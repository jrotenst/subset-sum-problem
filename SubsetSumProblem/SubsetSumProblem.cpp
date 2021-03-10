#include <iostream>
#include "SubsetSumSolver.h"

using namespace std;

int main()
{
    SubsetSumSolver<int> solver;
    vector<int> set({0, 3, 4, 9, 23, 36, 54, 75, 81, 99});
    solver.solve(set, 13);
}
