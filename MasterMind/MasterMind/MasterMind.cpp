// MasterMind.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>


std::random_device depart;
std::mt19937 hasard(depart());
std::uniform_int_distribution<> d6(1, 6);

int main()
{

	std::string Grid[10][4] = { { " "," "," "," " },
								{ " "," "," "," " },
								{ " "," "," "," " },
								{ " "," "," "," " },
								{ " "," "," "," " },
								{ " "," "," "," " },
								{ " "," "," "," " },
								{ " "," "," "," " },
								{ " "," "," "," " },
								{ " "," "," "," " } };

	std::string Colors[6] = { "J","R","B","M","C","V" };
	std::string CPU[4] = {Colors[d6(hasard)], Colors[d6(hasard)], Colors[d6(hasard)], Colors[d6(hasard)]};
	

	return 0;
}

