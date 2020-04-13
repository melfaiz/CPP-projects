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





    void save();
    void undo();
    void resume();

    int getSize(){
        return pile.back().getSize();
    }

    void start(){
        pile.back().placeAtRandomPosition();
        pile.back().placeAtRandomPosition();
    }
    void play();
    void displayInfos();
    int direction(char cmd);

    // void backupGrid(){
    //     lastGrid = grid;
    // }
    
    bool gridChanged(Grid tmp){

        if (pile.size() < 2)
        {
            return true;
        }else{

            
            Grid grid = pile.back();
            Grid lastGrid = pile[pile.size() - 2] ;
            int size = grid.getSize();
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (grid(i,j) != tmp(i,j) )
                    {
                        return true;

                    }
                    
                }
                
            }
            return false;

        }
        

        
    }
    


    static char displayMenu();


private:

    string info;
    vector<Grid> pile;

};

#endif