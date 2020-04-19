#include "grid.hh"

int random2or4(){
    double r = ((double) rand() / (RAND_MAX));
    if (r < 0.9)
    {
        return 2;
    }else{
        return 4;
    }
    
}

int random_index(int size){
    return rand() % size;
    
}
string formatCase(int n){

    if (n)
    {
        std::stringstream ss;
        ss << std::setw(4) << std::setfill(' ') << n;
        std::string s = ss.str();
        return s;
    }
    return "    ";
    

}

void Grid::display(){

    for (int i = 0; i < 5 * size + 1; i++)
    {
        cout << "#" ;
    }
    cout << endl;
    

    for (int i = 0; i < size; i++)
    {
        cout << "#";

        for (int j = 0; j < size; j++)
        {
            
            cout <<  formatCase(array[i][j]) ;

            if (j != size-1)
                cout << "|";
           
        }

        cout << "#" << endl;
        
    }
    
    for (int i = 0; i < 5 * size + 1; i++)
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

        if (array[line][column] == 0)
        {
            occupied = 0;
            array[line][column] = random2or4();

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

            int flag = 1;

            for(int k=j+1;k<size;k++){

                if (array[k][i] && flag == 1)
                {
                    if(array[j][i]==array[k][i])
                    {
            
                        array[j][i]+=array[k][i];
                        score += array[j][i];
                        array[k][i]=0;
                
                    }

                    flag = 0;
                }
                

                
                }
        }
    }

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
            {
                if(!array[j][i])
                {
                    for(int k=j+1;k<size;k++)
                        if(array[k][i])
                        {
                            array[j][i]=array[k][i];
                            array[k][i]=0;
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
            int flag = 1;


            for(int k=j-1;k>=0;k--){

                if (array[k][i] && flag == 1)
                {
                    if(array[j][i]&&array[j][i]==array[k][i])
                    {
                    
                        array[j][i] += array[k][i];
                        score += array[j][i];
                        array[k][i]=0;

                    }

                    flag = 0;

                }
                

                
                }
        }


    for(int i=0;i<size;i++){
            for(int j=size-1;j>=0;j--)
            {
                if(!array[j][i])
                {
                    for(int k=j-1;k>=0;k--)
                        if(array[k][i])
                        {
                            array[j][i]=array[k][i];
                            array[k][i]=0;
                            break;
                        }
                }

            }
    }
}

void Grid::moveLeft(){
    
        //  on somme
        int flag = 1;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
            {
                flag = 1;
                for(int k=j+1;k<size;k++){

                    if (array[i][k] && flag == 1)
                    {
                        /* code */
                   
                    
                        if(array[i][j] == array[i][k])
                        {
                           
                            array[i][j]+=array[i][k];
                            score += array[i][j];
                            array[i][k]=0;
                            
                        }

                        flag = 0;
                    
                    
                    }
                }
            }
        }

    // on justifie

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
        {
            if(!array[i][j])
            {
                for(int k=j+1;k<size;k++)
                    if(array[i][k])
                    {
                        array[i][j]=array[i][k];
                        array[i][k]=0;
                        break;
                    }
            }

        }
    }

 
}

void Grid::moveRight(){

    
    for(int i=0;i<size;i++){
        for(int j=size-1;j>0;j--)
        {
            int flag = 1;

            for(int k=j-1;k>=0;k--){

                if (array[i][k] && flag == 1)
                {
                    if(array[i][k] &&array[i][j]==array[i][k])
                    {
                        
                        array[i][j]+=array[i][k];
                        score += array[i][j];
                        array[i][k]=0;

                    }
                    flag = 0;
                
                }
        }
    }
    }

    for(int i=0;i<size;i++){
        for(int j=size-1;j>=0;j--)
        {
            if(!array[i][j])
            {
                for(int k=j-1;k>=0;k--)
                    if(array[i][k])
                    {
                        array[i][j]=array[i][k];
                        array[i][k]=0;
                        break;
                    }
            }

        }

    }

}


void Grid::saveGrid(ofstream& cout){
    for (int i = 0; i < 5 * size + 1; i++)
    {
        cout << "#" ;
    }
    cout << endl;
    

    for (int i = 0; i < size; i++)
    {
        cout << "#";

        for (int j = 0; j < size; j++)
        {
            
            cout <<  formatCase(array[i][j]) ;

            if (j != size-1)
                cout << "|";
           
        }

        cout << "#" << endl;
        
    }
    
    for (int i = 0; i < 5 * size + 1; i++)
    {
        cout << "#" ;
    }
    cout << endl;

}

