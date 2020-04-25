#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <iomanip>
#include "FileIO.h"
struct Product
{
	std::string Name;
	double Price = 0.00;
	std::string Desc;
	Product* Next = NULL;
};

struct Inventory //What we're calling this single linked list
{
	Product* First = NULL;
	int Size = 0;
};
double GetPriceFromUser();
Inventory* FillInventoryFromFile(std::string filename);
void AddProductToInventory(Inventory* inventory, std::string filename);
void DisplayProductsInInventory(Inventory* inventory);
#endif // !INVENTORY_H
