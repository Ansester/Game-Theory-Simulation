/********************************************************
 [USING 48 HOUR PASS]
 Author: Ashmit Shankar Mukherjee
 Date Created: December 2, 2023
 Description:
 ___________________________________________________
 Assignment 3 - Computer Programming for Engineers
 ___________________________________________________
 Computer Engineering Case Study- Iterated Prisoner's Dilemma:
 
 This C++ program simulates the Iterated Prisoner's Dilemma, a game theory scenario, through three main classes: Strategy, Player, and Game. The Strategy class defines players' behaviors—cooperation or defection—based on various strategies like tit-for-tat or random. Players, characterized in the Player class, keep scores and track their moves. The Game class orchestrates the match, managing player interactions and rounds. Players input their strategies, and the game evolves over 20 rounds, updating scores and moves accordingly. Finally, the program declares a winner based on the accumulated scores after all rounds.
 ***********************************************************/

#include <iostream>		//iostream library for handling input, output

#include <cstdlib>		//standard c library for srand and rand functions

#include <limits>		//library used in checking valid input function

using namespace std; //using standard namespace
#define num_rounds 20 // Defining number of rounds to 20

//Strategy class for storing the logic for 4 strategies and also the strategy code for players
class Strategy {
	
private:
	
	char strategy_code; //variable for storing player strategy code
	
public:
	// Function for the logic of the 4 strategies
	char CooperateOrDefect(char other_player_previous_move) {
		
		if (strategy_code == 'e') //evil strategy
		{
			return 'd'; //always returns defect
		} else if (strategy_code == 'g') //good person strategy
		{
			return 'c'; //always returns cooperate
		} else if (strategy_code == 't') //tit for tat strategy
		{
			return other_player_previous_move; //always mimics other player's previous move
		} else {
			if (rand() % 2 == 0) {
				return 'c'; //generates random move
			} else
				
			{
				return 'd';
			}
		}
	}
	
	char getStrategy() //accessor for strategy code
	{
		return strategy_code;
	}
	
	void setStrategy(char strat) //modifier for stratgy code
	{
		strategy_code = strat;
	}
	
};

//Player class for storing relevant information about every player
class Player {
private:
	
	int score; //for storing total score
	
	char previous_moves[num_rounds]; //array for storing all previous moves
	
	static int uniqueID; //static integer for generating unique ID
	
	int ID; //integer for storing unique ID
	
	char move; //character variable for storing current move
	
	Strategy s; //strategy class reference
	
public:
	
	//non-default constructor that initializes required data members and also increments static variable after assigning it to ID
	Player() {
		score = 0;
		ID = uniqueID;
		uniqueID++;
	}
	
	//function for increasing score after every round
	void increaseScore(int s) {
		score += s;
	}
	
	//modifier function for the previous moves array
	void setPreviousMoves(char move, int pos) {
		previous_moves[pos] = move;
	}
	
	//accessor for previous moves in the given position in the array
	char getPreviousMoves(int pos) {
		return previous_moves[pos];
	}
	
	//accessor for the total score
	int getScore() {
		return score;
	}
	
	//accessor for accessing current move
	char getMove() {
		return move;
	}
	
	//accessor for accessing current move
	void setMove(char m) {
		move = m;
	}
	
	//accessor for player strategy code
	char getStrategy() {
		return s.getStrategy();
	}
	
	//modifier for player strategy code
	void setStrategy(char strat) {
		s.setStrategy(strat);
	}
	
	//function for returning move that calls the same function in strategy class
	char CooperateOrDefect(char other) {
		return s.CooperateOrDefect(other);
	}
	
	//accessor for player ID
	int getID() {
		return ID;
	}
	
};

int Player::uniqueID = 0; // Initializing static variable

//Game class for handling the player interaction, adding players, printing score and declaring winner
class Game {
private:
	
	char strat; //for storing current strategy of player
	Player *
	P; //pointer variable to array of player objects
	char current_move; //for storing current move of player
	int num_players; //for storing the current total number of players
	
public:
	
