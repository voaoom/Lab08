#pragma once
#include "StdAfx.h"
#include <vector>
#include <utility>
#include "Function.h"

class Properties
{
public:
	Properties();
	double x_min, x_max, x_grid;
	double y_min, y_max, y_grid;
	int accuracy;
	std::vector<std::pair<Function, COLORREF>> functions;
	friend CArchive & operator<< ( CArchive & archive, Properties & properties);
	friend CArchive & operator>> ( CArchive & archive, Properties & properties);
};

