#include "common.hh"

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

void clearScreen()
{
    cout << string(50, '\n');
}

