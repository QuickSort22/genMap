#include "genMap.h"


int** genMap::upScale(int** ARR, int size, float scale)
{
	int rad = scale;
	int NSize = size * scale;
	int dx[] = {0,0,1,1, 1, 0,-1,-1,1};
	int dy[] = {0,1,1,0,-1,-1,-1, 0,-1};

	int** arr = new int* [NSize];
	for (int i = 0; i < NSize; i++)
		arr[i] = new int [NSize];
	for (int i = 0; i < NSize; i++)
		for (int j = 0; j < NSize; j++)
		{
			int R = 4;
			int elem = 9*R;
			int sum = 0;
			for(int r=0;r<=R;r++)
			for (int k = bool(r); k < 9; k++)
			{ 
				
				int ni=(i+dy[k]*r)/scale;
				int nj =(j+dx[k]*r)/scale;

				if (ni<0 || ni>=size) { elem--; continue; }
				if (nj<0 || nj>=size) { elem--; continue; }
				sum +=ARR[ni][nj];
			}
			arr[i][j] = sum / elem;
		}
	//delete[] ARR;
	return arr;
}

int** genMap::getPerlinNoise()
{
	srand(seed);
	int** perlin = new int* [finalSize];
	for (int i = 0; i < finalSize; i++)
		perlin[i] = new int[finalSize];
	for (int i = 0; i < finalSize; i++)
	{
		for (int j = 0; j < finalSize; j++)
			perlin[i][j]=0;
	}


	for (int k = 2; k <= step; k++)
	{
		int noiseSize = finalSize / pow(2, k);
		int** arr = genNoise(noiseSize);
		print(arr,noiseSize);
		arr =upScale(arr, noiseSize, finalSize / noiseSize);
		print(arr, finalSize);
		for (int i = 0; i < finalSize; i++)
		{
			for (int j = 0; j < finalSize; j++)
			{
				perlin[i][j] += arr[i][j];
			}
		}
		//delete[]arr;
	}
	for (int i = 0; i < finalSize; i++)
	{
		for (int j = 0; j < finalSize; j++)
		{
			perlin[i][j]/= step;
		}
	}

	return perlin;
}

void genMap::setFinalSize(int size)
{
	finalSize = size;
}

int** genMap::genNoise(int size)
{
	int** arr = new int* [size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = rand() % 256;
	return arr;
}

void genMap::print(int** arr, int size)
{

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int r = arr[i][j];
			char pr;
			if (r > 128)
				pr = '@';

			else
				pr = ' ';

			std::cout << pr << ' ';
		}
		std::cout << std::endl;

	}
	std::cout << "====================\n";

}

void genMap::setSeed(int nSeed)
{
	seed = nSeed;
}

int** genMap::orNoise(int** arr1, int** arr2, int size)
{

	int** arr = new int* [size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (abs(arr1[i][j] - arr2[i][j]) < 26)
				arr[i][j] = (arr1[i][j] + arr2[i][j]) / 2;
		}
	}
	return arr;

}
