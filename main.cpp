#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printField(char field[3][3]);
void getUserMove(char field[3][3], const char playerSign);
void getComputerMove(char field[3][3], const char computerSign);
void matchVsComputer(char field[3][3], const char playerSign, const char computerSign);
void matchVsPlayer(char field[3][3], const char player1Sign, const char player2Sign);
bool checkIfUserWon(char field[3][3], bool win, const char playerSign);
bool checkIfComputerWon(char field[3][3], bool win, const char playerSign);

int main()
{
    srand(time(NULL));
    char field[3][3] = {{' ', ' ', ' '}, 
                        {' ', ' ', ' '}, 
                        {' ', ' ', ' '}};
    //char* pField = field[0];

    //player vs computer
    char playerSign;
    char computerSign;

    //player vs player;
    char player1Sign;
    char player2Sign;
    bool player1Win;
    bool player2Win;

    int choice;

    cout<<"******** TIC TAC TOE ********\n";
    do
    {
        cout<<"1. Player VS CPU\n";
        cout<<"2. Player VS Player\n";
        cout<<"0. Exit\n";

        cout<<"Choice: ";
        cin>>choice;

    } while (choice < 0 || choice > 2);

    switch (choice)
    {
    case 0:
        cout<<"Goodbye\n";
        break;

    case 1:
        do
        {
            cout<<"Choose your sign (/'O/' or /'X/'): ";
            cin>>playerSign;
            playerSign = toupper(playerSign);
        } while (playerSign != 'O' && playerSign != 'X');

        playerSign == 'O' ? computerSign = 'X' : computerSign = 'O';
            
        matchVsComputer(field, playerSign, computerSign);
        break;

    case 2:
        do
        {
            cout<<"Player 1: choose your sign (/'O/' or /'X/'): ";
            cin>>player1Sign;
            player1Sign = toupper(player1Sign);
        } while (player1Sign != 'O' && player1Sign != 'X');

        player1Sign == 'O' ? player2Sign = 'X' : player2Sign = 'O';
            
        matchVsPlayer(field, player1Sign, player2Sign);
        break;

    default:
        break;
    }

    cout<<"***************************************\n";

    
    return 0;
}

void printField(char field[3][3]){
    std::cout<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<< field[0][0] <<"  |  "<< field[0][1] <<"  |  "<< field[0][2] <<"  "<<'\n';
    std::cout<<"_____|_____|_____"<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<< field[1][0] <<"  |  "<< field[1][1] <<"  |  "<< field[1][2] <<"  "<<'\n';
    std::cout<<"_____|_____|_____"<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<< field[2][0] <<"  |  "<< field[2][1] <<"  |  "<< field[2][2] <<"  "<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<'\n';
}

void getUserMove(char field[3][3], const char playerSign){

    int row, colum;
    bool alreadySigned;  // checks if the row and colum got in input was already signed by the player (ik i suck at english)

    do
    {
        alreadySigned = false;

        do
        {
            cout<<"insert the row: ";
            cin>>row;
        } while (row < 1 || row > 3);
        
        do
        {
            cout<<"insert the colum: ";
            cin>>colum;
        } while (colum < 1 || colum > 3);
        
        if (field[row - 1][colum - 1] == ' ')
        {
            field[row - 1][colum - 1] = playerSign;
            alreadySigned = true;
        }

    } while (!alreadySigned);
}

void getComputerMove(char field[3][3], const char computerSign){
    
    srand(time(NULL));
    int row, colum;
    bool alreadySigned;  // checks if the row and colum randomly generated were already signed by the AI

    do
    {
        alreadySigned = false;

        row = rand() % 3;

        colum = rand() % 3;

        if (field[row][colum] == ' ')
        {
            field[row][colum] = computerSign;
            alreadySigned = true;
        }
        
    } while (!alreadySigned);
}

