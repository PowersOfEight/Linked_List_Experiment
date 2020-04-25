#include "Inventory.h"
double GetPriceFromUser()
{
	double x = 0.00;
	while (!(std::cin >> x))
	{
		std::cout << "[ERROR] - Please enter a number for price: $";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (x <= 0.00)
	{
		std::cout << "[ERROR] - This is not free, and we certainly won't pay you to take it off our hands" << std::endl;
		std::cout << "Please enter a number for price that is not zero or negative: $";
		return GetPriceFromUser();
	}
	return x;
}
Inventory* FillInventoryFromFile(std::string filename)
{
	Inventory* inventory = new Inventory;
	std::string garbageLine;//To getline in order to get to the end of file
	inventory->Size = 0;
	inventory->First = NULL;
	int numberOfLines = CountFileLines(filename);
	int linesModulo = (numberOfLines % 3);
	if (numberOfLines > 0 && linesModulo == 0)
	{
		Product* currentProduct = inventory->First;
		int loopCounter = numberOfLines;
		std::ifstream InputFromFile = OpenFileToRead(filename);
		while (loopCounter > 0)
		{
			if (inventory->First == NULL)
			{
				inventory->First = new Product;
				inventory->First->Next = NULL;
				currentProduct = inventory->First;
			}
			else
			{
				currentProduct->Next = new Product;
				currentProduct->Next->Next = NULL;
				currentProduct = currentProduct->Next;
			}
			inventory->Size++;
			getline(InputFromFile, currentProduct->Name);
			InputFromFile >> currentProduct->Price;
			getline(InputFromFile, garbageLine);
			getline(InputFromFile, currentProduct->Desc);
			loopCounter = loopCounter - 3;
		}
		InputFromFile.close();
	}
	return inventory;
}

void AddProductToInventory(Inventory* inventory, std::string filename)
{
	Product* currentProduct = inventory->First;
	if (inventory->First == NULL)
	{
		inventory->First = new Product;
		currentProduct = inventory->First;
		currentProduct->Next = NULL;
	}
	else
	{
		while (currentProduct->Next != NULL)
		{
			currentProduct = currentProduct->Next;//will automatically take you to the last entry in the list
		}
		currentProduct->Next = new Product;
		currentProduct = currentProduct->Next;
	}
	inventory->Size++;
	std::cout << "Enter a new product name: ";
	getline(std::cin, currentProduct->Name);
	std::cout << "Enter product Price: $";
	currentProduct->Price = GetPriceFromUser();
	std::cout << "Enter a description for [" << currentProduct->Name << "]: ";
	std::cin.ignore();
	getline(std::cin, currentProduct->Desc);
	std::ofstream OutputToFile = OpenFileToAppend(filename);
	OutputToFile << currentProduct->Name << std::endl;
	OutputToFile << std::fixed << std::setprecision(2) << currentProduct->Price << std::endl;
	OutputToFile << currentProduct->Desc << std::endl;
	OutputToFile.close();
}

void DisplayProductsInInventory(Inventory* inventory)
{
	if (inventory->First == NULL)
	{
		std::cout << "-----------[EMPTY]-------------" << std::endl;
		return;
	}
	else
	{
		Product* currentProduct = inventory->First;
		for (int i = 0; i < inventory->Size; i++)
		{
			std::cout << "----------[" << currentProduct->Name << "]----------" << std::endl;
			std::cout << "Price: $" << currentProduct->Price << std::endl;
			std::cout << "Description: " << currentProduct->Desc << std::endl;
			currentProduct = currentProduct->Next;
		}
	}
}
