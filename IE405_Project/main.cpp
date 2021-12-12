//
//  main.cpp
//  IE405_Project
//
//  Created by Ellen Kirsh on 12/7/21.
//

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

char UserPick(){    //function giving the user an opportunity to choose rock, paper, or scissors
    char pick;      //define the player's choice as a character
    cout << "Choose (r) for rock, (p) for paper, (s) for scissors" << endl; //instructions for the player
    cin >> pick;    //player enters r, p, or s
    return pick;    //the function output holds the player's choice
}

int repeat(){       //function asking the user how many times they would like to play
    int n;          //define the player's answer as an integer
    cout << "How many games would you like to play?" << endl;   //instructions for the player
    cin >> n;       //player enters an integer
    cout << endl << "Great! Lets get started." << endl; //instructions for the player
    return n;       //the function output holds the desired number of games
}

char ComputerPick(){    //function defining the computer's choice. The computer is the opponent of the player
    srand(time(0));     //set new seed so the pseudorandom numbers generated are different for each execution
    int randNum = (rand() % 3) + 1; //set the variable randNum to be a random number of 1, 2, or 3
    if(randNum == 1){
        return 'r';     //if randNum = 1, the computer choice will be rock
    }
    else if (randNum == 2){
        return 'p';     //if randNum = 2, the computer choice will be paper
    }
    else {
        return 's';    //if randNum is not 1 or 2 then it will be 3 and the computer choice will be scissors
    }
}

void winner(char uPick, char cPick){    //function to let the player know the results of the game. It calls the output of UserPick and ComputerPick
    if(uPick == 'r' && cPick == 'p'){   //defines outcome when the user chooses r and the computer chooses p
        cout << "Computer wins, paper beats rock!" << endl; //single game outcome display
    }
    else if(uPick == 'r' && cPick == 's') { //defines outcome when the user chooses r and the computer chooses s
        cout << "You win, rock beats scissors!" << endl;    //single game outcome display
    }
    else if(uPick == 'p' && cPick == 'r') { //defines outcome when the user chooses p and the computer chooses r
        cout << "You win, paper beats rock!" << endl;   //single game outcome display
    }
    else if(uPick == 'p' && cPick == 's') { //defines outcome when the user chooses p and the computer chooses s
        cout << "Computer wins, scissors beats paper!" << endl; //single game outcome display
    }
    else if(uPick == 's' && cPick == 'r') { //defines outcome when the user chooses s and the computer chooses r
        cout << "Computer wins, rock beats scissors!" << endl;  //single game outcome display
    }
    else if(uPick == 's' && cPick == 'p') { //defines outcome when the user chooses s and the computer chooses p
        cout << "You win, scissors beat paper!" << endl;    //single game outcome display
    }
    else {  //defines the outcome if uPick == cPick
        cout << "Tie, you both picked " << uPick << "." << endl;    //single game outcome display
    }
}

int score(int n, char uPick[n], char cPick[n], string name){    //function to calculate the score of multiple games. Calls the number of games played, the results of each game, and the player's name
    int csum = 0; //defines the number of games the computer has won as an integer
    int usum = 0;   //defines the number of games the player has won as an integer
    int temp;   //defines a temporary variable to hold values of csum and usum
    for (int i=0; i<n; i++){ //loops for every game played, adds 1 to the winner's score
        if(uPick[i] == 'r' && cPick[i] == 'p'){ //defines score, after game i, when the user chooses r and the computer chooses p
            temp = csum;    //stores the value of the computer's score, after game i-1, in the temp variable
            csum = temp + 1;    //adds 1 win to the computer's score
        }
        else if(uPick[i] == 'r' && cPick[i] == 's') {   //defines score, after game i, when the user chooses r and the computer chooses s
            temp = usum;    //stores the value of the player's score, after game i-1, in the temp variable
            usum = temp + 1;    //adds 1 win to the player's score
        }
        else if(uPick[i] == 'p' && cPick[i] == 'r') {   //defines score, after game i, when the user chooses p and the computer chooses r
            temp = usum;    //stores the value of the player's score, after game i-1, in the temp variable
            usum = temp + 1;    //adds 1 win to the player's score
        }
        else if(uPick[i] == 'p' && cPick[i] == 's') {   //defines score, after game i, when the user chooses p and the computer chooses s
            temp = csum;    //stores the value of the computer's score, after game i-1, in the temp variable
            csum = temp + 1;    //adds 1 win to the computer's score
        }
        else if(uPick[i] == 's' && cPick[i] == 'r') {   //defines score, after game i, when the user chooses s and the computer chooses r
            temp = csum;    //stores the value of the computer's score, after game i-1, in the temp variable
            csum = temp + 1;    //adds 1 win to the computer's score
        }
        else if(uPick[i] == 's' && cPick[i] == 'p') {   //defines score, after game i, when the user chooses s and the computer chooses p
            temp = usum;    //stores the value of the player's score, after game i-1, in the temp variable
            usum = temp + 1;    //adds 1 win to the player's score
        }
        else {  //defines the score, after game i, when uPick == cPick
            temp = 0; //in the event of a tie, the scores remain the same as they were after game i-1
        }
    }
    cout << endl << "Final Results:" << endl;   //title for score listing
    cout << name << "'s score: " << usum << endl; //calls the name of the player and the player's score
    cout << "Computer's score: " << csum << endl;   //displays context and calls the computer's score
    int result = usum - csum;   //define the result as an integer, if usum-csum is positive, the player won; if negative, the computer won; if 0, there was a tie
    return result;  //the function outputs the total user score minus the total computer score
}

