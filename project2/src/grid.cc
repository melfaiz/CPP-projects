#include "grid.hh"
#include "common.hh"

string formatCase(int n){
    std::stringstream ss;
    ss << std::setw(4) << std::setfill(' ') << n;
    std::string s = ss.str();
    return s;
}

void Grid::display(){

    for (int i = 0; i < 5 * this->size + 1; i++)
    {
        cout << "#" ;
    }
    cout << endl;
    

    for (int i = 0; i < this->size; i++)
    {
        cout << "#";

        for (int j = 0; j < this->size; j++)
        {
            
            cout <<  formatCase(this->grid[i][j]) ;

            if (j != size-1)
                cout << "|";
           
        }

        cout << "#" << endl;
        
    }
    
    for (int i = 0; i < 5 * this->size + 1; i++)
    {
        cout << "#" ;
    }
    cout << endl;
    
}

void Grid::placeAtRandomPosition(){

    int occupied = 1;
    int line;
    int column;

    while (occupied)
    {
        line = random_index(size); 
        column = random_index(size);

        if (grid[line][column] == 0)
        {
            occupied = 0;
            grid[line][column] = random2or4();
        }
        
    }
    
}

bool Grid::isInside(int i,int j){
    if (i>=0 && j>=0 && j<size && i<size)
    {
        return true;
    }else{
        return false;
    }
}

void Grid::moveUp(){

    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++)
        {
            for(int k=j+1;k<size;k++){
                if(grid[k][i] && grid[j][i]==grid[k][i])
                {
        
                    grid[j][i]+=grid[k][i];
                    grid[k][i]=0;
            
                    break;
                }
                
                }
        }
    }

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
            {
                if(!grid[j][i])
                {
                    for(int k=j+1;k<size;k++)
                        if(grid[k][i])
                        {
                            grid[j][i]=grid[k][i];
                            grid[k][i]=0;
                            break;
                        }
                }

            }
    }
}

void Grid::moveDown(){

    for(int i=0;i<size;i++)
        for(int j=size-1;j>0;j--)
        {
            for(int k=j-1;k>=0;k--){
                if(grid[j][i]&&grid[j][i]==grid[k][i])
                {
                
                    grid[j][i] += grid[k][i];
                    grid[k][i]=0;
                    
        break;
                }
                
                }
        }


    for(int i=0;i<size;i++){
            for(int j=size-1;j>=0;j--)
            {
                if(!grid[j][i])
                {
                    for(int k=j-1;k>=0;k--)
                        if(grid[k][i])
                        {
                            grid[j][i]=grid[k][i];
                            grid[k][i]=0;
                            break;
                        }
                }

            }
    }
}

void Grid::moveLeft(){
    
        //  on somme
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
            {
                for(int k=j+1;k<size;k++){

                    // cout << "here " << i <<j << k << endl;
                    if( grid[i][k] && grid[i][j] == grid[i][k])
                    {
                        
                        grid[i][j]+=grid[i][k];
                        grid[i][k]=0;
                        
                        break;
                    }
                    
                }
            }
        }

    // on justifie

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
        {
            if(!grid[i][j])
            {
                for(int k=j+1;k<size;k++)
                    if(grid[i][k])
                    {
                        grid[i][j]=grid[i][k];
                        grid[i][k]=0;
                        break;
                    }
            }

        }
    }

 
}

void Grid::moveRight(){

    for(int i=0;i<size;i++)
        for(int j=size-1;j>0;j--)
        {
            for(int k=j-1;k>=0;k--){
                if(grid[i][k] &&grid[i][j]==grid[i][k])
                {
                    
                    grid[i][j]+=grid[i][k];
                    grid[i][k]=0;
                    
break;
                }
                
                }
        }

    for(int i=0;i<size;i++)
        for(int j=size-1;j>=0;j--)
        {
            if(!grid[i][j])
            {
                for(int k=j-1;k>=0;k--)
                    if(grid[i][k])
                    {
                        grid[i][j]=grid[i][k];
                        grid[i][k]=0;
                        break;
                    }
            }

        }

}