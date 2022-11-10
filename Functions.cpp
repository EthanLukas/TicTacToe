#include "Functions.h"

void runGame()
{
    bool playagain = true;
    bool gameover = false;
    while(playagain == true)
    {
        char gameboard[3][3];
        initBoard(gameboard);
        bool isx = true;
        while(gameover == false)
        {
            int xcoord;
            int ycoord;
            if(isx == true)
            {
                std::cout << "Enter coordinate for X. Input should be X Y" << std::endl;
            }
            else
            {
                std::cout << "Enter coordinate for O. Input should be X Y" << std::endl;
            }
            std::cin >> xcoord;
            std::cin >> ycoord;

            //X's turn
            if(isx == true)
            {
                placeAPiece(xcoord, ycoord, 'X', gameboard);

                displayBoard(gameboard);

                bool winX = checkForWinner('X', gameboard);

                if(winX == true)
                {
                    cout << "X Won" << std::endl;
                    gameover = true;
                }

                else
                {
                    bool drawcheckX = checkForDraw(gameboard);

                    if(drawcheckX == true)
                    {
                        cout << "Draw" << std::endl;
                        gameover = true;
                    }
                }
                
                isx = false;
            }
            //O's turn
            else
            {
                placeAPiece(xcoord, ycoord, 'O', gameboard);

                displayBoard(gameboard);

                bool winO = checkForWinner('O', gameboard);

                if(winO == true)
                {
                    cout << "O Won" << std::endl;
                    gameover = true;
                }
                
                else 
                {
                    bool drawcheckO = checkForDraw(gameboard);

                    if(drawcheckO == true)
                    {
                        cout << "Draw" << std::endl;
                        gameover = true;
                    }
                }

                isx = true;
            }
        }
        string inp1;
        std::cout << "Do you want to play again?" << std::endl;
        std::cin >> inp1;
        if(inp1 == "Y" || inp1 == "y")
        {
            playagain = true;
            gameover = false;
        }
        else
        {
            playagain = false;
        }
    }
    std::cout << "Done" << std::endl;
}

//Nested for loop to fill the board with "empty" - characters
void initBoard(char board[3][3])
{
    for(int row = 0; row<3; row++)
    {
        for(int col = 0; col<3; col++)
        {
            board[row][col] = '-';
        }
    }
}

//Makes the equivalent coordinate on the board from arguments take the value of the piece
void placeAPiece(int x, int y, char piece, char board[3][3])
{
    board[x][y] = piece;
}

bool checkForWinner(char piece, char board[3][3])
{
    if(board[0][0] == board[0][1] &&  board[0][1] == board[0][2] && board[0][0] == piece)
    {
        return true;
    }
    else if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == piece)
    {
        return true;
    }
    else if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == piece)
    {
        return true;
    }
    else if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == piece)
    {
        return true;
    }
    else if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == piece)
    {
        return true;
    }
    else if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == piece)
    {
        return true;
    }
    else if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == piece)
    {
        return true;
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == piece)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkForDraw(char board[3][3])
{
    bool full = true;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(board[i][j] == '-')
            {
                full = false;
            }

        } 
    }
    if(full == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


void displayBoard(char board[3][3])
{
    std::cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << std::endl;
}