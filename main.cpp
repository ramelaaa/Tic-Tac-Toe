#include <iostream>
#include <string>
#include <cctype>   //isdigit()
#include <vector>
using namespace std;

char square[9] = {'1','2','3','4','5','6','7','8','9'};
void board();
bool check_user_input(string number);

int main(){
    
    int player   = 0, 
        response = 0, 
        mode     = 1;
    char letter  = '0',
         temp    = '0';
    bool is_response_valid;
    string user_input = "";

    vector<vector<int>> winning_rows = {//Horizontal Possibilities
                                {1,2,3}, //0
                                {4,5,6}, //1
                                {7,8,9}, //2
                                //Vertical Possibilities
                                {1,4,7}, //3
                                {2,5,8}, //4
                                {3,6,9}, //5
                                //Diagonal Possibilities
                                {1,5,9},// 6
                                {3,5,7} }; //7

    cout << "Let's play Tic Tac Toe! <<" << endl;
    cout << "This is the game board." << endl;
    board();
    cout << "Player 1 will be X and Player 2 will be O." << endl;
    board();
    
    do{
        // Allow Players to play
        while ( (mode % 3 == 1) || (mode % 3 == 2) ){
        	//player 1's turn
        	if(mode % 3 == 1){
        		player = 1;
            	letter = 'x';
        	}
        	//player 2's turn
        	else{
        		player = 2;
            	letter = 'o';
        	}
            
            //Allow player to make a selection
            cout << "Player " << player << ", enter a number to place an " << letter << ": " << endl;
            cin >> user_input;
            
            //validate user input
            is_response_valid = check_user_input(user_input);
            if(is_response_valid == false){
                //Give player another chance
                cout << "Your input is not valid. Try again!" << endl;
            }else{
                //Convert input to an int to locate square on board
                response = stoi(user_input);
                //temp will store char value of user input
                temp = '0' + response;
                //if user_input corresponds to a free space on board
                // an X or an O can be placed there
                if(temp == square[response - 1]){
                    square[response - 1] = letter;
                    mode++;
                }else{
                    cout<< endl;
                    cout<<"You cannot place an "<< letter <<" there, try again." << endl;
                }
                board();
            }
        }
        //Check if anyone won, with any of the row possibilites
        if ( mode % 3 == 0){
            for(int i = 0; i < winning_rows.size(); i++){
                if ((square[winning_rows[i][0]] == square[winning_rows[i][1]]) && (square[winning_rows[i][1]] == square[winning_rows[i][2]])){
                    cout << "Player " << player << " wins!" << endl;
                    cout << i << endl;
                    cout << winning_rows[i+1][0] << endl;
                    cout << winning_rows[i+1][1] << endl;
                    cout << winning_rows[i+1][2] << endl;
                    //break do-while loop condition
                    return 0;
                // All possibilies tested and no one won (yet)
                }
            }
            mode++;
        }  
    }while(mode <= 17 && mode >= 0);
    
    //Determine of there was a stalemate.
    //If turns equals 18, that means that the board is full
    //there is no X's or O's that are in a row of three.
    if (mode == 18){
        cout << "This game is a draw!" << endl;
    }
    
    return 0;   
}

//Print updated game board
void board(){
    cout << "*********************************************" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;
    cout << "     |     |     " << endl << endl;
}

//Checks user input if it is an integer between 1 and 9.
bool check_user_input(string number){   
    return number.size() == 1 &&number[0] >= '1' && number[0] <= '9';
}
