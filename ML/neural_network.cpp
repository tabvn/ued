#include <iostream> 
#include <math.h>

using namespace std;

struct NN
{
	double m1,w1,m2,w2,b;

	NN(double m1, double m2, double w1, double w2, double b){
		this->m1 = m1;
		this->m2 = m2;
		this->w1 = w1;
		this->w2 = w2;
		this->b = b;
	}
	double Sigmoid(){
		double x = (m1*w1) + (m2*w2) + b;
		return 1/(1+exp(-x));
	}

	double Const(){
		return pow((b -4),2);
	}

	double NumSlope(){
		double h = 0.0001;
		return (Const(b+h) - Const(b))/h;

	}
	double Slope(){
		return 2*(b-4);
	}
	
};

/**
cost(b) = (b-4)^2
b = b - 0.1 * slope(b);
slope = [const(b +h) - const(b)]/h;
slope = 2*(b-4);
*/

int main(){
	
	return 0;
}