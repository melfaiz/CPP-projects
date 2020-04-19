#ifndef GAME_HH
#define GAME_HH

#include "grid.hh"

char diplayMenu();

using namespace std;



class Game {

public:

    Game() = default;

    Game(char m){
        
        if (m == 'e'){
            Grid new_grid = Grid(5);
            pile.push_back(new_grid);
            
        }else
        {   
            Grid new_grid = Grid(4);
            pile.push_back(new_grid);
        }

    
    }


    void resume();
    void start();
    int play();
    static char displayMenu();


private:

    int direction(char cmd);
    int getSize(){
        return pile.back().getSize();
    }
    void displayInfos();
    bool gridChanged(Grid tmp);
    void save();
    void undo();

    vector<Grid> pile;

};

#endif