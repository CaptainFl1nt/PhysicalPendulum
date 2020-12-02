#include <iostream>
#include <fstream>
#include <vector>
#include "RungeKuttaSolver.hpp"
#include "PhysicalPendulum.hpp"
using namespace std;

int main() {
    // setup read from file
    ifstream infile;
    infile.open("input.txt");
    
    // declare data values
    double dt, Tmax, m, I, d, temp;
    vector<double> y0(2);
    
    // read from file
    infile >> dt >> Tmax >> m >> I >> d;
    infile >> temp;
    y0[0] = temp;
    infile >> temp;
    y0[1] = temp;

    // solve system
    PhysicalPendulum pend = PhysicalPendulum(I, m, d);
    RungeKuttaSolver solver = RungeKuttaSolver(&pend, y0);

    solver.setDt(dt);
    solver.setTMax(Tmax);
    solver.Solve();

    solver.output("output.txt");
    return 0;
}
