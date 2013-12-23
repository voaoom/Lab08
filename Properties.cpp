#pragma once
#include "StdAfx.h"
#include "Properties.h"

Properties::Properties() :
	x_min(-10), x_max(10), x_grid(1),
	y_min(-10), y_max(10), y_grid(1),
	accuracy(3) {};

CArchive & operator<< ( CArchive & a, Properties & p) {
	a << p.x_min << p.x_max << p.x_grid << p.y_min << p.y_max << p.y_grid << p.accuracy;
	auto & f = p.functions;
	a << p.functions.size();
	for(int i = 0; i < p.functions.size(); ++i){
		auto & item = p.functions[i];
		a << f[i].first.a << f[i].first.b << f[i].first.c << f[i].second;
	}
	return a;
}
CArchive & operator>> ( CArchive & a, Properties & p ) {
	a >> p.x_min >> p.x_max >> p.x_grid >> p.y_min >> p.y_max >> p.y_grid >> p.accuracy;
	int size = 0;
	a >> size;
	for(int i = 0; i < size; ++i) {
		std::pair<Function, COLORREF> tmp;
		a >> tmp.first.a >> tmp.first.b >> tmp.first.c >> tmp.second;
		p.functions.push_back(tmp);
	}
	return a;

	return a;
}