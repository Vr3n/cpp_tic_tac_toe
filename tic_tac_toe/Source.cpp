#include <iostream>
#include <vector>
#include <random>

template<typename T>
T random(T range_from, T range_to) {
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<T> distrib(range_from, range_to);
	return distrib(generator);
}

class TicTacToe
{
public:

	void PlayerName()
	{
		// Take Name as Input.
		std::cout << "Enter your name: ";
		std::cin >> player_name;

		std::cout << std::endl;

		std::cout << "Hello, " << player_name << std::endl;
	}

	void DrawBoard()
	{
		for (int i = 0; i < arr_length; ++i)
		{
			for (int j = 0; j < arr_length; ++j)
			{
				switch (j)
				{
				case 1:
					std::cout << " | " << board[i][j] << " | ";
					break;

				default:
					std::cout << board[i][j];
					break;
				};
			}
			std::cout << std::endl;
		}
	}

	void ChoosePlayerDice()
	{
		int player_option;

		std::cout << "Choose your option: 1: X or 2: O" << std::endl;
		std::cin >> player_option;

		switch (player_option)
		{
		case 1:
			player_dice = "X";
			computer_dice = "O";
			break;
		case 2:
			player_dice = "O";
			computer_dice = "X";
			break;
		default:
			std::cout << "Please choose type 1 or 2.";
			std::cout << std::endl;
			return ChoosePlayerDice();
			break;
		}

		std::cout << "You chose: " << player_dice << std::endl;
	}

	void PlayerPositionInput()
	{
		int row = 1;
		int col = 1;

		std::cout << "Player turn, Enter your position you want to place dice." << std::endl;
		std::cout << "Row: ";
		std::cin >> row;
		std::cout << std::endl << "Col: ";
		std::cin >> col;

		if (row <= 3 && col <= 3)
		{
			row -= 1;
			col -= 1;
			if (board[row][col] == " ")
			{
				board[row][col] = player_dice;
				visited++;
				std::cout << std::endl;
				DrawBoard();
			}
			else {
				std::cout << row << " " << col << " position is already occupied pls chose another position" << std::endl;
				return PlayerPositionInput();
			}
		}
		else
		{
				std::cout << "Enter the row and column numbers under 3." << std::endl << "Eg: row = 3, col = 3" << std::endl;
				return PlayerPositionInput();

		}
	}

	void ComputerPositionInput()
	{
		const int range_from = 0;
		const int range_to = 2;

		int row = random(range_from, range_to);
		int col = random(range_from, range_to);

		if (board[row][col] == " ")
		{
			board[row][col] = computer_dice;
			visited++;
			std::cout << std::endl;
			DrawBoard();
		}
		else
		{
			return ComputerPositionInput();
		}
	}

	void ContinueGame()
	{
		char option;
		std::cout << "Do you want to continue playing (Y/N)? ";
		std::cin >> option;

		if (toupper(option) == 'N')
			continue_game = false;

	}

	void StartGame()
	{
		std::cout << "*** Welcome to TIC TAC TOE ***" << std::endl;
		std::cout << std::endl;
		PlayerName();
		ChoosePlayerDice();
		while (continue_game)
		{
			DrawBoard();
			PlayerPositionInput();
			std::cout << std::endl;
			ComputerPositionInput();
			std::cout << std::endl;
			ContinueGame();
		}
		std::cout << std::endl << "Goodbye, Hope you enjoyed the game!";


	}

private:
	int arr_length = 3;
	std::string player_name;
	std::string player_dice;
	std::string computer_dice;
	std::string board[3][3] = {
		{" ", " ", " "},
		{" ", " ", " "},
		{" ", " ", " "}
	};
	bool continue_game = true;
	int visited = 0;
};


int main()
{
	TicTacToe game;

	game.StartGame();

	return 0;
}