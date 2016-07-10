/*
 * Yingzhu Zhang, CS 312
 * Assignment 6
 * Vector.cpp
 */

#include "Vector.hpp"
#include <cmath>

Vector::Vector (double x, double y, double z) {
	set(x, y, z);
}
void Vector::set (double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector::normalize (void) {
	double my_length = this->length();
    x = x / my_length;
    y = y / my_length;
    z = z / my_length;
 }

double Vector::dot (Vector v) {
	double dp = x * v.x + y * v.y + z * v.z;
	return dp;
}

Vector Vector::add (Vector v) {
	Vector rv;
	rv.x = x + v.x;
	rv.y = y + v.y;
	rv.z = z + v.z;
	return rv;
}

Vector Vector::subtract (Vector v) {
	Vector rv;
	rv.x = x - v.x;
	rv.y = y - v.y;
	rv.z = z - v.z;
	return rv;
}

Vector Vector::mult (Vector v) {
	Vector rv;
	rv.x = x * v.x;
	rv.y = y * v.y;
	rv.z = z * v.z;
	return rv;
}

Vector Vector::scalar_mult (double scalar) {
    Vector rv;
    rv.x = x * scalar;
	rv.y = y * scalar;
	rv.z = z * scalar;
	return rv;
}

Vector Vector::scalar_divide (double scalar) {
    Vector rv;
    rv.x = x / scalar;
	rv.y = y / scalar;
	rv.z = z / scalar;
	return rv;
}

Vector Vector::operator+ (Vector v) {
	return this->add(v);
}

Vector Vector::operator- (Vector v) {
	return this->subtract(v);
}

Vector Vector::operator* (Vector v){
	return this->mult(v);
}

Vector Vector::operator* (double scale){
	return this->scalar_mult(scale);
}

Vector Vector::operator/ (double scale){
	return this->scalar_divide(scale);
}
 	
double Vector::sum_components (void){
    return x + y + z;
}

double Vector::length (void){
    double length = sqrt(pow(x,2) + pow(y,2) + pow(z, 2));
    return length;
}



