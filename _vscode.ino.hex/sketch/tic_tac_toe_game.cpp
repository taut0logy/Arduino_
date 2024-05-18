#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\tic_tac_toe_game.cpp"
#include <iostream>
#include <string>

using namespace std;

// Function to draw the board
void drawBoard(string board[3][3])
{
    cout << "  -------------\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "  | ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << "\n  -------------\n";
    }
}

// Function to check if someone has won
bool checkWin(string board[3][3])
{
    // Check for horizontal wins
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
    }
    
    // Check for vertical wins
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }
    
    // Check for diagonal wins
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
    {
        return true;
    }
    
    // No one has won
    return false;
}

int main()
{
    // Create a 3x3 board
    string board[3][3] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}
    };
    
    // Keep track of whose turn it is
    string turn = "X";
    
    // Keep playing until someone wins
    while (!checkWin(board))
    {
        // Draw the board
        drawBoard(board);
        
        // Get the player's move
        int row, col;
        cout << turn << "'s turn. Enter row and column: ";
        cin >> row >> col;
        
        // Make sure the space is empty
        if (board[row][col] == " ")
        {
            board[row][col] = turn;
            
            // Switch turns
            if (turn == "X")
            {
                turn = "O";
            }
            else
            {
                turn = "X";
            }
        }
        else
        {
            cout << "That space is already taken!\n";
        }
    }
    
    // Someone has won
    drawBoard(board);
    cout << turn << " has won!\n";
    
    return 0;
}
