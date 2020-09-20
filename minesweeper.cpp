#include "minesweeper.h"
#include <iostream>


using namespace std;


// Class->Place Functions

Place::Place()
{
    
    marked = false;
    isMine = false;
    isFlag = false;
    int minesnearby = 0;
    string appearance = "-";

}

void Place::set_isMarked(bool tf)
{
    marked = tf;
}

void Place::set_isMine(bool tf)
{
    isMine = tf;
}

void Place::set_isFlag(bool tf)
{
    isFlag = tf;
}

void Place::set_appearance(string s)
{
    appearance = s;
    // s will be the number of adjacent mines
}

bool Place::get_isMarked()
{
    return marked;
}

bool Place::get_isMine()
{
    return isMine;
}

bool Place::get_isFlag()
{
    return isFlag;
}

string Place::get_appearance()
{
    return appearance;
}

void Place::add_minesnearby()
{
    minesnearby++;
}

int Place::get_minesnearby()
{
    return minesnearby;
}


// MineBoardEasy Functions


MineBoardEasy::MineBoardEasy()
{
    
}


void MineBoardEasy::create_board()
{

    //for each row, a mine will be in a random column
    for(int i = 0; i <= rows; i++)
    {
        
        //get random x and y value
        int randx = rand() % (rows - 1);
        int randy = rand() % (columns - 1);

        

        if (board[randx][randy].get_isMine() == true)
        {
            i--;
        }
        if (board[randx][randy].get_isMine() == false)
        {
            board[randx][randy].set_isMine(true);
        }
    
    }

}


void MineBoardEasy::create_integers()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j].get_isMine() == false)
            {
                if (board[i + 1][j + 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i + 1][j].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i][j + 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i - 1][j - 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i - 1][j].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i][j - 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i + 1][j - 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i - 1][j + 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
            }
        }
    }
}





void MineBoardEasy::spawn_appearances()
{
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j].get_isMarked() == true && board[i][j].get_isMine() == true)
            {
                board[i][j].set_appearance("X");
            }
            if (board[i][j].get_isMarked() == false) 
            {
                board[i][j].set_appearance("-");
            }
            if (board[i][j].get_isMarked() == false && board[i][j].get_isFlag() == true)
            {
                board[i][j].set_appearance("#");
            }
            else if (board[i][j].get_isMarked() == true && board[i][j].get_isMine() == false && board[i][j].get_minesnearby() >= 0)
            {
                string s = to_string(board[i][j].get_minesnearby());
                board[i][j].set_appearance(s);
            }
        }
    }    
}

void MineBoardEasy::display_board()
{
    cout << "------------------" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << " " << board[i][j].get_appearance() << " " ;
        }
        
        cout << endl;
    }
    cout << "------------------" << endl;
}


void MineBoardEasy::make_move()
{
    cout << "Enter the coordinates of the place you wish to select: " << endl;

    cout << "First, enter column value(0 - 5): ";
    string input1;
    getline(cin, input1);
    cout << endl;

    cout << "Next, enter row value(0 - 5): ";
    string input2;
    getline(cin,input2);
    cout << endl;

    int board_column = stoi(input1);
    int board_row = stoi(input2);

    cout << "Do you want to mark this square, or flag it?(type 'M' to mark and 'F' to flag): ";
    string input3;
    while(getline(cin, input3))
    {
        if (input3 == "M")
        {
            

            board[board_row][board_column].set_isMarked(true);
            
            if (board[board_row + 1][board_column + 1].get_isMine() == false)
            {
                board[board_row + 1][board_column + 1].set_isMarked(true);
            }
            if (board[board_row + 1][board_column].get_isMine() == false)
            {
                board[board_row + 1][board_column].set_isMarked(true);
            }
            if (board[board_row][board_column + 1].get_isMine() == false)
            {
                board[board_row][board_column + 1].set_isMarked(true);
            }
            if (board[board_row - 1][board_column - 1].get_isMine() == false)
            {
                board[board_row - 1][board_column - 1].set_isMarked(true);
            }
            if (board[board_row - 1][board_column].get_isMine() == false)
            {
                board[board_row - 1][board_column].set_isMarked(true);
            }
            if (board[board_row][board_column - 1].get_isMine() == false)
            {
                board[board_row][board_column - 1].set_isMarked(true);
            }
            if (board[board_row + 1][board_column - 1].get_isMine() == false)
            {
                board[board_row + 1][board_column - 1].set_isMarked(true);
            }
            if (board[board_row - 1][board_column + 1].get_isMine() == false)
            {
                board[board_row - 1][board_column + 1].set_isMarked(true);
            }
            
            break;
        }
        if (input3 == "F")
        {
            board[board_row][board_column].set_isFlag(true);
            break;
        }
        else
        {
            cout << "Invalid input, please enter M or F: " << endl;
        }
    }
    
    
}

