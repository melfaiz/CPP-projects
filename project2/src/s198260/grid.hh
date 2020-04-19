#ifndef GRID_HH
#define GRID_HH

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


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



    int getSize(){
        return size;
    }
    
    int getScore(){
        return score;
    }

    void display();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void saveGrid(ofstream& file);

    
    void placeAtRandomPosition();
    

    void setScore(int s){
        score = s;
    }
    void setArray(vector<vector<int>> new_array){
        array = new_array;
    }

    void setSize(int s){
        size = s;
    }

    bool isFull(){
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if(array[i][j] == 0)
                    return false;
        return true;
    }

    bool power11Exists(){

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if(array[i][j] == 2048)
                    return true;
    
        return false;
    }


private:
    int size;
    int score;
    vector<vector<int>> array;

    bool isInside(int i,int j);

};



#endif