#include <iostream>


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

		std::cout << "Choose your option: (1.) X or (2.) O" << std::endl;
		std::cin >> player_option;

		switch (player_option)
		{
		case 1:
			player_dice = "X";
			break;
		case 2:
			player_dice = "O";
			break;
		default:
			std::cout << "Please choose type 1 or 2.";
			std::cout << std::endl;
			return ChoosePlayerDice();
			break;
		}

		std::cout << "You chose: " << player_dice << std::endl;
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
		while (continue_game)
		{
			PlayerName();
			ChoosePlayerDice();
			DrawBoard();
			std::cout << std::endl;
			ContinueGame();
		}
		std::cout << std::endl << "Goodbye, Hope you enjoyed the game!";
	}

private:
	int arr_length = 3;
	std::string player_name;
	std::string player_dice;
	std::string board[3][3] = {
		{" ", " ", " "},
		{" ", " ", " "},
		{" ", " ", " "}
	};
	bool continue_game = true;
};



int main()
{
	TicTacToe game;

	game.StartGame();

	return 0;
}