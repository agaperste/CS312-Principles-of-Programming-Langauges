/*
 * Yingzhu Zhang, CS 312
 * Assignment 5
 * Initializes image file; loops through pixels; sets ray; prints pixels; frees list
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vec.h"
#include "rc.h"

void read_objs (OBJ_T **list){
	double in1, in2, in3, in4, in5, in6, in7;
	OBJ_T *new;
	*list = NULL;
	while (scanf("%lf%lf%lf%lf%lf%lf%lf",&in1, &in2, &in3, &in4, &in5, &in6, &in7)== 7){
		new = (OBJ_T *)(malloc(sizeof (OBJ_T)));
		new->sph.ctr.x = in1;
		new->sph.ctr.y = in2;
		new->sph.ctr.z = in3;
		new->sph.radius = in4;
		new->clr.R = in5;
		new->clr.G = in6;
		new->clr.B = in7;
		new->next = *list;
		*list = new;
	}
}

int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t){
	double A = 1;
	double B = 2 * (ray.dir.x * (ray.orig.x - sphere.ctr.x) +
					ray.dir.y * (ray.orig.y - sphere.ctr.y) +
					ray.dir.z * (ray.orig.z - sphere.ctr.z));
	double C = pow((ray.orig.x - sphere.ctr.x), 2) + 
			   pow((ray.orig.y - sphere.ctr.y), 2) + 
			   pow((ray.orig.z - sphere.ctr.z), 2) - pow(sphere.radius, 2);
	double discriminant = pow(B, 2) - 4*A*C;
	if (discriminant <= 0) {
		return 0;
	}
	else {
		double t0 = (-B + sqrt(discriminant))/(2*A);
		double t1 = (-B - sqrt(discriminant))/(2*A);	
		if ((t0 <= 0) || (t1 <= 0)) {
			return 0;
		}
		else {
			double t = fmin(t0, t1);
			// if (t > 0) {
				return 1;
			// }
		}
	}				
}

COLOR_T cast (RAY_T ray, OBJ_T *list) {
	OBJ_T *curr;
	double min_T = 1000;
	double t;
	COLOR_T my_color;
	// set default pixel to white
	my_color.R = 1;
	my_color.G = 1;
	my_color.B = 1;
	for (curr = list; curr != NULL; curr=curr->next){
		if (intersect_sphere(ray, curr->sph, &t)){
			if (t<min_T){
				my_color = curr->clr;
				min_T = t;
			}
		}
	}
	return my_color;
}


int main (int argc, char *argv[]){
	printf("P6\n 1000 1000\n 255\n");
	OBJ_T *my_list;
	read_objs(&my_list);
	double y, x;
	for (y = 0; y < 1000; y++) {
		for (x = 0; x < 1000; x++){
			// set ray
			RAY_T my_ray;
			my_ray.orig.x = 0;
			my_ray.orig.y = 0;
			my_ray.orig.z = 0;
			my_ray.dir.x = -0.5 + x * (1/1000.0);
			my_ray.dir.y = 0.5 - y/1000.0;
			my_ray.dir.z = 1;
			// normalize ray dir
			my_ray.dir = normalize(my_ray.dir);
			COLOR_T my_pixel;
			my_pixel = cast(my_ray, my_list);
			// if (intersect_sphere(my_ray, my_sphere, *my_list)) {
			// 	my_pixel.R = 1;
			// 	my_pixel.G = 0;
			// 	my_pixel.B = 0;
			// }

			// write pixel -printf
			printf("%c%c%c", (unsigned char) (my_pixel.R*255), 
								 (unsigned char) (my_pixel.G*255),
								 (unsigned char) (my_pixel.B*255));
		}
	}
	free(my_list);

	return 0;
}

