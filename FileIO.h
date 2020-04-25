#pragma once
#ifndef FILEIO_H
#define FILEIO_H
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <string>
std::ifstream OpenFileToRead(std::string filename);
std::ofstream OpenFileToAppend(std::string filename);
std::ofstream OpenFileToOverwrite(std::string filename);
bool DoesFileExist(std::string filename);
int CountFileLines(std::string filename);
#endif // !FILEIO_H
