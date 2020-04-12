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
            grid = new_grid;
            
        }else
        {   
            Grid new_grid = Grid(4);
            grid = new_grid;
        }
        
     
    
    }





    void save();
    void undo();
    void resume();

    int getSize(){
        return grid.getSize();
    }

    void play();
    void displayInfos();
    int direction(char cmd);

    // void backupGrid(){
    //     lastGrid = grid;
    // }
    
    // bool compareGrid(){
    //     bool flag = true;
    //     int size = grid.getSize();
    //     for (int i = 0; i < size; i++)
    //     {
    //         for (int j = 0; i < size; j++)
    //         {
    //             if (grid(i,j) != lastGrid(i,j))
    //             {
    //                 return false;
    //             }
                
    //         }
            
    //     }
    //     return flag;
        
    // }
    


    static char displayMenu();


private:

    Grid grid;
    vector<Grid> pile;

};

#endif