#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

double calcDistance(double x1, double y1, double x2, double y2)
{
	double result;

	double xSqr = std::pow((x2 - x1), 2.0);
	double ySqr = std::pow((y2 - y1), 2.0);
	result = std::sqrt(xSqr + ySqr);

	return result;
}

int main()
{
	std::string line;
	std::vector<std::vector<std::string>>data;
	while (getline(std::cin, line))
	{
		if (line == "exit")
		{
			break;
		}
		std::vector<std::string> row;

		std::stringstream read(line);
		string word;
		while (getline(read, word, ' '))
		{
			row.push_back(word);
		}
		data.push_back(row);
		//std::cout << line << std::endl;

	}
	std::cout << "=========================================" << std::endl;

	//std::cout << data[0][0] << std::endl;
	double xCat = std::stod(data[0][0]);
	std::cout << "xCat: " << xCat << std::endl;

	//std::cout << data[0][1] << std::endl;
	double yCat = std::stod(data[0][1]);
	std::cout << "yCat: " << yCat << std::endl;

	//std::cout << data[0][2] << std::endl;
	double vCat = std::stod(data[0][2]);
	std::cout << "vCat: " << vCat << std::endl;

	//std::cout << data[1][0] << std::endl;
	double xTree = std::stod(data[1][0]);
	std::cout << "xTree: " << xTree << std::endl;

	//std::cout << data[1][1] << std::endl;
	double yTree = std::stod(data[1][1]);
	std::cout << "yTree: " << yTree << std::endl;

	//std::cout << data[2][0] << std::endl;
	double numDogs = std::stod(data[2][0]);
	std::cout << "numDogs: " << numDogs << std::endl;


	double catDist = calcDistance(xCat, yCat, xTree, yTree);
	double catTime = catDist / vCat;

	std::cout << "catDist: " << catDist << std::endl;
	std::cout << "catTime: " << catTime << std::endl;

	std::cout << "\n=========================================" << std::endl;
	bool catFlag = true;
	std::string catSafe;

	for (int i = 3; i < data.size(); i++)
	{
		//std::cout << data[0][0] << std::endl;
		double xDog = std::stod(data[i][0]);
		std::cout << "xDog: " << xDog << std::endl;

		//std::cout << data[0][1] << std::endl;
		double yDog = std::stod(data[i][1]);
		std::cout << "yDog: " << yDog << std::endl;

		//std::cout << data[0][2] << std::endl;
		double vDog = std::stod(data[i][2]);
		std::cout << "vDog: " << vDog << std::endl;
		
		double dogDist = calcDistance(xDog, yDog, xTree, yTree);
		double dogTime = dogDist / vDog;

		std::cout << "dogDist: " << dogDist << std::endl;
		std::cout << "dogTime: " << dogTime << std::endl;

		if (dogTime < catTime)
		{
			catFlag = false;
		}
	}

	if (catFlag == false)
	{
		catSafe = "Captured";
	}
	else
	{
		catSafe = "Escaped";
	}

	std::cout << "Status of the cat: " << catSafe << std::endl;
	return 0;
}