	//non-default constructor
	Game() {
		P = nullptr; // Initialize P to nullptr
		num_players = 0;
	}
	
	//non-default destructor for deallocating memory
	~Game() {
		if (P != nullptr) { //prevents double deletion
			delete[] P;
			P = nullptr;
		}
	}
	
	// Interaction function which is the function for running the game
	
	void Interaction() {
		
		//Main Menu
		cout <<
		"------------------------------------------------------------------------------------------------------------------\n";
		cout << "Iterated Prisoner's Dilemma\n";
		cout <<
		"------------------------------------------------------------------------------------------------------------------\n";
		cout << "Here are the strategy codes- \n";
		cout << "\ne: Evil (always defect)\n" <<
		"t: Tit for tat (imitates other player's previous move)\n" <<
		"g: Good Person (always cooperate)\n" << "r: Random\n";
		cout <<
		"------------------------------------------------------------------------------------------------------------------\n";
		
		// Loop for Player 1's Strategy input
		while (true) {
			cout << "Enter Player 1 Strategy- ";
			cin >> strat;
			if (isValidInput() && (strat == 'e' || strat == 'g' || strat == 't' || strat == 'r')) //checks valid and desired input
			{
				P[0].setStrategy(strat);
				break;
			} else {
				cout << "Invalid input. Please try again.\n";
			}
		}
		
		// Loop for Player 2's Strategy input
		while (true) {
			cout << "Enter Player 2 Strategy- ";
			cin >> strat;
			if (isValidInput() && (strat == 'e' || strat == 'g' || strat == 't' || strat == 'r')) //checks valid and desired input
			{
				P[1].setStrategy(strat);
				break;
			} else {
				cout << "Invalid input. Please try again.\n";
			}
		}
		
		// Loop for Player 1's first move if Tit for Tat
		if (P[0].getStrategy() == 't') {
			while (true) {
				cout <<
				"Enter Player 1 first move ('c' for Cooperate and 'd' for Defect): ";
				cin >> current_move;
				if (isValidInput() && (current_move == 'c' || current_move == 'd')) //checks valid and desired input
				{
					P[0].setMove(current_move);
					P[0].setPreviousMoves(current_move, 0);
					break;
				} else {
					cout << "Invalid input. Please try again.\n";
				}
			}
		} else {
			P[0].setMove(P[0].CooperateOrDefect(' '));
			P[0].setPreviousMoves(P[0].getMove(), 0);
		}
		
		// Loop for Player 2's first move if Tit for Tat
		if (P[1].getStrategy() == 't') {
			while (true) {
				cout <<
				"Enter Player 2 first move ('c' for Cooperate and 'd' for Defect): ";
				cin >> current_move;
				if (isValidInput() && (current_move == 'c' || current_move == 'd')) //checks valid and desired input
				{
					P[1].setMove(current_move);
					P[1].setPreviousMoves(current_move, 0);
					break;
				} else {
					cout << "Invalid input. Please try again.\n";
				}
			}
		} else {
			P[1].setMove(P[1].CooperateOrDefect(' '));
			P[1].setPreviousMoves(P[1].getMove(), 0);
		}
		
		printingMove(0); //calls the print move function to print player move for the first round
		scoringLogic(); //calls the scoring function to calculate player score for the first round
		
		// Loop for rounds 2 to 20
		for (int i = 1; i < num_rounds; i++) {
			P[0].setMove(P[0].CooperateOrDefect(P[1].getPreviousMoves(i - 1)));
			P[1].setMove(P[1].CooperateOrDefect(P[0].getPreviousMoves(i - 1)));
			P[0].setPreviousMoves(P[0].getMove(), i);
			P[1].setPreviousMoves(P[1].getMove(), i);
			
			printingMove(i); //calls the print move function to print player move for the round
			scoringLogic(); //calls the scoring function to calculate player score
			
		}
	}
	
