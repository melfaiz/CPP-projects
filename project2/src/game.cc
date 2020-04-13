#include "game.hh"
#include "common.hh"

void Game::displayInfos(){

        cout << "Score: " << pile.back().getScore() << endl;

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

        for(size_t i = 0 ; i < pile.size() ; i++ ){
                saved << "Score: " << pile[i].getScore() << endl;
                pile[i].saveGrid(saved);
        }      

        saved.close();
  

}

void Game::undo(){

        if (pile.size() > 1)
        {
                pile.pop_back();
        }        

}


void Game::play(){

        Grid grid = pile.back();
    
        char cmd;
        clearScreen();
        displayInfos();                        
        grid.display();
        cout << "NEXT MOVE: ";
        Grid tmp;
        while (cin >> cmd)
        {

                clearScreen();
                grid = pile.back();
                tmp = grid;

                if (cmd == 's')
                {       
                        save();                        
                        
                }else if(cmd == 'b'){
                        
                        undo();
                        grid = pile.back();
                        
                        
                }else{

                        if (cmd == 'u')
                        {  
                        grid.moveUp();
                        
                        }else if(cmd == 'd'){
                        grid.moveDown();
                        
                        }else if(cmd == 'l'){
                        grid.moveLeft();

                        }else if(cmd == 'r'){
                        grid.moveRight();
                        
                        
                        }

                        Grid tmp = grid;

                        if (gridChanged(tmp))
                        {
                                grid.placeAtRandomPosition();
                                pile.push_back(grid);
                        }
             
                }


                


                
                
                displayInfos();                        
                grid.display();
                cout << "NEXT MOVE: ";                      

                
                
                


        }

        cout << endl << endl;;

    
}


vector<string> SavedToVector(){

        ifstream saved;
        saved.open ("power11.saved");  

        vector<string> vec;
        string line;
        while(std::getline(saved, line)){
                vec.push_back(line);
        }

        return vec;
}


void Game::resume(){

        vector<string> vec = SavedToVector();
        vector<Grid> saved_pile;
        

        int size = ( vec[1].length() - 1 ) / 5;    
        int gridsNb = vec.size() / ( size + 3) ;     

        cout << "size: " << size << ", nb: " << gridsNb << endl;                
        
        for (int g = 0; g < gridsNb; g++)
        {       

                vector<vector<int>> array;

                array.resize(size);
                for (int i = 0; i < size; ++i)
                        array[i].resize(size);

                
                string score_line = vec[(size+3)*g];                
                string score_str = score_line.substr (6,score_line.size());                          
                int score = atoi(score_str.c_str());

               
                

                

                for (size_t i = 0; i < 4; i++)
                {       
                        int indice = (size+3)*g + i + 2;
                     
                        string line = vec[indice];
                        
                        int j = 0;

                        string buf;

                        for (size_t k = 1;k < line.length(); k++)
                        {   
                        
                        
                                if (line[k] != '|' and line[k] != '#')
                                {
                                        buf += line[k];
                                        
                                }else{
                                        array[i][j] = atoi(buf.c_str());
                                                                              
                                        buf = "";
                                        j++;
                                }
                        
                        }cout << endl;

                        
                }

                
                Grid ngrid;
                ngrid.setArray(array);
                ngrid.setScore(score);
                ngrid.setSize(size);
                

                saved_pile.push_back(ngrid);
        }

        pile = saved_pile;
        
}