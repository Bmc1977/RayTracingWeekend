#include <fstream>
#include "Vec3.h"
#include "Ray.h"
#include "Sphere.h"
#include "Hitablelist.h"
#include "Camera.h"
#include <float.h>

vec3 color(const ray& r, hitable *world)
{
	hit_record rec;

	if (world->hit(r, 0.0, FLT_MAX, rec))
	{
		return 0.5 * vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
	}
	else
	{
		vec3 unit_direction = unit_vector(r.direction());
		double t = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	}
}

double random_number()
{
	return ((double)rand() / (double)RAND_MAX);
}



int main()
{
	std::cout << random_number() << std::endl;
	std::cout << random_number() << std::endl;
	std::cout << random_number() << std::endl;
	srand((unsigned)time(NULL));
	int nx = 800;
	int ny = 400;
	int ns = 400;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n" << nx << " " << ny << "\n255\n";

	hitable* list[2];

	list[0] = new sphere(vec3(0, 0, -1), 0.5);
	list[1] = new sphere(vec3(0, -100.5, -1), 100);
	hitable* world = new hitable_list(list, 2);

	camera cam;

	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			vec3 col(0, 0, 0);
			for (int s = 0; s < ns; s++)
			{
				double u = double(i + random_number()) / double(nx);
				double v = double(j + random_number()) / double(ny);

				ray r = cam.get_ray(u , v);
				vec3 p = r.point_at_parameter(2.0);
				col += color(r, world);
			}
			col /= double(ns);

			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);

			file << ir << " " << " " << ig << " " << ib << std::endl;
		}
	}


	file.close();
	return 0;
}