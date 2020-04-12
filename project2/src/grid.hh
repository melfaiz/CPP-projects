#ifndef GRID_HH
#define GRID_HH

#include "common.hh"

class Grid {

public:


    Grid(){

        ifstream saved;
        saved.open ("power11.saved");  
        
        string line;
        
        cout << "zero :" << atoi("  ") << endl;
        size = 5;

        int line_i = 0;
        int i=0;
        while(std::getline(saved, line) && line_i< size + 2){
            istringstream buf(line);
            
            if (line_i==0)
            {
                line = line.substr (6,line.size());                          
                score = atoi(line.c_str());
                // cout <<  score << endl;  
            }else if (line_i==1)
            {
                size = ( line.length() - 1 ) / 5;
                // cout <<  size << endl;   

                grid.resize(size);
                for (int i = 0; i < size; ++i)
                    grid[i].resize(size);

            }else{
                    
                    



                    int j = 0;
                    string buf;
                    for (size_t k = 1;k < line.length(); k++)
                    {   
                        
                        
                        if (line[k] != '|' and line[k] != '#')
                        {
                            buf += line[k];
                           
                        }else{
                            grid[i][j] = atoi(buf.c_str());
                            cout << i << j <<  ":" << buf << ",";
                            buf = "";
                            j++;
                        }
                        
                    }
                    cout << endl;
                    i++;
                     
            }
            
            line_i++;

        }
        
        saved.close();
        

            

        
    };

    Grid(int s){


        size = s;
        score = 0;
        grid.resize(size);
        for (int i = 0; i < size; ++i)
            grid[i].resize(size);

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                grid[i][j] = 0 ;

        this->placeAtRandomPosition();


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