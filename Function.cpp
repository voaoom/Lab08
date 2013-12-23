#pragma once
#include "stdafx.h"
#include "Function.h"

#define _USE_MATH_DEFINES
#include <math.h>

Function::Function() {
	a = 10.0 * rand() / RAND_MAX;
	b = 5.0 * rand() / RAND_MAX;
	c = 2 * M_PI * rand() / RAND_MAX / b;
}
Function::Function(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

CString Function::name() {
	CString tmp;
	tmp.Format(_T("%g * sin(%g * x + %g)"), a, b, c);
	return tmp;
}
double Function::f(double x) {
	return a * sin(b * x + c);
}