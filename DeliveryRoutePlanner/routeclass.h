#pragma once
#include <iostream>
#include "fileClass.h"
#include <vector>



class routeclass
{
private:
	unsigned int a, b, c, d, e ,i, lowest, lowestX, lowestY, last, indexofX, indexofY, indexofSteps, row, col, distanceX, distanceY, ind, totalSteps;
	std::vector<std::vector<char>> v1;
	std::vector<char> v2;
	std::vector<int>::iterator itr;
	std::vector<int> Steps;

public:
	void sortingBrute(fileClass file);
	void sortingNearest(fileClass file);
	void bruteForce(fileClass file);
	void nearestNeighbor(fileClass file);
	void create2Dpath();
	void create2D();
	void display2D();
	void display2Dlabels();
	void answer();
	void returnValues(fileClass file);
	std::vector<char> sVecLabels; // Sorted vector for labels
	std::vector<int> sVecX; // Sorted vector for X
	std::vector<int> sVecY; // Sorted vector for Y
	std::vector<char> bVecLabels; // Brute force vector
	std::vector<int> bVecX; // Brute force vector
	std::vector<int> bVecY; // Brute force vector
	

};
