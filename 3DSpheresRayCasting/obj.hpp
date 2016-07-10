/*
 * Yingzhu Zhang, CS 312
 * Assignment 6
 * obj.hpp
 */

#ifndef obj_hpp
#define obj_hpp

#include "rt.hpp"
#include "Sphere.hpp"

typedef struct OBJ {
	Sphere sph;
	COLOR_T clr;
	struct OBJ *next;
}OBJ_T;

#endif