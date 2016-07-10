/*
 * Yingzhu Zhang, CS 312
 * Assignment 6
 * HEADER FILE FOR Sphere.cpp
 */

#include "Vector.hpp"
#include "rt.hpp"

#ifndef Sphere_hpp
#define Sphere_hpp

class Sphere
{
private:
	Vector ctr;
	double radius;	
public:
 	void set(Vector c, double r);
 	bool intersect_sphere (RAY_T ray, double &t, Vector &int_pt, Vector &normal);
};

#endif