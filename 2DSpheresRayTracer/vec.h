/*
 * Yingzhu Zhang, CS 312
 * Assignment 5
 * HEADER FILE FOR vec.c
 */

 #ifndef VEC_H
 #define VEC_H
 typedef struct{
 	double x;
 	double y;
 	double z;
 }VEC_T;

// fn prototype
VEC_T normalize (VEC_T v);
// double dot(VEC_T v1, VEC_T v2);

#endif