#ifndef GRID_HH
#define GRID_HH

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

class Grid
{

public:
    Grid() = default;

    Grid(int s)
    {

        size = s;
        score = 0;
        array.resize(size);
        for (int i = 0; i < size; ++i)
            array[i].resize(size);

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                array[i][j] = 0;
    }



    int getSize()
    {
        return size;
    }

    int getScore()
    {
        return score;
    }
    
    void setScore(int s)
    {
        score = s;
    }
    void setArray(vector<vector<int>> new_array)
    {
        array = new_array;
    }

    void setSize(int s)
    {
        size = s;
    }

    void display(); // Display the grid
    void moveUp(); 
    void moveDown();
    void moveLeft();
    void moveRight();
    void saveGrid(ofstream &file); // Write the grid into the ofstream

    int operator()(int i, int j);

    void placeAtRandomPosition(); // Placing either a 4 or a 2 in an empty cases in the grid

    bool power11Exists(); // Search if the number 2048 is present on the grid
    

private:
    int size;
    int score;
    vector<vector<int>> array; // Grid's actual array

    bool isInside(int i, int j); 
};

#endif