#include "Inventory.h"
#include "FileIO.h"
#include "Menu.h"
#include <iomanip>
namespace FileSpace
{
	std::string filename = "Inventory.txt";
}

int main()
{
	Inventory* inventory = FillInventoryFromFile(FileSpace::filename);
	//std::ofstream Overwrite = OpenFileToOverwrite(FileSpace::filename);
	AddProductToInventory(inventory, FileSpace::filename);
	DisplayProductsInInventory(inventory);
	delete inventory->First;
	delete inventory;
	std::cin.get();
	return 0;
}