#ifndef GRID_HH
#define GRID_HH

#include "common.hh"

class Grid {

public:


    Grid() = default;
    Grid(int s){


        size = s;
        score = 0;
        grid.resize(size);
        for (int i = 0; i < size; ++i)
            grid[i].resize(size);

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                grid[i][j] = 0 ;


    }
    
    int operator () (int i,int j) { 
            return grid[i][j]; 
    } 

    void placeAtRandomPosition();

    int getSize(){
        return size;
    }
    
    int getScore(){
        return score;
    }

    void display();

    void saveGrid(ofstream& file);

    void test(){
        grid = 
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,8,4,2,2},
        };
    };
    
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    bool isInside(int i,int j);

private:
    int size;
    int score;
    vector<vector<int>> grid;
    
};



#endif