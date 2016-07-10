/*
 * Yingzhu Zhang, CS 312
 * Assignment 5
 * Vector portion of A5
 */

#include <stdio.h>
#include <stdlib.h>
#include "vec.h"
#include <math.h>

VEC_T normalize (VEC_T v) {
	double length = sqrt(pow((v.x),2) + pow((v.y),2) + pow((v.z),2));
	double norm_x = (v.x)/length;
	double norm_y = (v.y)/length;
	double norm_z = (v.z)/length;
	v.x = norm_x;
	v.y = norm_y;
	v.z = norm_z;
	return v;
 }

// double dot (VEC_T v1, VEC_T v2) {
// 	double dp;
// 	dp = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
// 	return dp;
// }