#pragma once
#include <vector>
#include<cmath>
#include <iostream>
class genMap
{
	int finalSize=1024;
	int step =4;
	int seed=15215252131;

	void print(int** arr, int size);
public:
	void setSeed(int nSeed);
	int** orNoise(int** arr1,int**arr2,int size);
	int** upScale(int** ARR, int size, float scale);
	int** getPerlinNoise();
	int getFinalSize();
	void setFinalSize(int size);
	int** genNoise(int size);



};

