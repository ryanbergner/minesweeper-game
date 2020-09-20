#include "minesweeper.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;


// THIS MUST BE COMPILED WITH C++ 11

// g++ -std=c++11 minesweeper.cpp minesweeperDriver.cpp -o drivex

int main()
{
    cout << "----------------------" << endl;
    cout << "WELCOME TO MINESWEEPER" << endl;
    cout << "----------------------" << endl;

    // Make object either MineBoardEasy, MineBoardMedium, and MineBoard Hard to change difficulty

    MineBoardHard game1;

    auto start = chrono::steady_clock::now();

    game1.run_minesweeper();

    auto stop = chrono::steady_clock::now();

    auto time_elapsed = chrono::duration_cast<chrono::seconds>(stop - start).count();

    if (game1.check_end_game_win() == true)
    {
        ifstream in_file;
        in_file.open("Leaderboard.txt");
        string input_line;
        long time;

        vector<long long> vector1;

        while (getline(in_file, input_line))
        {
            istringstream is(input_line);
            is >> time;
            int time_int = (int)time;
            vector1.push_back(time_int);
        }

        int newtime = (int)time_elapsed;

        vector1.push_back(time_elapsed);

        sort(vector1.begin(), vector1.end());

        ofstream out_file;
        out_file.open("Leaderboard.txt");
        if (out_file.fail())
        {
            return -1;
        }

        out_file << "Leaderboard" << endl;
        for (int i = 0; i < vector1.size(); i++)
        {
            out_file << i << " " << vector1[i] << endl;
        }

        out_file.close();

        cout << "Your time to complete the game was: " << newtime << endl;
    }


    return 0;

}