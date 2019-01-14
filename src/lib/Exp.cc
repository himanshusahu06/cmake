#include<cmath>
#include "Exp.h"

Exp::Exp(int n) {
	number = n;
}

double Exp::getExpo() {
	return exp(number);
}
