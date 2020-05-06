#include "game.hh"

int main()
{
    srand((unsigned)time(0));
    char menu;

    while (true)
    {

        menu = Game::displayMenu();

        Game new_game = Game(menu);

        if (menu == 'e' or menu == 'h')
        {

            new_game.start();
            new_game.play();
        }
        else if (menu == 'r')
        {

            if (new_game.resume()) // If a saved game is present in power11.saved
            {
                new_game.play();
            }
        }
        else if (menu == 'q')
        {
            return 0;
        }
    }
}