// MasterMind.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>

void Instructions();
void ShowGrid(std::vector<std::vector<std::string>> &Grid, std::vector<std::string> CPU);
void CheckWin(std::vector<std::vector<std::string>> Grid, std::vector<std::string> CPU, int round, int& Win);
int CheckWinWhite(std::vector<std::string> &CopieCPU, std::vector<std::vector<std::string>> Grid, int round);
int CheckWinBlack(std::vector<std::string> &CopieCPU, std::vector<std::vector<std::string>> Grid, int round);

std::random_device depart;
std::mt19937 hasard(depart());
std::uniform_int_distribution<> d6(0, 5);

int main()
{

	std::vector<std::vector<std::string>> Grid = { { " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " },
													{ " "," "," "," " } };

	std::vector<std::string> Colors = { "J","R","B","M","O","V" };
	std::vector<std::string> CPU = { Colors[d6(hasard)], Colors[d6(hasard)], Colors[d6(hasard)], Colors[d6(hasard)] };

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

void ShowGrid(std::vector<std::vector<std::string>> &Grid, std::vector<std::string> CPU)
{
	int round = 0;
	int Win = 0;

	do
	{
		std::cout << "Entrez 4 couleurs entre J, R, B, M, O, V : " << std::endl;
		std::cin >> Grid[round][0] >> Grid[round][1] >> Grid[round][2] >> Grid[round][3];
		for (int i = 0; i < 10; i++)
		{
			std::cout << "| " << Grid[i][0] << " | " << Grid[i][1] << " | " << Grid[i][2] << " | " << Grid[i][3] << " |" << std::endl;
			std::cout << "+---+---+---+---+" << std::endl;
		}

		CheckWin(Grid, CPU, round, Win);
		round++;

		if (round == 10)
		{
			std::cout << "Vous avez perdu, la solution était: " << CPU[0] << CPU[1] << CPU[2] << CPU[3] << std::endl;
		}
	} while (Win != 1 || round != 10);
}

void CheckWin(std::vector<std::vector<std::string>> Grid, std::vector<std::string> CPU, int round, int& Win)
{
	std::vector<std::string> CopieCPU = CPU;

	std::cout << "BILLES NOIR - Nombre de bonne réponses (couleurs bien placées) : " << CheckWinBlack(CopieCPU, Grid, round) << std::endl;
	std::cout << "BILLES BLANCHE - Nombre de réponses valides mais mal positionnées : " << CheckWinWhite(CopieCPU, Grid, round) << std::endl;

	if (Grid[round][0] == CPU[0] && Grid[round][1] == CPU[1] && Grid[round][2] == CPU[2] && Grid[round][3] == CPU[3])
	{
		std::cout << "You Win" << std::endl;
		Win = 1;
	}
}

int CheckWinBlack(std::vector<std::string> &CopieCPU, std::vector<std::vector<std::string>> Grid, int round)
{
	int noir = 0;

	for (int i = 0; i <= 3; i++)
	{
		if (Grid[round][i] == CopieCPU[i])
		{
			noir++;
			CopieCPU[i] = ' ';
		}
	}
	return noir;
}


int CheckWinWhite(std::vector<std::string> &CopieCPU, std::vector<std::vector<std::string>> Grid, int round)
{
	int blanc = 0;

	for (int i = 0; i <= 3; i++)
	{
		if (Grid[round][i] != CopieCPU[i])
		{
			if (Grid[round][i] == CopieCPU[0])
			{
				blanc++;
				CopieCPU[0] = ' ';
			}
			else if (Grid[round][i] == CopieCPU[1])
			{
				blanc++;
				CopieCPU[1] = ' ';
			}
			else if (Grid[round][i] == CopieCPU[2])
			{
				blanc++;
				CopieCPU[2] = ' ';
			}
			else if (Grid[round][i] == CopieCPU[3])
			{
				blanc++;
				CopieCPU[3] = ' ';
			}
		}
	}
	return blanc;
}