bool MineBoardEasy::check_end_game_lose()
{
    bool flag = false;
    //LOSING THE GAME
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // Condition:
            if (board[i][j].get_isMine() == true && board[i][j].get_isMarked() == true)
            {
                flag = true;
                return true;
            }
            
        }
        

    }

    return false; 

}

bool MineBoardEasy::check_end_game_win()
{
    int mines = 0;
    int flags = 0;

    //WINNING THE GAME
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j].get_isMine() == true)
            {
                mines++;
            }
            if (board[i][j].get_isFlag() == true & board[i][j].get_isMine() == true)
            {
                flags++;
            }
        }
    }

    if (mines == flags)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MineBoardEasy::run_minesweeper()
{
    create_board();
    create_integers();

    while(check_end_game_lose() == false && check_end_game_win() == false)
    {
        spawn_appearances();

        display_board();

        make_move();
    }
    if(check_end_game_lose() == true)
    {
        cout << "You lost, you selected a tile with a mine!" << endl;
    }
    if(check_end_game_win() == true)
    {
        cout << "You win, all mines are flagged!" << endl;
    }
}


//-------------------------------------------------------------------


// MineBoard Medium Functions

MineBoardMedium::MineBoardMedium()
{
}

void MineBoardMedium::create_board()
{

    for (int i = 0; i <= rows; i++)
    {

        //get random x and y value
        int randx = rand() % (rows - 1);
        int randy = rand() % (columns - 1);

        if (board[randx][randy].get_isMine() == true)
        {
            i--;
        }
        if (board[randx][randy].get_isMine() == false)
        {
            board[randx][randy].set_isMine(true);
        }
    }
}

void MineBoardMedium::create_integers()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j].get_isMine() == false)
            {
                if (board[i + 1][j + 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i + 1][j].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i][j + 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i - 1][j - 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i - 1][j].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i][j - 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i + 1][j - 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i - 1][j + 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
            }
        }
    }
}

void MineBoardMedium::spawn_appearances()
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j].get_isMarked() == true && board[i][j].get_isMine() == true)
            {
                board[i][j].set_appearance("X");
            }
            if (board[i][j].get_isMarked() == false)
            {
                board[i][j].set_appearance("-");
            }
            if (board[i][j].get_isMarked() == false && board[i][j].get_isFlag() == true)
            {
                board[i][j].set_appearance("#");
            }
            else if (board[i][j].get_isMarked() == true && board[i][j].get_isMine() == false && board[i][j].get_minesnearby() >= 0)
            {
                string s = to_string(board[i][j].get_minesnearby());
                board[i][j].set_appearance(s);
            }
        }
    }
}

void MineBoardMedium::display_board()
{
    cout << "------------------------" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << " " << board[i][j].get_appearance() << " ";
        }

        cout << endl;
    }
    cout << "------------------------" << endl;
}

