#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void ChoosingFirstPlayer(bool& playerTurn);
void GameGrid(char grid[]);
void ColumnChoice(bool& playerTurn, int& columnChoice);
void TokenPlacement(bool& playerTurn, int& columnChoice, int& columnStack, char grid[6][7]);
bool WinValidation();
void GameEnd();

void main()
{
	char grid[6][7] = { {'1', '2', '3', '4', '5', '6', '7'},
						{' ', ' ', ' ', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', ' ', ' ', ' ', ' '} };
	int columnChoice;
	int columnStack[6] = { 0, 0, 0, 0, 0, 0 };
	int tokenWinCount;
	bool gameOn = true;
	bool playerTurn = true;

	cout << "Bienvenue au jeu de Connect4 !" << endl;
	cout << "Le but du jeu est de faire une ligne, colonne ou diagonale de 4 jetons identiques." << endl;
	cout << "Tirons le premier joueur au hasard !" << endl;

	system("pause");
	system("cls");

	ChoosingFirstPlayer(playerTurn);

	system("pause");
	system("cls");

	while (gameOn)
	{
		GameGrid(grid);
		do
		{
			ColumnChoice(playerTurn, columnChoice);
		} while (columnStack[columnChoice] < 6);
		TokenPlacement(playerTurn, columnChoice, columnStack[columnChoice], grid);

		if (WinValidation)
		{
			gameOn = false;
		}
	}

}

void ChoosingFirstPlayer(bool& playerTurn)
{
	srand(time(0));
	int firstPlayer = rand() % 2;

	if (firstPlayer == 0)
	{
		cout << "Vous jouez en premier !" << endl;
		playerTurn = true;
	}
	else
	{
		cout << "L'Ordi joue en premier ! " << endl;
		playerTurn = false;
	}
}


void GameGrid(char grid[6][7])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j == 0)
			{
				cout << "| " << grid[i][j] << " | ";
			}				
			else if (j == 6)
			{
				cout << grid[i][j] << " |" << endl;
			}				
			else
			{
				cout << grid[i][j] << " | ";
			}
		}
		cout << "-----------------------------" << endl;
	}
}

void ColumnChoice(bool& playerTurn, int& columnChoice)
{
	if (playerTurn)
	{
		do
		{
			cout << "Entrez un choix de colonne entre 1 et 7: ";
			cin >> columnChoice;
			cout << endl;
		} while (columnChoice < 1 || columnChoice > 7);
	}
	else
	{

			columnChoice = rand() % 7;
	}
}

void TokenPlacement(bool& playerTurn, int& columnChoice, int& columnStack, char grid[6][7])
{
	do
	{
		if (playerTurn)
		{
			grid[columnStack[columnChoice]][columnChoice] = 'X';
		}
		else
		{
			grid[columnStack[columnChoice]][columnChoice] = 'O';
		}
	} while (columnStack[columnChoice] < 6);

	columnStack++;
	!playerTurn;
}

bool WinValidation()
{
	if ()
}

void GameEnd()
{

}