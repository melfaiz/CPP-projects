#include "game.hh"
#include "common.hh"

void Game::displayInfos(){

        cout << "SCORE: " << score << endl;
        cout << "LEVEL: " << level << endl;
        cout << "SIZE: " << getSize() << endl << endl;
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

void Game::play(){

    
        char cmd;
        // grid.test();
        do
        {
                
                clearScreen();
                displayInfos();


                if (cmd == 'u')
                {   grid.moveUp();
                }else if(cmd == 'd'){
                    grid.moveDown();
                }else if(cmd == 'l'){
                    grid.moveLeft();
                }else if(cmd == 'r'){
                    grid.moveRight();
                }
                
                                
                
                grid.placeAtRandomPosition();
                grid.display();
                
                // if (!compareGrid())
                

                // backupGrid();
                cout << "NEXT MOVE: ";

        } while (cin >> cmd);

        cout << endl << endl;;

    
}