	//printing move function to print the move for players for every round
	void printingMove(int num) {
		
		cout << "\nRound " << num + 1 << " \n";
		cout << "----------------------------------------------\n";
		cout << "Player 1 move: ";
		if (P[0].getMove() == 'c') {
			cout << "Cooperate\n";
		} else {
			cout << "Defect\n";
		}
		
		cout << "Player 2 move: ";
		
		if (P[1].getMove() == 'c') {
			cout << "Cooperate\n";
		} else {
			cout << "Defect\n";
		}
		
	}
	
	//scoring logic function that keeps adding the scores in the scores data member in the player class after every round
	void scoringLogic() {
		// Scoring logic for the rest of the rounds
		if (P[0].getMove() == 'c' && P[1].getMove() == 'c') {
			P[0].increaseScore(3);
			P[1].increaseScore(3);
		} else if (P[0].getMove() == 'c' && P[1].getMove() == 'd') {
			P[1].increaseScore(5);
		} else if (P[0].getMove() == 'd' && P[1].getMove() == 'd') {
			P[0].increaseScore(1);
			P[1].increaseScore(1);
		} else if (P[0].getMove() == 'd' && P[1].getMove() == 'c') {
			P[0].increaseScore(5);
		}
	}
	
	// Function for printing score and declaring winner
	void printScore() {
		cout << "\n----------------------------------------------\n";
		cout << "Player 1 Score: " << P[0].
		getScore() << "\nPlayer 2 Score: " << P[1].getScore() << endl;
		
		if (P[0].getScore() == P[1].getScore()) {
			cout << "\nResult: The game is a tie between the two players\n";
		} else if (P[0].getScore() > P[1].getScore()) {
			cout << "\nPlayer 1 wins \n";
		} else {
			cout << "\nPlayer 2 wins \n";
		}
	}
	
	//function for changing strategy (if required)
	void changeStrategy(int player_ID, char strat) {
		P[player_ID].setStrategy(strat);
	}
	
	bool isValidInput() //function for checking valid user input
	{
		if (cin.fail()) {
			cin.clear(); // clear error state
			cin.ignore(numeric_limits < streamsize > ::max(), '\n'); // ignore the rest of the line up to newline
			return false;
		}
		
		return true; //returns true if valid input
	}
	
	//function for adding players based on the number of players passed to it
	void setupNewGame(int numPlayers) {
		if (P != nullptr) {
			delete[] P; // Deallocate old memory if P was previously allocated
			P = nullptr;
		}
		
		num_players = numPlayers;
		P = new Player[numPlayers];
	}
	
	//function for adding a new player to the game
	void addPlayer() {
		Player *
		newP = new Player[num_players + 1];
		
		for (int i = 0; i < num_players; i++) {
			newP[i] = P[i]; // Copy existing players
		}
		
		delete[] P; // Free old array
		P = newP; // Reassign P to the new array
		num_players++; // Increase number of players
	}
	
	//function for dropping a player by passing playerID
	void dropPlayer(int playerID) {
		if (num_players <= 1 || P == nullptr) {
			// Can't drop players from an empty or nearly empty game
			return;
		}
		
		Player *
		newP = new Player[num_players - 1];
		int
		newIndex = 0;
		
		for (int i = 0; i < num_players; i++) {
			if (P[i].getID() != playerID) {
				newP[newIndex++] = P[i]; // Copy players except the one to drop
			}
		}
		
		delete[] P; // Free old array
		P = newP; // Reassign P to the new array
		num_players--; // Decrease number of players
	}
	
};

//main function
int main() {
	srand(static_cast < unsigned > (time(NULL))); // Seed for the rand function
	
	char ans = 'n'; // Variable to store user's choice to play again
	
	do {
		Game g; // Creating object for game class
		
		g.setupNewGame(2); // Setup a new game with 2 players
		g.dropPlayer(1); //drops a player
		g.addPlayer(); //adds a player
		g.Interaction(); // Run the game interaction
		g.printScore(); // Print the score at the end of the game
		
		cout << "\nDo you want to play again? (y/n): ";
		cin >> ans;
		
	}
	while (ans == 'y' || ans == 'Y'); // Continue if user enters 'y' or 'Y'
	
	return 0;
}

/************************************END****************************************/
