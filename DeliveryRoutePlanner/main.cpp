// DeliveryRoutePlanner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//  This file is given as a starting point to help you with your coursework :).
//  You will want to split this single file into multiple classes, objects and methods fairly early on.
//  Author:  azelise
//     SID:  10522657

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "fileClass.h"
#include "routeclass.h"



int main()
{
	char choosenMethod, runAgain;
	fileClass file;
	routeclass routing;
	std::cout << "Delivery Route Planner Problem Program Title!" << std::endl;
	std::cout << "Author:  azelise" << std::endl;
	std::cout << "SID:  10522657" << std::endl << std::endl;
	std::cout << "Please choose to enter a filename to read from a text file file, or to type Random to randomly generate node data." << std::endl;

	std::cin >> file.fileName;
	//file.fileName = "Route1.txt";
	file.readfile();
	std::cout << "Would you like to brute-force (b) or nearest-neighbour (n) solution?" << std::endl;
	std::cout << "Please enter 'b' or 'n'?" << std::endl;

	std::cin >> choosenMethod;
	//choosenMethod = 'n';

	if (choosenMethod == 'b' or choosenMethod == 'n') { 
		switch (choosenMethod) {
		case 'b':
			routing.bruteForce(file);
		case 'n':
			routing.nearestNeighbor(file);
		}
	}
	else { std::cout << "Sorry, but you choose non-existent solution" << std::endl; }

	std::cout << std::endl;
	std::cout << "Please enter a filename to save to text file or enter 'n' to not save:" << std::endl;
	std::cin >> file.savedFileName;
	if (file.savedFileName == "n" or file.savedFileName == "N") {
		std::cout << "File wasnt saved" << std::endl;
	}
	else { 
		routing.returnValues(file);
		file.writefile();
		std::cout << "The route has been saved as " << file.savedFileName << std::endl; 
	}
	
	std::cout << "Please enter 'Y' or 'y' to run again:" << std::endl;

	std::cin >> runAgain;
	if (runAgain == 'y' or runAgain == 'Y') {
		std::cout << std::endl;
		main();
	}

	return 0;
}