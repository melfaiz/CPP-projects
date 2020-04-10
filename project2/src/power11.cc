#include "game.hh"
#include "common.hh"


int main()
{
    srand((unsigned) time(0));

    char menu = Game::displayMenu();

    

    if (menu == 'e' or menu == 'h')
    {
        Game new_game(menu);
        new_game.play();

    }else if(menu == 'r'){
        // resume game
    }else{
        return true;
    }
    
    



}