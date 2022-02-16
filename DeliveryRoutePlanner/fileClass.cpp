#include "fileClass.h"
#include "routeclass.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void fileClass::readfile()
{
	std::ifstream fileInputStream;
	if (fileName == "Random" or fileName == "Random.txt" or fileName == "random" or fileName == "random.txt") {
		std::cout << "How many nodes do you want?";
		std::cin >> userNodes;
		fileName = "Random.txt";
		randomfile();
	}

	fileInputStream.open(fileName); // hardcoded filename, for now...
	if (fileInputStream.good())
	{
		

		std::getline(fileInputStream, readLine); // read first line
		while (!fileInputStream.fail()) // check for failbit
		{
			//after reading each line, lets split on commas to get the node label, x, and y values for each node:
			std::stringstream ss(readLine);

			std::getline(ss, token1, ','); // read first token
			std::stringstream ss1(token1);
			ss1 >> nodeLabel;
			vectorNodeLabel.push_back(nodeLabel);

			std::getline(ss, token2, ','); // read second token
			std::stringstream ss2(token2);
			ss2 >> x;
			vectorX.push_back(x);


			std::getline(ss, token3, ','); // read third token
			std::stringstream ss3(token3);
			ss3 >> y;
			vectorY.push_back(y);

			std::cout << "node " << vectorNodeLabel[numOfNode] << " is at: (" << vectorX[numOfNode] << ", " << vectorY[numOfNode] << ")" << std::endl;
			numOfNode++;
			getline(fileInputStream, readLine); // read next lines...
		}

		std::cout << std::endl;

		if (fileInputStream.eof()) {
			std::cout << "File " << fileName << " read successfully..." << std::endl;
			std::cout << "There are " << vectorNodeLabel.size() << " file nodes, X, Y values are within valid ranges" << std::endl;
		}
		else {
			std::cout << "Error in file file." << std::endl;
		}
	}
	else
	{
		std::cout << "Error opening file file, ";
		std::cout << "check 'bargraph1.txt' exists in correct directory." << std::endl;
	}
	
	std::cout << std::endl;
	fileInputStream.close();
}

void fileClass::writefile()
{
	std::ofstream fileOutputStream;


	fileOutputStream.open(savedFileName);
	if (fileOutputStream.good()) {
		for (int a = 0; unsigned(a) < vectorNodeLabel.size(); a++) {
			fileOutputStream << vectorNodeLabel[a] << " (" << vectorX[a] << ", " << vectorY[a] <<")" << std::endl;
		}
	}
}


void fileClass::randomfile()
{
	std::ofstream outputFileStream;
	outputFileStream.open("Random.txt");

	srand(unsigned(time(NULL)));
	
	while (i < userNodes) {
		x = rand() % 48 + 1;
		y = rand() % 28 + 1;
		outputFileStream << letter << ", ";
		outputFileStream << x << ", ";
		outputFileStream << y << std::endl;
		letter++;
		i++;
	}

}
