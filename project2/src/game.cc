#include "game.hh"
#include "common.hh"

void Game::displayInfos(){

        cout << "Score: " << grid.getScore() << endl;

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
        saved.open ("power11.saved");  

        for(size_t i = pile.size() ; i-- ;){
                saved << "Score: " << pile[i].getScore() << endl;
                pile[i].saveGrid(saved);
        }      

        saved.close();
        cout << "* * * * * * * GAME SAVED * * * * * * *" << endl;
   

}

void Game::undo(){

}

void Game::resume(){



}


void Game::play(){

    
        char cmd;
        do
        {
                
                clearScreen();
                
                if (cmd == 's')
                {
                        save();                        
                        
                }else if(cmd == 'b'){
                        
                        undo();
                        
                }else{

                        if (cmd == 'u')
                        {  
                        grid.moveUp();
                        grid.placeAtRandomPosition();
                        }else if(cmd == 'd'){
                        grid.moveDown();
                        grid.placeAtRandomPosition();
                        }else if(cmd == 'l'){
                        grid.moveLeft();
                        grid.placeAtRandomPosition();
                        }else if(cmd == 'r'){
                        grid.moveRight();
                        grid.placeAtRandomPosition();
                        }
                        
                        pile.push_back(grid);
                }
                        
                        
                        
                                        
                        displayInfos();                        
                        grid.display();
                        cout << "NEXT MOVE: ";

                
                
                


        } while (cin >> cmd);

        cout << endl << endl;;

    
}