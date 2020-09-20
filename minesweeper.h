#include <string>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;


class Place
{
private:
    bool marked = false;
    bool isMine = false;
    bool isFlag = false;
    int minesnearby = 0;
    string appearance = "-";

public:
    Place();

    void set_isMarked(bool tf);
    void set_isMine(bool tf);
    void set_isFlag(bool tf);
    void set_appearance(string s);

    bool get_isMarked();
    bool get_isMine();
    bool get_isFlag();
    string get_appearance();

    void add_minesnearby();

    int get_minesnearby();
};

//-------------------------------------------

class MineBoardEasy
{
private:

    int rows = 6;
    int columns = 6;

    Place board[6][6];

public:
    

    MineBoardEasy();
    //MAKE THIS SO YOU CAN MAKE A GRID OF PLACES

    void create_board();

    void create_integers();

    void spawn_appearances();

    void display_board();

    void make_move();

    bool check_end_game_win();
    bool check_end_game_lose();

    void run_minesweeper();

};

//-------------------------------------------

class MineBoardMedium
{
private:
    int rows = 8;
    int columns = 8;

    Place board[8][8];

public:
    MineBoardMedium();
    //MAKE THIS SO YOU CAN MAKE A GRID OF PLACES

    void create_board();

    void create_integers();

    void spawn_appearances();

    void display_board();

    void make_move();

    bool check_end_game_win();
    bool check_end_game_lose();

    void run_minesweeper();

};

//-------------------------------------------

class MineBoardHard
{
private:
    int rows = 10;
    int columns = 10;

    Place board[10][10];

public:
    MineBoardHard();
    //MAKE THIS SO YOU CAN MAKE A GRID OF PLACES

    void create_board();

    void create_integers();

    void spawn_appearances();

    void display_board();

    void make_move();

    bool check_end_game_win();
    bool check_end_game_lose();

    void run_minesweeper();

};
