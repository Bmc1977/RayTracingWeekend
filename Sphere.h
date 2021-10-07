#pragma once

#ifndef SPHEREH
#define SPHEREH

#include "Hitable.h"

class sphere : public hitable
{
public:
	sphere() {}
	sphere(vec3 cen, double r) : center(cen), radius(r) {};
	virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const;
	vec3 center;
	double radius;
};


/*
 * Whether or not a ray will hit a circle can be represented by a quadriatic equation.
 * Roots: 0 -> Doesn't hit 1 -> Hits the very edge 2 -> Hits within the circle (and theoretically the back).
 * Uses the quadriatic formula.
 */
bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const
{
	vec3 oc = r.origin() - center;
	double a = dot(r.direction(), r.direction());
	double b = dot(oc, r.direction());
	double c = dot(oc, oc) - radius * radius;
	double discriminant = b * b - a * c;
	if (discriminant > 0)
	{
		double temp = (-b - sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	return false;
}

#endif