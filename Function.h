#pragma once
#include "stdafx.h"

class Function
{
public:
	Function();
	Function(double a, double b, double c);
	double a, b, c;
	CString name();
	double f(double x);
};

