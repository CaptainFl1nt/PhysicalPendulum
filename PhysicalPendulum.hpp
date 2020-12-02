#include <vector>
#include <cmath>
#include "DifferentialEquation.hpp"
using namespace std;


class PhysicalPendulum : public DifferentialEquation {
    private:
        double moi;     // moment of interia
	double mass;    // mass of pendulum
	double dist;    // distance between pivot and COM
	double g;       // local acc. due to gravity
    public:
	PhysicalPendulum() { }
	PhysicalPendulum(double I, double m, double d);

	void setMoI(double I) { moi = I; }
	void setMass(double m) { mass = m; }
	void setDist(double d) { dist = d; }
	void setG(double g) { this->g = g; }

        vector<double> equation(vector<double> y, double t);
};


/**
 * Equation of motion for the physical pendulum. These are obtained by
 * the Hamiltonian, H = p^2/(2I) - mgd*cos(theta).
 * Equations:
 * (1)    d(theta)/dt = p/I
 * (2)    dp/dt = -mgd*sin(theta)
 */
vector<double> PhysicalPendulum::equation(vector<double> y, double t) {
    vector<double> yp(2);
    yp.at(0) = y.at(1)/moi;
    yp.at(1) = -mass*g*dist*sin(y.at(0));
    return yp;
}

// Constructors
PhysicalPendulum::PhysicalPendulum(double I, double m, double d) {
   moi = I;
   mass = m;
   dist = d;
   g = 9.81;
}
