#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


#include "belote.hh"

#define CARDS_NB 10

using namespace std;

typedef struct card{
    char trump;
    char rank;
} card_t;


const int P_SCORES [CARDS_NB] = {0,0,0,10,2,3,4,11};
const int T_SCORES [CARDS_NB] = {0,0,14,10,20,3,4,10};

char game_trump;
int contract_team;

int next_player = 0;
int score[2] = {0,0};
int bonus[2] = {0,0};
int has_belote[4] = {0,0,0,0};

vector< vector<char> > errors(4);
vector< vector<card_t> > trump_cards(4);

bool capot_1 = true;
bool capot_2 = true;
bool belote_1 = false;
bool belote_2 = false;



char get_rank(string card){
    return card[0];
}

char get_trump(string card){
    return card[1];
}

vector<card_t> get_trick(string line){

    vector<card_t> trick;
    istringstream buf(line);
    for(string word; buf >> word; ){

        card_t card;

        int len = word.size();

        card.trump = word[len-1];

        if (word.substr (0,len-1) == "10")
        {
            card.rank = 'T';
        }else{
            card.rank = word[0];
        }
        

        trick.push_back(card);
    }
    return trick;

}


int card_score(card_t card,char game_trump){

    int s = 0;

    if (card.trump == game_trump)
    {
        if (card.rank == '7')
        {
            s = 0;
        }else if(card.rank == '8'){
            s = 0;
        }else if(card.rank == '9'){
            s = 14;
        }else if(card.rank == 'T'){
            s = 10;
        }else if(card.rank == 'J'){
            s = 20;
        }else if(card.rank == 'Q'){
            s = 3;
        }else if(card.rank == 'K'){
            s = 4;
        }else if(card.rank == 'A'){
            s = 11;
        }
    }else{
        if (card.rank == '7')
        {
            s = 0;
        }else if(card.rank == '8'){
            s = 0;
        }else if(card.rank == '9'){
            s = 0;
        }else if(card.rank == 'T'){
            s = 10;
        }else if(card.rank == 'J'){
            s = 2;
        }else if(card.rank == 'Q'){
            s = 3;
        }else if(card.rank == 'K'){
            s = 4;
        }else if(card.rank == 'A'){
            s = 11;
        }
    }

    
    return s;
    
}

int write_score(std::ostream& out){

    out << score[0] + bonus[0] << " " << score[1] + bonus[1] << " " << next_player + 1 << endl;

    return 0;
}






int player_i(int i){
    return (next_player + i ) %4 ; // 0-1-2-3
}

int team_i(int i){
    return   i%2 ; // 0-1
}

bool higher_than(card_t card1, card_t card2){

    if (card_score(card1, game_trump) > card_score(card2, game_trump))
    {
        return true;

    }else if( card_score(card1, game_trump) == card_score(card2, game_trump)){

        if ( card1.rank > card2.rank )
        {
            return true;
        }else
        {
            return false;
        }
        
        

    }else{
        return false;
    }
    

}



