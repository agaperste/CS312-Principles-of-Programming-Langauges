/*
 * Yingzhu Zhang, CS 312
 * Assignment 6
 * HEADER FILE FOR Vector.cpp
 */

 #ifndef VECTOR_HPP
 #define VECTOR_HPP

 class Vector
 {
 private:
 	double x;
 	double y;
 	double z;
 public:
    Vector (void) {};
 	Vector (double x, double y, double z);
 	void set(double x, double y, double z);
     
 	void normalize (void);
 	double dot (Vector v);
     
 	Vector add (Vector v);
    Vector subtract (Vector v);
    Vector mult (Vector v);
    Vector scalar_mult (double scalar);
    Vector scalar_divide (double scalar);

 	Vector operator+ (Vector v);
 	Vector operator- (Vector v);
 	Vector operator* (Vector v);
    Vector operator* (double scale);
    Vector operator/ (double scale);
     
 	double sum_components (void);
 	double length (void);
 };

#endif