void MineBoardMedium::make_move()
{
    cout << "Enter the coordinates of the place you wish to select: " << endl;

    cout << "First, enter column value(0 - 7): ";
    string input1;
    getline(cin, input1);
    cout << endl;

    cout << "Next, enter row value(0 - 7): ";
    string input2;
    getline(cin, input2);
    cout << endl;

    int board_column = stoi(input1);
    int board_row = stoi(input2);

    cout << "Do you want to mark this square, or flag it?(type 'M' to mark and 'F' to flag and unflag): ";
    string input3;
    while (getline(cin, input3))
    {
        if (input3 == "M")
        {

            board[board_row][board_column].set_isMarked(true);

            if (board[board_row + 1][board_column + 1].get_isMine() == false)
            {
                board[board_row + 1][board_column + 1].set_isMarked(true);
            }
            if (board[board_row + 1][board_column].get_isMine() == false)
            {
                board[board_row + 1][board_column].set_isMarked(true);
            }
            if (board[board_row][board_column + 1].get_isMine() == false)
            {
                board[board_row][board_column + 1].set_isMarked(true);
            }
            if (board[board_row - 1][board_column - 1].get_isMine() == false)
            {
                board[board_row - 1][board_column - 1].set_isMarked(true);
            }
            if (board[board_row - 1][board_column].get_isMine() == false)
            {
                board[board_row - 1][board_column].set_isMarked(true);
            }
            if (board[board_row][board_column - 1].get_isMine() == false)
            {
                board[board_row][board_column - 1].set_isMarked(true);
            }
            if (board[board_row + 1][board_column - 1].get_isMine() == false)
            {
                board[board_row + 1][board_column - 1].set_isMarked(true);
            }
            if (board[board_row - 1][board_column + 1].get_isMine() == false)
            {
                board[board_row - 1][board_column + 1].set_isMarked(true);
            }

            break;
        }
        if (input3 == "F") //This is a flag AND undo now
        {
            board[board_row][board_column].set_isFlag(true);
            break;
        }
        else
        {
            cout << "Invalid input, please enter M or F: " << endl;
        }
    }
}

bool MineBoardMedium::check_end_game_lose()
{
    bool flag = false;
    //LOSING THE GAME
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // Condition:
            if (board[i][j].get_isMine() == true && board[i][j].get_isMarked() == true)
            {
                flag = true;
                return true;
            }
        }
    }

    return false;
}

bool MineBoardMedium::check_end_game_win()
{
    int mines = 0;
    int flags = 0;

    //WINNING THE GAME
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j].get_isMine() == true)
            {
                mines++;
            }
            if (board[i][j].get_isFlag() == true & board[i][j].get_isMine() == true)
            {
                flags++;
            }
        }
    }

    if (mines == flags)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MineBoardMedium::run_minesweeper()
{
    create_board();
    create_integers();

    while (check_end_game_lose() == false && check_end_game_win() == false)
    {
        spawn_appearances();

        display_board();

        make_move();
    }
    if (check_end_game_lose() == true)
    {
        cout << "You lost, you selected a tile with a mine!" << endl;
    }
    if (check_end_game_win() == true)
    {
        cout << "You win, all mines are flagged!" << endl;
    }
}

//-------------------------------------------------------------------



// MineBoard Hard Functions


MineBoardHard::MineBoardHard()
{
}

void MineBoardHard::create_board()
{

    for (int i = 0; i <= rows; i++)
    {

        //get random x and y value
        int randx = rand() % (rows - 1);
        int randy = rand() % (columns - 1);

        if (board[randx][randy].get_isMine() == true)
        {
            i--;
        }
        if (board[randx][randy].get_isMine() == false)
        {
            board[randx][randy].set_isMine(true);
        }
    }
}

void MineBoardHard::create_integers()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j].get_isMine() == false)
            {
                if (board[i + 1][j + 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i + 1][j].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i][j + 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i - 1][j - 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i - 1][j].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i][j - 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i + 1][j - 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
                if (board[i - 1][j + 1].get_isMine() == true)
                {
                    board[i][j].add_minesnearby();
                }
            }
        }
    }
}