int set_score(vector<card_t> trick,std::ostream& err){

    int temp_score_1=0; // sum of card scores played by team 1
    int temp_score_2=0; // sum of card scores played by team 2
    int temp_next_player=0; // index of winning player in the current trick

    char trick_suit = trick[0].trump; // current color

    int has_trump =0;        
    int max_has_trump = -1; 
    int max_score_trump = -1;


    for (size_t i = 0; i < trick.size(); i++)
    {
        int player = player_i(i); // current player in trick, players are 0-1-2-3
        int team = team_i(player_i(i)); // current team playing, teams are 0-1

        int s = card_score(trick[i], game_trump); // score of current card in trick

        // cout << trick[i].rank << trick[i].trump << " " << s << " p" << player+1 << " , " ;

        if (team == 0)
        {
            temp_score_1 += s;
        }else{
            temp_score_2 += s;
        }


        if (trick[i].trump == game_trump ) // played color is the game trump
        {
           
            has_trump+=1;          

            if ( card_score(trick[i], game_trump) > max_score_trump)
            {
                max_score_trump = card_score(trick[i], game_trump);
                max_has_trump = i;

                
            }else if (card_score(trick[i], game_trump) == max_score_trump)
            {
                if ( trick[i].rank == '8')
                {
                  
                    max_score_trump = card_score(trick[i], game_trump);
                    max_has_trump = i;
                }
                
            }
            

            // check for belote-rebelote
            if ( trick[i].rank == 'K')
            {
    
                has_belote[player] = has_belote[player] + 1;
            }
            if ( trick[i].rank == 'Q')
            {
                
                has_belote[player] +=1;
            }
            if ( has_belote[player] > 1)
            {   
                
                has_belote[player] = 0;
                bonus[ team_i(player) ] +=20;               

                
            }


            
        
            

        }
    
    }
        // cout << " | " << temp_score_1 << " " << temp_score_2 << " | " ;

        
        int max_score=0;
        for (size_t i = 0; i < trick.size(); i++)
        {
            int s = card_score(trick[i], game_trump);
            int player = player_i(i);

            auto v = errors[player];
            bool present = false;

            for (char c: v)
            {
                if (c == trick[i].trump )
                {
                   present = true;
                }
                
            }
            

            if ( present ){
                err << "ERROR: player " << player + 1 << " played a " << trick[i].rank << trick[i].trump ;
                // err << " but he should not have any " << errors[player] << " left." ;
                err << endl;
                return false;
            }

            if (trick[i].trump == trick_suit)
                {  

                    if ( max_score < s )
                    {
                        
                            temp_next_player = i;
                            max_score = s;
                    

                    }else if( max_score == s){

                        if (higher_than(trick[i], trick[temp_next_player]))
                        {
                            temp_next_player = i;
                            max_score = s;
                        }
                
                    }
            }else
            {
                
                errors[player].push_back(trick_suit);
            }


            if ( trick[i].trump != trick_suit and trick[i].trump != game_trump and team_i(next_player) != team_i(player))
            {   

                errors[player].push_back(trick_suit);
            }

            

            
        }

       


    if (has_trump==0)
    {   

        

        if ( team_i( player_i(temp_next_player) ) == 1 )
        {
     
            score[1] += temp_score_1 + temp_score_2;
            capot_1 = false;
        }else if (  team_i( player_i(temp_next_player) ) == 0  )
        {   
           
            score[0] += temp_score_1 + temp_score_2;
            capot_2 = false;
            
        }


    }else
    {   
        if ( team_i( player_i(max_has_trump) ) == 0 )
        {
            score[0] += temp_score_1 + temp_score_2;
            capot_2 = false;
        }else{
            score[1] += temp_score_1 + temp_score_2;
            capot_1 = false;
        }

        temp_next_player = max_has_trump;
        
    }

    

    next_player = ( temp_next_player + next_player  ) %4;
 
    

    return true;

}

bool game(std::istream& in, std::ostream& out, std::ostream& err){



    in >> game_trump >> contract_team;

    vector<card_t> trick;

    string line;
    int line_i = 0;
    while(std::getline(in, line)){

        if (line_i != 0)
        {
            trick = get_trick(line);

            if(set_score(trick,err) == false){
                return false;
            }



            if (line_i == 8)
            {

                    
                    // 10 de Der: WINNING LAST TRICK
                    if (team_i(next_player) == 0)
                    {
                    score[0] +=10;
                    }else{
                    score[1] +=10;
                    }

            }
            
            write_score(out);

            // cout << score[0] + bonus[0] << " " <<  score[1] +  bonus[1] << " " << next_player + 1 << endl;



        } 
        line_i +=1;
    }

    // CAPOT: WINNING ALL TRICKS
    if(capot_1){
        
        score[0] +=90;
    }if(capot_2){
        
        score[1] +=90;
    }

    // Final score
    if (score[0] + bonus[0] < score[1] +  bonus[1] and contract_team == 1)
    {
        
        score[1] = score[0] + score[1] ;
        score[0] = 0;
    }else if (score[1] +  bonus[1] < score[0] + bonus[0]  and contract_team == 2){
        score[0] = score[1] + score[0] ;
        score[1] = 0;
    }



    // cout << score[0] + bonus[0] << " " << score[1] +  bonus[1] << endl;
    out << score[0] + bonus[0] << " " <<  score[1] +  bonus[1] << endl;
    

    return true;

}


//////////////////  tar cfJ s198260.tar.xz s198260