bool checkIfUserWon(char field[3][3], bool win, const char playerSign){
    // player wins? return true

    if (field[0][0] == playerSign && field[0][1] == playerSign && field[0][2] == playerSign) //i'm trurely sorry idk how to make it easier to read
    {
        return true;
    }
    else if (field[1][0] == playerSign && field[1][1] == playerSign && field[1][2] == playerSign)
    {
        return true;
    }
    else if (field[2][0] == playerSign && field[2][1] == playerSign && field[2][2] == playerSign)
    {
        return true;
    }
    else if (field[0][0] == playerSign && field[1][0] == playerSign && field[2][0] == playerSign)
    {
        return true;
    }
    else if (field[0][1] == playerSign && field[1][1] == playerSign && field[2][1] == playerSign)
    {
        return true;
    }
    else if (field[0][2] == playerSign && field[1][2] == playerSign && field[2][2] == playerSign)
    {
        return true;
    }
    else if (field[0][0] == playerSign && field[1][1] == playerSign && field[2][2] == playerSign)
    {
        return true;
    }
    else if (field[0][2] == playerSign && field[1][1] == playerSign && field[2][0] == playerSign)
    {
        return true;
    }
    else{
        return false;
    }
}

bool checkIfComputerWon(char field[3][3], bool win, const char computerSign){
    // computer wins? return true

    if (field[0][0] == computerSign && field[0][1] == computerSign && field[0][2] == computerSign) //i'm trurely sorry idk how to make it easier to read
    {
        return true;
    }
    else if (field[1][0] == computerSign && field[1][1] == computerSign && field[1][2] == computerSign)
    {
        return true;
    }
    else if (field[2][0] == computerSign && field[2][1] == computerSign && field[2][2] == computerSign)
    {
        return true;
    }
    else if (field[0][0] == computerSign && field[1][0] == computerSign && field[2][0] == computerSign)
    {
        return true;
    }
    else if (field[0][1] == computerSign && field[1][1] == computerSign && field[2][1] == computerSign)
    {
        return true;
    }
    else if (field[0][2] == computerSign && field[1][2] == computerSign && field[2][2] == computerSign)
    {
        return true;
    }
    else if (field[0][0] == computerSign && field[1][1] == computerSign && field[2][2] == computerSign)
    {
        return true;
    }
    else if (field[0][2] == computerSign && field[1][1] == computerSign && field[2][0] == computerSign)
    {
        return true;
    }
    else{
        return false;
    }
}

void matchVsComputer(char field[3][3], const char playerSign, const char computerSign){
    bool playerWin;
    bool computerWin;
    int indexMatch;
    
    cout<<"Here's the field:\n";
    printField(field);

    for (indexMatch = 0; indexMatch < 9; indexMatch++)
    {
        //User's turn
        cout<<"******* PLAYER'S TURN *******\n";
        getUserMove(field, playerSign);
        system("pause");
        printField(field);

        playerWin = checkIfUserWon(field, playerWin, playerSign);
        if (playerWin)
        {
            cout<<"YOU WON!\n";
            break;
        }

        if (indexMatch == 4) // i put this because the field now is full of sign (5 by player1 - 4 by player2)
        {
            break;
        }

        //AI's turn
        getComputerMove(field, computerSign);
        cout<<"******* COMPUTER'S TURN *******\n";
        system("Pause");
        printField(field);

        computerWin = checkIfComputerWon(field, computerWin, computerSign);
        if (computerWin)
        {
            cout<<"COMPUTER WON! - YOU LOST!\n";
            break;
        }
    }

    if (indexMatch == 4 && !playerWin && !computerWin)
    {
        cout<<"It's a draw!\n";
    }
}

void matchVsPlayer(char field[3][3], const char player1Sign, const char player2Sign){
    bool player1Win;
    bool player2Win;
    int indexMatch;
    
    cout<<"Here's the field:\n";
    printField(field);

    for (indexMatch = 0; indexMatch < 5; indexMatch++)
    {
        //Player 1's turn
        cout<<"******* PLAYER 1 TURN *******\n";
        getUserMove(field, player1Sign);
        system("pause");
        printField(field);

        player1Win = checkIfUserWon(field, player1Win, player1Sign);
        if (player1Win)
        {
            cout<<"PLAYER 1 WON!\n";
            break;
        }

        if (indexMatch == 4) // i put this because the field now is full of sign (5 by player1 - 4 by player2)
        {
            break;
        }

        //Player 2's turn
        cout<<"******* PLAYER 2 TURN *******\n";
        getUserMove(field, player2Sign);
        system("Pause");
        printField(field);

        player2Win = checkIfComputerWon(field, player2Win, player2Sign);
        if (player2Win)
        {
            cout<<"PLAYER 2 WON!\n";
            break;
        }
    }

    if (indexMatch == 4 && !player1Win && !player2Win)
    {
        cout<<"It's a draw!\n";
    }
}