/*
 * Yingzhu Zhang, CS 312
 * Assignment 6
 * Sphere.cpp
 */
#include "Sphere.hpp"
#include <cmath>

void Sphere::set (Vector c, double r) {
    ctr = c;
    radius = r;
}

bool Sphere::intersect_sphere (RAY_T ray, double &t, Vector &int_pt, Vector &normal){
	double A = 1;
    
	double B = 2.0 * (ray.dir.dot(ray.orig-ctr));
    double C = (ray.orig - ctr).dot(ray.orig - ctr) - pow(radius, 2);
    
	double discriminant = pow(B, 2) - 4*A*C;
	if (discriminant <= 0) {
		return false;
	}
	else {
		double t0 = (-B + sqrt(discriminant))/(2*A);
		double t1 = (-B - sqrt(discriminant))/(2*A);
        
        t = fmin(t0, t1);
		if (t > 0) {
            int_pt = ray.orig + ray.dir * t;
            normal = (int_pt - ctr) / radius;
            return true;
        }
        else{
            return false;
        }
	}				
}