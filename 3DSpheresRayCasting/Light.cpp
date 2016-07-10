/*
 * Yingzhu Zhang, CS 312
 * Assignment 6
 * Light.cpp
 */
#include <cmath>
#include "Light.hpp"

Light::Light (double x, double y, double z) {
    loc.set(x, y, z);
}

COLOR_T Light::illuminate(RAY_T ray, COLOR_T surface_col, Vector int_pt, Vector normal) {
	COLOR_T col;

	//ambient
	col.R = surface_col.R * 0.1;
	col.G = surface_col.G * 0.1;
	col.B = surface_col.B * 0.1;

	//diffuse
	double dot;
	Vector L;
	L = loc - int_pt;
	L.normalize();
	dot = L.dot(normal);
	if (dot > 0) {
		col.R += dot * surface_col.R;
		col.G += dot * surface_col.G;
		col.B += dot * surface_col.B;

		//speculate
		Vector R;
		R = L - (normal * normal.dot(L) * 2);
		R.normalize();
		double dot2 = R.dot(ray.dir);
		if (dot2 > 0) {
			col.R += pow(dot2, 200);
			col.G += pow(dot2, 200);
			col.B += pow(dot2, 200);
		}//dot2>0
	}//dot>0
	return col;
}
