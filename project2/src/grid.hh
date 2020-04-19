#ifndef GRID_HH
#define GRID_HH

#include "common.hh"

class Grid {

public:

    Grid() = default;
    
    Grid(int s){


        size = s;
        score = 0;
        array.resize(size);
        for (int i = 0; i < size; ++i)
            array[i].resize(size);

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                array[i][j] = 0 ;

        


    }
    
    int operator () (int i,int j) { 
            return array[i][j]; 
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

    
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    bool isInside(int i,int j);

    void setScore(int s){
        score = s;
    }
    void setArray(vector<vector<int>> new_array){
        array = new_array;
    }

    void setSize(int s){
        size = s;
    }


private:
    int size;
    int score;
    vector<vector<int>> array;
    
};



#endif