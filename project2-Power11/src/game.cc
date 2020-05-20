#include "game.hh"

void Game::clearScreen()
{
        cout << string(50, '\n');
}

void Game::displayInfos()
{

        cout << "Score: " << pile.back().getScore() << endl;
}

int Game::getSize()
{
        return pile.back().getSize();
}

char Game::displayMenu()
{

        char key;
        do
        {

                cout << "* * * * MENU * * * *" << endl;
                cout << "* e start a new Easy (5-by-5) game" << endl;
                cout << "* h start a new Hard (4-by-4) game" << endl;
                cout << "* r Resume the last saved game" << endl;
                cout << "* q Quit the game" << endl;
                cout << "* * * Type your choice: ";

                cin >> key;

                if (key == 'e' or key == 'h' or key == 'r' or key == 'q')
                {
                        return key;
                }

        } while (true);
}

void Game::save()
{

        ofstream saved;
        saved.open("power11.saved");

        for (size_t i = 0; i < pile.size(); i++)
        {
                saved << "Score: " << pile[i].getScore() << endl;
                pile[i].saveGrid(saved);
        }

        saved.close();
}

void Game::undo()
{

        if (pile.size() > 1)
        {
                pile.pop_back();
        }
}

bool Game::play()
{

        if (gameIsOver()) // check if the resumed game is already over
                return true;

        Grid grid = pile.back();
        char cmd;
        Grid tmp;

        clearScreen();
        displayInfos();
        grid.display();
        cout << endl
             << "* NEXT MOVE: ";

        bool game = true;
        while (cin >> cmd && game == true)
        {

                clearScreen();
                grid = pile.back();
                tmp = grid;

                if (cmd == 's') // saving the game
                {
                        save();
                }
                else if (cmd == 'b') // undo the last move
                {

                        undo();
                        grid = pile.back();
                }
                else if (cmd == 'q') // quitting the game
                {
                        return false;
                }
                else
                {

                        if (cmd == 'u')
                        {
                                grid.moveUp();
                        }
                        else if (cmd == 'd')
                        {
                                grid.moveDown();
                        }
                        else if (cmd == 'l')
                        {
                                grid.moveLeft();
                        }
                        else if (cmd == 'r')
                        {
                                grid.moveRight();
                        }

                        Grid tmp = grid;

                        if (gridChanged(tmp)) // Saving the new state if its changed
                        {
                                grid.placeAtRandomPosition();
                                pile.push_back(grid);
                        }
                }

                if (gameIsOver())
                        game = false;

                displayInfos();
                grid.display();

                cout << endl
                     << "* NEXT MOVE: ";
        }

        return true;
}

bool Game::gridChanged(Grid tmp)
{

        Grid grid = pile.back();
        int size = getSize();
        for (int i = 0; i < size; i++)
        {
                for (int j = 0; j < size; j++)
                {
                        if (grid(i, j) != tmp(i, j))
                        {
                                return true;
                        }
                }
        }
        return false;
}

void Game::start()
{
        pile.back().placeAtRandomPosition();
        pile.back().placeAtRandomPosition();
}

vector<string> SavedToVector()
{

        ifstream saved;
        saved.open("power11.saved");

        vector<string> vec;
        string line;
        while (std::getline(saved, line))
        {
                vec.push_back(line);
        }

        return vec;
}

bool Game::resume()
{

        vector<string> vec = SavedToVector(); // Puts power11.saved lines into the vector
        vector<Grid> saved_pile;

        if (vec.size() < 5)
        {
                cout << "No game to be resumed!" << endl;
                return false;
        }

        int size = (vec[1].length() - 1) / 5;  // Grid's size is relative to a line's length
        int gridsNb = vec.size() / (size + 3); // number of states from the saved game

        for (int g = 0; g < gridsNb; g++)
        {

                vector<vector<int>> array;
                // initiating the array
                array.resize(size);
                for (int i = 0; i < size; ++i)
                        array[i].resize(size);

                string score_line = vec[(size + 3) * g];                           // Reading the score line
                int score = atoi(score_line.substr(6, score_line.size()).c_str()); // Extracting the score from the line

                for (int i = 0; i < size; i++)
                {
                        int indice = (size + 3) * g + i + 2; // mapping from the i position in a grid to the line number

                        string line = vec[indice];

                        int j = 0;

                        string buf;

                        for (size_t k = 1; k < line.length(); k++)
                        {

                                if (line[k] != '|' and line[k] != '#')
                                {
                                        buf += line[k];
                                }
                                else
                                {
                                        array[i][j] = atoi(buf.c_str());

                                        buf = "";
                                        j++;
                                }
                        }
                }

                Grid new_grid;
                new_grid.setArray(array);
                new_grid.setScore(score);
                new_grid.setSize(size);

                saved_pile.push_back(new_grid); // pushing the grid to the pile of game states
        }

        pile = saved_pile;

        return true;
}

bool Game::gameIsOver()
{

        Grid grid = pile.back();
        if (grid.power11Exists())
        {

                displayInfos();
                grid.display();
                cout << "YOU WON WITH A SCORE OF " << grid.getScore() << endl;
                return true;
        }
        else
        {
                Grid tmp = grid;
                bool changed = false;

                // check if the grid will change with a possible move :
                tmp.moveUp();
                if (gridChanged(tmp))
                        changed = true;

                tmp.moveDown();
                if (gridChanged(tmp))
                        changed = true;

                tmp.moveLeft();
                if (gridChanged(tmp))
                        changed = true;

                tmp.moveRight();
                if (gridChanged(tmp))
                        changed = true;

                if (changed == false)
                {
                        displayInfos();
                        grid.display();
                        cout << "YOU LOST!" << endl;
                        return true;
                }
                return false;
        }
}