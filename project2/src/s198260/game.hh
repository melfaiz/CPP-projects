#ifndef GAME_HH
#define GAME_HH

#include "grid.hh"

using namespace std;

class Game
{

public:
    Game() = default;

    Game(char m)
    {

        if (m == 'e')
        {
            Grid new_grid = Grid(5);
            pile.push_back(new_grid);
        }
        else
        {
            Grid new_grid = Grid(4);
            pile.push_back(new_grid);
        }
    }

    bool resume();
    void start();
    bool play();
    
    static char displayMenu();
    static void clearScreen();

private:
    int direction(char cmd);
    int getSize();
    void displayInfos();
    bool gridChanged(Grid tmp);
    void save();
    void undo();
    bool gameIsOver();

    vector<Grid> pile; // All the game states
};

#endif