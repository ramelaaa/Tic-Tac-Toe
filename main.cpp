#include <iostream>
#include <string>
#include <cctype>   //isdigit()
#include <vector>
using namespace std;

char square[9] = {'1','2','3','4','5','6','7','8','9'};
void board();
bool check_user_input(string number);

int main(){
    
    int player; // var to conrol which player is playing. 
    int mode     = 1; // modes to let player 1 or 2 play, or to check board after each move
    char letter; // letter to mark the board
    char temp    = '0';
    string user_input = "";

    vector<vector<int>> winning_rows = {//Horizontal Possibilities
                                {0,1,2}, //0
                                {3,4,5}, //1
                                {6,7,8}, //2
                                //Vertical Possibilities
                                {0,3,6}, //3
                                {1,4,7}, //4
                                {2,5,8}, //5
                                //Diagonal Possibilities
                                {0,4,8},// 6
                                {2,4,6} }; //7

    cout << "Let's play Tic Tac Toe!" << endl;
    cout << "This is the game board." << endl;
    board(); // print board to users what it looks like.
    cout << "Player 1 will be X and Player 2 will be O." << endl;
    board(); // print board for first time.
    
    do{
        // Allow Players to play
        while ( (mode % 4 == 1) || (mode % 4 == 3) ){
        	//player 1's turn
        	if(mode % 4 == 1){
        		player = 1;
            	letter = 'X';
        	}
        	//player 2's turn
        	else{
        		player = 2;
            	letter = 'O';
        	}
            
            //Allow player to make a selection
            cout << "Player " << player << ", enter a number to place an " << letter << ": " << endl;
            cin >> user_input;
            
            //validate user input
            bool is_response_valid = check_user_input(user_input);
            if(is_response_valid == false){
                //Give player another chance
                cout << "Your input is not valid. Try again!" << endl;
            }else{
                //Convert input to an int to locate square on board
                int response = stoi(user_input);
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
               // printer updated board with new entry from player
                board();
            }
        }
        //Check if anyone won, with any of the row possibilites
        while ( mode % 4 == 0 || mode % 4 == 2){
            for(const auto& row : winning_rows){
                // three in a row have to be the same char
                if (( square[row[0]] == square[row[1]] && square[row[1]] == square[row[2]]){
                    cout << "Player " << player << " wins!" << endl;
                    //break do-while loop condition
                    return 0;
                }// All possibilies tested and no one won (yet)
            }
            mode++;
        }  
    }while(mode < 19);
    
    //Determine of there was a stalemate.
    //If turns equals 18, that means that the board is full
    //there is no X's or O's that are in a row of three.
    if (mode == 19){
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