void MineBoardHard::spawn_appearances()
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j].get_isMarked() == true && board[i][j].get_isMine() == true)
            {
                board[i][j].set_appearance("X");
            }
            if (board[i][j].get_isMarked() == false)
            {
                board[i][j].set_appearance("-");
            }
            if (board[i][j].get_isMarked() == false && board[i][j].get_isFlag() == true)
            {
                board[i][j].set_appearance("#");
            }
            else if (board[i][j].get_isMarked() == true && board[i][j].get_isMine() == false && board[i][j].get_minesnearby() >= 0)
            {
                string s = to_string(board[i][j].get_minesnearby());
                board[i][j].set_appearance(s);
            }
        }
    }
}

void MineBoardHard::display_board()
{
    cout << "------------------------------" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << " " << board[i][j].get_appearance() << " ";
        }

        cout << endl;
    }

    cout << "------------------------------" << endl;
}

void MineBoardHard::make_move()
{
    cout << "Enter the coordinates of the place you wish to select: " << endl;

    cout << "First, enter column value(0 - 9): ";
    string input1;
    getline(cin, input1);
    cout << endl;

    cout << "Next, enter row value(0 - 9): ";
    string input2;
    getline(cin, input2);
    cout << endl;

    int board_column = stoi(input1);
    int board_row = stoi(input2);

    cout << "Do you want to mark this square, or flag it?(type 'M' to mark and 'F' to flag): ";
    string input3;
    while (getline(cin, input3))
    {
        if (input3 == "M")
        {

            board[board_row][board_column].set_isMarked(true);

            if (board[board_row + 1][board_column + 1].get_isMine() == false)
            {
                board[board_row + 1][board_column + 1].set_isMarked(true);
            }
            if (board[board_row + 1][board_column].get_isMine() == false)
            {
                board[board_row + 1][board_column].set_isMarked(true);
            }
            if (board[board_row][board_column + 1].get_isMine() == false)
            {
                board[board_row][board_column + 1].set_isMarked(true);
            }
            if (board[board_row - 1][board_column - 1].get_isMine() == false)
            {
                board[board_row - 1][board_column - 1].set_isMarked(true);
            }
            if (board[board_row - 1][board_column].get_isMine() == false)
            {
                board[board_row - 1][board_column].set_isMarked(true);
            }
            if (board[board_row][board_column - 1].get_isMine() == false)
            {
                board[board_row][board_column - 1].set_isMarked(true);
            }
            if (board[board_row + 1][board_column - 1].get_isMine() == false)
            {
                board[board_row + 1][board_column - 1].set_isMarked(true);
            }
            if (board[board_row - 1][board_column + 1].get_isMine() == false)
            {
                board[board_row - 1][board_column + 1].set_isMarked(true);
            }

            break;
        }
        if (input3 == "F")
        {
            board[board_row][board_column].set_isFlag(true);
            break;
        }
        else
        {
            cout << "Invalid input, please enter M or F: " << endl;
        }
    }
}

bool MineBoardHard::check_end_game_lose()
{
    bool flag = false;
    //LOSING THE GAME
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // Condition:
            if (board[i][j].get_isMine() == true && board[i][j].get_isMarked() == true)
            {
                flag = true;
                return true;
            }
        }
    }

    return false;
}

bool MineBoardHard::check_end_game_win()
{
    int mines = 0;
    int flags = 0;

    //WINNING THE GAME
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j].get_isMine() == true)
            {
                mines++;
            }
            if (board[i][j].get_isFlag() == true & board[i][j].get_isMine() == true)
            {
                flags++;
            }
        }
    }

    if (mines == flags)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MineBoardHard::run_minesweeper()
{
    create_board();
    create_integers();

    while (check_end_game_lose() == false && check_end_game_win() == false)
    {
        spawn_appearances();

        display_board();

        make_move();
    }
    if (check_end_game_lose() == true)
    {
        cout << "You lost, you selected a tile with a mine!" << endl;
    }
    if (check_end_game_win() == true)
    {
        cout << "You win, all mines are flagged!" << endl;
    }
}