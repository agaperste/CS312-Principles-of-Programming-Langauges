/*
 * Yingzhu Zhang, CS 312
 * Assignment 5
 * HEADER FILE FOR rc.c
 */

#include "vec.h"

typedef struct{
	VEC_T orig;
	VEC_T dir;
}RAY_T;

typedef struct{
	double R;
	double G;
	double B;
}COLOR_T;

typedef struct{
	VEC_T ctr;
	double radius;
}SPHERE_T;

typedef struct OBJ {
	SPHERE_T sph;
	COLOR_T clr;
	struct OBJ *next;
}OBJ_T;