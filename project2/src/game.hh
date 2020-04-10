#ifndef GAME_HH
#define GAME_HH

#include "grid.hh"

char diplayMenu();

using namespace std;



class Game {

public:

    Game(char m){
    
        if (m == 'e'){
            this->level = "easy";
            Grid new_grid(5);
            this->grid = new_grid;
        }else
        {   
            this->level = "hard";
            Grid new_grid(4);
            this->grid = new_grid;
        }
        
        this->score = 0;
    
    }

    int getScore(){
        return score;
    }

    void save(){
        cout << "GAME SAVED " << endl;
    }

    void resume(){
        cout << "RESUMING LAST GAME " << endl;
    }

    int getSize(){
        return grid.getSize();
    }

    void play();
    void displayInfos();
    int direction(char cmd);
    void backupGrid(){
        lastGrid = grid;
    }
    
    bool compareGrid(){
        bool flag = true;
        int size = grid.getSize();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; i < size; j++)
            {
                if (grid(i,j) != lastGrid(i,j))
                {
                    return false;
                }
                
            }
            
        }
        return flag;
        
    }
    



private:
    int score;
    string level;
    Grid grid;
    Grid lastGrid;
       

};

#endif