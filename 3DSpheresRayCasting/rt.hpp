/*
 * Yingzhu Zhang, CS 312
 * Assignment 5
 * HEADER FILE FOR rt.cpp
 */

#include "Vector.hpp"

#ifndef rt_hpp
#define rt_hpp

typedef struct{
	Vector orig;
	Vector dir;
}RAY_T;

typedef struct{
	double R;
	double G;
	double B;
}COLOR_T;

#endif