#include "game.hh"
#include "common.hh"


int main()
{
    srand((unsigned) time(0));

    char menu = Game::displayMenu();
    

    if (menu == 'e' or menu == 'h')
    {
        Game new_game = Game(menu);
        new_game.play();

    }else if(menu == 'r'){
        Game resumed_game = Game();
        resumed_game.play();
    }
    
    



}