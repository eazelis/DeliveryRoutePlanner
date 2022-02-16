#include "routeclass.h"
#include "fileClass.h"
#include <vector>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> // 



void routeclass::bruteForce(fileClass file)
{
	std::cout << "Processing brute-force route..." << std::endl;
	sortingBrute(file);
}

void routeclass::nearestNeighbor(fileClass file)
{
	std::cout << "Processing nearest neighbor route..." << std::endl;
	sortingNearest(file);
}



void routeclass::create2D()
{

	row = 50; col = 30;
	// Creating 2D vertor 
	for (int a = 0; unsigned(a) < row; a++) {
		v2.push_back(' ');
	}
	for (int b = 0; unsigned(b) < col; b++) {
		v1.push_back(v2);
	}
	// Upgrading dispay vector for userinterface
	for (unsigned int c = 0; c < v2.size(); c++) {
		v1[0][c] = '-';
		v1[col - 1][c] = '-';
	}
	for (unsigned int d = 0; d < v1.size(); d++) {
		v1[d][0] = '|';
		v1[d][row - 1] = '|';
	}
	v1[0][0] = '+';
	v1[col-1][0] = '+';
	v1[0][row-1] = '+';
	v1[col-1][row-1] = '+';

	std::cout << std::endl;
	create2Dpath();
	
}

void routeclass::create2Dpath()
{
	for (a = 0; a < sVecLabels.size() - 1; a++) { // Repeat patch until its finished
		distanceX = abs(sVecX[a + 1] - sVecX[a]); // abs() function always return positive integer
		distanceY = abs(sVecY[a + 1] - sVecY[a]);
		totalSteps = totalSteps + distanceX + distanceY;

		distanceX = abs(sVecX[a + 1] - sVecX[a]); // abs() function always return positive integer
		distanceY = abs(sVecY[a + 1] - sVecY[a]);

		for (b = 0; b < distanceX; b++) { // Drawing X path

			if (sVecX[a] > sVecX[a + 1]) {
				v1[sVecY[a]][sVecX[a] - b - 1] = 'x';
			}
			else {
				v1[sVecY[a]][sVecX[a] + b + 1] = 'x';
			}



		}
		for (c = 0; c < distanceY; c++) { // Drawing Y path
			if (sVecY[a] > sVecY[a + 1]) {
				v1[sVecY[a] - c][sVecX[a + 1]] = 'x';
			}
			else {
				v1[sVecY[a] + c][sVecX[a + 1]] = 'x';
			}

		}

	}
	display2D();
}


void routeclass::display2D()
{
	std::cout << "ASCII art plot showing the route the delivery driver takes:";
	display2Dlabels();
	std::cout << std::endl;
	for (int i = 0; unsigned(i) < v1.size(); i++) {

		for (int a = 0; unsigned(a) < v2.size(); a++) {
			std::cout << v1[i][a] << " ";
		}
		std::cout << std::endl;
	}
	std::cout <<"This route takes " << totalSteps << " total steps." <<std::endl;
}

void routeclass::display2Dlabels() // Showing coordinates labels on coor
{
	for (int e = 0; unsigned(e) < sVecLabels.size(); e++) {
		v1[sVecY[e]][sVecX[e]] = sVecLabels[e];
	}
}



void routeclass::sortingBrute(fileClass file) // NEARES NEIGHBOOR NOT WITH X BUT ALSO WITH Y, FIX IT!!!!!!!!!!!!!!!!!!!!!!!!  Route3.txt
{
		lowest = *min_element(file.vectorX.begin(), file.vectorX.end());// lowest value
		
		itr = find(file.vectorX.begin(), file.vectorX.end(), lowest);
		indexofX = std::distance(file.vectorX.begin(), itr);


		sVecLabels.push_back(file.vectorNodeLabel[indexofX]);
		sVecX.push_back(file.vectorX[indexofX]);
		sVecY.push_back(file.vectorY[indexofX]);
		
		file.vectorX[indexofX] = 100;
		file.vectorY[indexofX] = 100;


		for (int a = 0; unsigned(a) < file.vectorNodeLabel.size()-1; a++) {
			lowestX = *min_element(file.vectorX.begin(), file.vectorX.end());
			itr = find(file.vectorX.begin(), file.vectorX.end(), lowestX);
			indexofX = std::distance(file.vectorX.begin(), itr);

			lowestY = *min_element(file.vectorY.begin(), file.vectorY.end());// lowest value
			itr = find(file.vectorY.begin(), file.vectorY.end(), lowestY);
			indexofY = std::distance(file.vectorY.begin(), itr);

			if (file.vectorX[indexofX] - sVecX[a] < file.vectorX[indexofY] - sVecX[a]) {
				sVecLabels.push_back(file.vectorNodeLabel[indexofX]);
				sVecX.push_back(file.vectorX[indexofX]);
				sVecY.push_back(file.vectorY[indexofX]);
				file.vectorX[indexofX] = 100;
				file.vectorY[indexofX] = 100;
			}
			else {
				sVecLabels.push_back(file.vectorNodeLabel[indexofY]);
				sVecX.push_back(file.vectorX[indexofY]);
				sVecY.push_back(file.vectorY[indexofY]);
				file.vectorX[indexofY] = 100;
				file.vectorY[indexofY] = 100;
			}


		}

		


		answer();
		create2D();
}

void routeclass::sortingNearest(fileClass file)
{

	lowest = *min_element(file.vectorX.begin(), file.vectorX.end());// lowest value

	itr = find(file.vectorX.begin(), file.vectorX.end(), lowest);
	indexofX = std::distance(file.vectorX.begin(), itr);


	sVecLabels.push_back(file.vectorNodeLabel[indexofX]);
	sVecX.push_back(file.vectorX[indexofX]);
	sVecY.push_back(file.vectorY[indexofX]);

	file.vectorX[indexofX] = 100;
	file.vectorY[indexofX] = 100;
	for (int b = 0; b < file.numOfNode -1; b++) {

		for (int a = 0; a < file.numOfNode; a++) {
			distanceX = abs(sVecX[b] - file.vectorX[a]);
			distanceY = abs(sVecY[b] - file.vectorY[a]);
			Steps.push_back(distanceX + distanceY);

		}

		lowest = *min_element(Steps.begin(), Steps.end());// lowest value

		itr = find(Steps.begin(), Steps.end(), lowest);
		indexofSteps = std::distance(Steps.begin(), itr);
		Steps.clear();
		sVecLabels.push_back(file.vectorNodeLabel[indexofSteps]);
		sVecX.push_back(file.vectorX[indexofSteps]);
		sVecY.push_back(file.vectorY[indexofSteps]);

		file.vectorX[indexofSteps] = 100;
		file.vectorY[indexofSteps] = 100;

	}
	std::cout << std::endl;
	answer();
	create2D();
	
}

void routeclass::answer()
{
	std::cout << std::endl; // Priting answer
	std::cout << "Answer: The route planner suggest the following short(est) route:" << std::endl;
	for (int b = 0; unsigned(b) < sVecLabels.size(); b++) {
		std::cout << sVecLabels[b] << "(";
		std::cout << sVecX[b] << ", ";
		std::cout << sVecY[b] << "); ";
	}
	std::cout << std::endl;

}

void routeclass::returnValues(fileClass file)
{
	file.vectorNodeLabel.clear();
	file.vectorX.clear();
	file.vectorY.clear();
	for (int b = 0; unsigned(b) < sVecLabels.size(); b++) {
		file.vectorNodeLabel.push_back(sVecLabels[b]);
		file.vectorX.push_back(sVecX[b]);
		file.vectorY.push_back(sVecY[b]);
	}
}
