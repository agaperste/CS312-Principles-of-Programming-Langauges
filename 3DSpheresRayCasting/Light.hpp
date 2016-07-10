/*
 * Yingzhu Zhang, CS 312
 * Assignment 6
 * HEADER FILE FOR Light.cpp
 */

#include "Vector.hpp"
#include "rt.hpp"

#ifndef Light_hpp
#define Light_hpp

class Light
{
private:
	Vector loc;
public:
	Light(double x, double y, double z);
	COLOR_T illuminate(RAY_T ray, COLOR_T surface_col, Vector int_pt, Vector normal);
};

#endif