void choices(char choice){  //function takes the single character choice, from the user or computer, and displays the full name of the choice
    if(choice == 'r'){  //defines the output text if r was chosen
        cout << "Rock" << endl; //display's choice r as Rock
    }
    else if(choice == 'p'){ //defines the output text if p was chosen
        cout << "Paper" << endl;    //display's choice p as Paper
    }
    else if(choice == 's'){ //defines the output text if s was chosen
        cout << "Scissors" << endl; //display's choice s as Scissors
    }
}



int main(){

    int loop; //defines the variable used to store the number of games played as an integer
    
    cout << "Welcome to Rock, Paper, Scissors! What is your name?" << endl; //initial welcome text to define the game. Instructs the user to input their name
    string name;    //defines the variable used to store the player's name as a string
    cin >> name;    //player enters their name
    cout << "Nice to meet you, " << name << "! ";   //text to greet the player by name
    loop = repeat();    //calls the repeat function and stores the output as loop
    
    char bestofu[loop]; //define the array used to store user choices in each game as a character array. The array size is equal to the number of games played
    char bestofc[loop]; //define the array used to store computer choices in each game as a character array. The array size is equal to the number of games played
    
    char uPick; //defines the variable used to store the user's choice for a single game as a character
    char cPick; //defines the variable used to store the computer's choice for a single game as a character
    
    for(int i=0; i<loop; i++){  //loops the functionality of one game
        cout << endl;   //aesthetic space
        cout << "Game " << i+1 << endl; //displays the game number being played
        uPick = UserPick(); //calls the user's choice for one game and stores it as uPick
        cPick = ComputerPick(); //calls the computer's choice for one game and stores it as cPick

        cout << "You chose ";   //context to display the user's choice
        choices(uPick); //calls the choices function to display the full name of the user's choice

        cout << "The computer chose ";  //context to display the computer's choice
        choices(cPick); //calls the choices function to display the full name of the computer's choice

        winner(uPick, cPick);   //displays the winner of one game
        
        bestofu[i] = uPick; //stores the user's choice for game i
        bestofc[i] = cPick; //stores the computer's choice for game i
    }
    int uminusc = score(loop, bestofu, bestofc, name);  //calls the score function and stores it as uminusc, an integer
    cout << endl;   //aesthetic space
    if(uminusc > 0){    //defines display text if the total user score is greater than the total computer score
        cout << "Congratulations " << name << "! You have won best of " << loop << " games" << endl;    //displays message that the user won, calls the player's name and the number of games played
    }else if(uminusc < 0){  //defines display text if the total user score is less than the total computer score
        cout << "The computer has won best of "<< loop << " games. Better luck next time!" << endl; //displays message that the computer won, calls the number of games played
    }else{  //defines display text if the total user score is equal to the total computer score
        cout << "You have tied. You and the computer both won "<< loop/2 <<" games"<<endl;  //displays message that there was a tie, calls the number of games played/2, representing the number of games won by the player and computer
    }
    cout << endl;   //aesthetic space
    return 0;
}
