#pragma once

#ifndef RAYH
#define RAYH

#include "Vec3.h"

/*
 * A can be defined by the equation p(t) = A + t * B
 * Where A is the origin and B is the direction.
 * t is then used to determine what direction and at what scale the ray is pointing.
 * If t is positive the ray can only move forward reletive to the origin.
 */

class ray
{
public:
	ray() {}
	ray(const vec3& a, const vec3& b) { A = a; B = b; }
	vec3 origin() const { return A;}
	vec3 direction() const { return B; }

	//This function returns the result of the base ray function.
	vec3 point_at_parameter(double t) const { return A + t * B;  }

	vec3 A;
	vec3 B;
};

#endif