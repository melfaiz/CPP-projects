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

char displayMenu()
{

    char key;
    do
    {
        clearScreen();
        
        cout << "  ** MENU **" << endl;
        cout << "  e start a new Easy (5-by-5) game" << endl;
        cout << "  h start a new Hard (4-by-4) game" << endl;
        cout << "  r Resume the last saved game" << endl;
        cout << "  q Quit the game" << endl << endl;

        cout << "  Rentrez votre choix: " ;

        cin >> key;

        if (key == 'e' or key == 'h' or key == 'r' or key == 'q')
        {
            return key;
        }
        

    } while (true);

}