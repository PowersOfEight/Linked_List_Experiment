#pragma once
#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "Inventory.h"
#include "FileIO.h"
enum class MenuState
{
	Main,
	Sort,
	Display,
	Exit
};

void mainMenu();


#endif // !MENU_H

