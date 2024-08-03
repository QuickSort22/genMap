#include<iostream>
#include"genMap.h"
#include<ctime>

void print(int** arr, int size)
{

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int r = arr[i][j];
			char pr;
			if (r > 80)
				pr = '@';

			else
				pr = ' ';

			std::cout << pr << ' ';
		}
		std::cout << std::endl;

	}
	std::cout << "====================\n";

}
int main()
{
	system("pause");
	int size = 256;
	genMap gen;
	gen.setFinalSize(size);
	int**perlin1 = gen.getPerlinNoise();
	gen.setSeed(1522156235);
	int** perlin2 = gen.getPerlinNoise();

	int** perlin = gen.orNoise(perlin2,perlin1,size);


	std::cout << "\n\n\n\n";
	print(perlin1, size);
	std::cout << "\n\n\n\n";
	print(perlin2, size);
	std::cout << "\n\n\n\n";
	print(perlin, size);


	
}