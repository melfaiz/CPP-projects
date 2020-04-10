#include "game.hh"
#include "common.hh"

void Game::displayInfos(){

        cout << "SCORE: " << grid.getScore() << endl;
        cout << "LEVEL: " << level << endl;
        cout << "SIZE: " << Game::getSize() << endl << endl;
}

int Game::direction(char cmd){
        switch (cmd)
        {
        case 'u':
                return 0;
                break;
        case 'd':
                return 1;
                break;
        case 'l':
                return 2;
                break;
        case 'r':
                return 3;
                break;             

        default:
                return -1;
                break;
        }
}

char Game::displayMenu()
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

void Game::save(){
    
        ofstream saved;
        saved.open ("power11.saved", ofstream::app);        
        saved << "Score: " << grid.getScore() << endl;
        grid.saveGrid(saved);
        saved.close();
   

}
void Game::play(){

    
        char cmd;
        // grid.test();
        grid.placeAtRandomPosition();
        do
        {
                
                clearScreen();
                
                if (cmd == 'u')
                {   grid.moveUp();
                }else if(cmd == 'd'){
                    grid.moveDown();
                }else if(cmd == 'l'){
                    grid.moveLeft();
                }else if(cmd == 'r'){
                    grid.moveRight();
                }

                
                
                
                
                                
                displayInfos();
                grid.placeAtRandomPosition();
                save();
                grid.display();
                
                // if (!compareGrid())
                

                // backupGrid();
                cout << "NEXT MOVE: ";

        } while (cin >> cmd);

        cout << endl << endl;;

    
}