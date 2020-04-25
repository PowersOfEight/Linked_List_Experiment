#include "FileIO.h"

std::ifstream OpenFileToRead(std::string filename)
{
	std::ifstream InputFromFile;
	InputFromFile.open(filename);
	return InputFromFile;
}

std::ofstream OpenFileToAppend(std::string filename)
{
	std::ofstream OutputToFile;
	OutputToFile.open(filename, std::ios::app);
	return OutputToFile;
}

std::ofstream OpenFileToOverwrite(std::string filename)
{
	std::ofstream OutputToFile;
	OutputToFile.open(filename, std::ios::trunc);
	return OutputToFile;
}

bool DoesFileExist(std::string filename)
{
	std::ifstream InputFromFile = OpenFileToRead(filename);
	bool thisExists = true;
	if (InputFromFile)
	{
		thisExists = true;
	}
	else if (!InputFromFile)
	{
		thisExists = false;
	}
	InputFromFile.close();
	return thisExists;
}

int CountFileLines(std::string filename)
{
	std::string lines;
	int numberOfLines = 0;
	if (DoesFileExist(filename))
	{
		std::ifstream InputFromFile = OpenFileToRead(filename);
		while (!InputFromFile.eof())
		{
			getline(InputFromFile, lines);
			if (!InputFromFile.eof())
			{
				numberOfLines++;
			}
		}
		InputFromFile.close();
	}
	return numberOfLines;
}

