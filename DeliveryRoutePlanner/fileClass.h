#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>



class fileClass
{
private:

	std::string readLine, token1, token2, token3;
	char nodeLabel, letter = 'A';
	int x, y, i, userNodes;

public:
	int numOfNode;
	void readfile();
	void randomfile();
	void writefile();
	std::string fileName;
	std::vector<char> vectorNodeLabel;
	std::vector<int> vectorX;
	std::vector<int> vectorY;
	std::string savedFileName;
};