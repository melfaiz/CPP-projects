#include "game.hh"


int main()
{
    srand((unsigned) time(0));
    char menu;

    while (true)
    {
        menu = Game::displayMenu();
        

        if (menu == 'e' or menu == 'h')
        {
            Game new_game = Game(menu);
            new_game.start();
            new_game.play();

        }else if(menu == 'r'){
            
            Game resumed_game = Game();
            resumed_game.resume();
            resumed_game.play();

        }else if (menu == 'q')
        {
            return 0;
        }

        
        
    }  



}