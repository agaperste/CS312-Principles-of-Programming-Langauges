/*
 * Yingzhu Zhang, CS 312
 * Assignment 6
 * rt.hpp
 */
#include <iostream>
#include <cmath>
#include "Vector.hpp"
#include "rt.hpp"
#include "Light.hpp"
#include "obj.hpp"

void read_objs (OBJ_T **list) {
    OBJ_T *node;
    *list = NULL;
	double cx, cy, cz, r, lr, lg, lb;
	while (std::cin >>cx>>cy>>cz>>r>>lr>>lg>>lb){
		node = new OBJ_T;
        
        Vector ctr(cx, cy, cz);
        node->sph.set(ctr, r);
        
        node->clr.R = lr;
        node->clr.G = lg;
        node->clr.B = lb;
        
		node->next = *list;
		*list = node;
	}
}

COLOR_T trace (RAY_T ray, OBJ_T *list, Light light) {
	double min_T = 1000;
	double t;
	Vector int_pt, normal, closest_int_pt, closest_normal;
	COLOR_T my_color;
	// set default pixel to white
	my_color.R = 0.0;
	my_color.G = 0.0;
	my_color.B = 0.0;
    
    OBJ_T *closest_obj = NULL;
    for (OBJ_T *obj = list; obj != NULL; obj = obj->next) {
        if (obj->sph.intersect_sphere(ray, t, int_pt, normal)) {
        	if (t < min_T) {
                min_T = t;
	            closest_obj = obj;
	            closest_int_pt = int_pt;
	            closest_normal = normal;
	        }
        }
    }
    if (closest_obj != NULL) {
        my_color = light.illuminate(ray, closest_obj->clr, closest_int_pt, closest_normal);
    }
	
	return my_color;
}

int main(int argc, char const *argv[])
{
    Light my_light(5.0, 10.0, 0.0);
	std::cout<<"P6\n 1000 1000\n 255\n";
    
	OBJ_T *my_list;
	read_objs(&my_list);

	int y, x;
	for (y = 0; y < 1000; y++) {
		for (x = 0; x < 1000; x++){
            
			// set ray
			RAY_T my_ray;
			my_ray.orig.set(0,0,0);
			my_ray.dir.set(-0.5 + x/1000.0, 0.5 - y/1000.0, 1);
            
			// normalize ray dir
			my_ray.dir.normalize();
            
			COLOR_T my_pixel;
			my_pixel = trace(my_ray, my_list, my_light);
            
            //keep color at 1.0 before cout
            if (my_pixel.R > 1.0){
                my_pixel.R = 1.0;
            }
            if (my_pixel.G > 1.0){
                my_pixel.G = 1.0;
            }
            if (my_pixel.B > 1.0){
                my_pixel.B = 1.0;
            }

			// write pixel -cout
			std::cout<<(unsigned char) (my_pixel.R * 255) << (unsigned char) (my_pixel.G * 255) << (unsigned char) (my_pixel.B * 255);
		}
	}

	delete(my_list);
	return -1;
}


