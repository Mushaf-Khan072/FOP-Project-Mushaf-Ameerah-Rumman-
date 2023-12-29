























#include <iostream>
using namespace std;

char board[9]; // 1D array to represent a 3x3 Tic-Tac-Toe board

// Initialize the board with empty spaces
void initializeBoard() 
{
    for (int i = 0; i < 9; ++i) 
	{
        board[i] = ' ';
    }
}

// Display the current status of the board
void displayBoard() 
{
	int s = 0;
    cout << "-------------" << endl;
    
	for (int i = 0; i < 3; ++i) 
	{
        cout << "| ";
        for (int j = 0; j < 3; ++j) 
		{
            cout << board[s] << " | ";
            s++;            
        }
        cout << endl << "-------------" << endl;
    }
}

// Check if the game is over (win or draw)
bool gameOver() 
{
    // Check rows, columns, and diagonals for a win.
    for (int i = 0; i < 3; ++i) 
    
	{
        if (board[i * 3] != ' ' && board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2]) 
		{
            return true; // Row win
        }
        
		if (board[i] != ' ' && board[i] == board[3 + i] && board[3 + i] == board[6 + i]) 
		{
            return true; // Column win
        }
    }
    
	if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8]) 
	{
        return true; // Diagonal win (top-left to bottom-right)
    }
    
	if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6]) 
	{
        return true; // Diagonal win (top-right to bottom-left)
    }

    // Check for a draw
    for (int i = 0; i < 9; ++i) 
	{
        if (board[i] == ' ') 
		{
            return false; // Game is not over yet
        }
    }
    return true; // Game ends in a draw
}

// Main game loop
void playGame() 
{
    int position;
    char currentPlayer = 'X'; // Player 'X' starts

    while (true) {
        displayBoard();

        // Player's turn
        cout << "Player " << currentPlayer << ", enter position (1-9): ";
        cin >> position;

        // Convert from 1-based to 0-based indexing
        position--;

        // Check if the chosen position is valid
        if (position >= 0 && position < 9 && board[position] == ' ') 
		{
            board[position] = currentPlayer;

            // Check if the game is over
            if (gameOver()) 
			{
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } 
		
		else 
		{
            cout << "Invalid move. Try again." << endl;
        }
    }

    if (!gameOver()) 
	{
        displayBoard();
        cout << "It's a draw!" << endl;
    }
}

int main() 
{
    int i = 0;
	
	cout << "The layout of the positions for the game is as follows:" << endl;
	
    for (int line = 0; line < 7; line++)
    {
	    if (line % 2 == 0)
	    {
		    cout << " -------------\n";
	    }
	    
		else
	    {
		    for (int x = 1; x <= 3; x++)
		    {
				i++;
					cout << " | " << i;
				} 
				
				cout << " | " << endl;
			}
	}
	
	
	cout << "Welcome to Tic-Tac-Toe!" << endl;
    initializeBoard();
    playGame();
    return 0;
}