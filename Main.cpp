#include <fstream>

#include "Vec3.h"



int main()
{
	int nx = 400;
	int ny = 200;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n" << nx << " " << ny << "\n255\n";

	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			vec3 col(double(i) / double(nx), double(j) / double(ny), 0.2);

			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);

			file << ir << " " << " " << ig << " " << ib << std::endl;
		}
	}


	file.close();
	return 0;
}