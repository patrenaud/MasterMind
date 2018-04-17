// MasterMind.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>

void Instructions();
void ShowGrid(std::vector<std::vector<std::string>> &Grid, std::vector<std::string> CPU);

std::random_device depart;
std::mt19937 hasard(depart());
std::uniform_int_distribution<> d6(0, 5);

int main()
{

	std::vector<std::vector<std::string>> Grid = {  { " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " } };

	std::vector<std::string> Colors = { "J","R","B","M","C","V" };
	std::vector<std::string> CPU = {Colors[d6(hasard)], Colors[d6(hasard)], Colors[d6(hasard)], Colors[d6(hasard)]};

	Instructions();
	ShowGrid(Grid, CPU);

	return 0;
}

void Instructions()
{
	std::cout
		<< "Les règles sont simples, vous devez entrer 4 couleurs et trouver la" << std::endl
		<< "combinaison gagnante. Les billes noires indiquent les bonnes réponses" << std::endl
		<< "et les billes blanches les réponses mal placées. Bonne chance!" << std::endl
		<< "---------------------------------------------------------------------" << std::endl
		<< "Vous devez mettre un espace entre vos lettres en MAJUSCULE" << std::endl
		<< "J = Jaune / R = Rouge / B = Bleu / M = Mauve / O = Orange / V = Vert" << std::endl;
}

void ShowGrid(std::vector<std::vector<std::string>> &Grid, std::vector<std::string> CPU )
{
	int round = 0;
	int Win = 0;

	do 
	{
		std::cout << "Entrez 4 couleurs entre J, R, B, M, O, V : " << std::endl;
		std::cin >> Grid[round][0] >> Grid[round][1] >> Grid[round][2] >> Grid[round][3];
		for (int i = 0; i < 10; i++)
		{
			std::cout << "| "<< Grid[i][0] << " | " << Grid[i][1] << " | " << Grid[i][2] << " | " << Grid[i][3] << " |" << std::endl;
			std::cout << "+---+---+---+---+" << std::endl;
		}


	} while (Win == 1 || round == 10);

}