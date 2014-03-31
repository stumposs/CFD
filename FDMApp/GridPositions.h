#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>

const float xMin = -100;
const float xMax = 100;
const float zMin = -100;
const float zMax = 100;
const float yMin = -100;
const float yMax = 100;
const float yBound = 0;


class GridPositions
{
public:
	GridPositions(void);
	~GridPositions(void);
	void GenerateGrid();
	
private:
	int _N;
};
