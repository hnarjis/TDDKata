#include "StringCalculatorClass.h"
#include <stdlib.h>
#include <sstream>

int StringCalculatorClass::add(std::string newString) {
	int sum = 0;
	std::stringstream stringStream;
	stringStream.str(newString);
	std::string line;

	char delimiter = ',';
	if (newString[0] == '/' && newString[1] == '/')
	{
		delimiter = newString[2];
		std::getline(stringStream,line);
	}

	bool hasNegatives = false;
	std::string negatives = "negatives not allowed";
	while (!stringStream.eof())
	{
		std::getline(stringStream,line);
		std::stringstream lineStream;
		lineStream.str(line);
		while(!lineStream.eof())
		{
			std::string numberString;
			std::getline(lineStream,numberString,delimiter);
			int number = atoi(numberString.c_str());

			if (number < 0)
			{
				hasNegatives = true;
				negatives.append(" ");
				negatives.append(numberString);
			}
			sum += number;
		}
	}
	if (hasNegatives)
		throw negatives;
	return sum;
}
