# Iterated Prisoner's Dilemma Simulation

## Overview
This project involves the development of a C++ program designed to simulate the Iterated Prisoner's Dilemma (IPD) game. The program offers several functionalities:
1. Set strategies for two players.
2. Enter the first move for the "Tit for Tat" strategy.
3. Simulate 20 rounds of the IPD game.
4. Display moves for each round and calculate scores.
5. Print the final scores and declare the winner.
6. Option to play again or exit the program.

## Table of Contents
- [Overview](#overview)
- [Technical Details](#technical-details)
  - [Game Theory and IPD](#game-theory-and-ipd)
  - [Algorithm](#algorithm)
  - [Data Structures](#data-structures)
  - [Functions](#functions)
- [Usage Instructions](#usage-instructions)
- [Conclusion](#conclusion)

## Technical Details

### Game Theory and IPD
The Iterated Prisoner's Dilemma is a classic game theory scenario where two players repeatedly choose to either cooperate or defect. The outcomes of their choices are scored based on a predefined payoff table:
- **Both Cooperate**: Each gets 3 points.
- **Both Defect**: Each gets 1 point.
- **One Cooperates, One Defects**: The defector gets 5 points, and the cooperator gets 0 points.

### Algorithm
1. **Set Player Strategies**: Players choose from four strategies: Evil (always defect), Good Person (always cooperate), Random (randomly cooperate or defect), and Tit for Tat (mimics the opponent's last move).
2. **Enter First Move for Tit for Tat**: If a player chooses Tit for Tat, they must enter their first move.
3. **Simulate IPD Rounds**: The game simulates 20 rounds, updating the players' moves and scores based on their strategies.
4. **Calculate Scores**: Scores are calculated after each round based on the payoff table.
5. **Print Scores and Declare Winner**: The final scores are displayed, and the winner is declared.

### Data Structures
- **Strategy Class**: Stores the logic for each strategy and the player's chosen strategy code.
- **Player Class**: Stores player-specific data such as score, previous moves, current move, and strategy.
- **Game Class**: Manages the overall game, including player interactions, score calculation, and result display.

### Functions
1. **Strategy Class**:
   - `char CooperateOrDefect(char other_player_previous_move)`: Determines the player's move based on their strategy.
   - `char getStrategy()`: Returns the player's strategy code.
   - `void setStrategy(char strat)`: Sets the player's strategy code.

2. **Player Class**:
   - `void increaseScore(int s)`: Increases the player's score.
   - `void setPreviousMoves(char move, int pos)`: Sets the player's move at a specific position.
   - `char getPreviousMoves(int pos)`: Gets the player's move at a specific position.
   - `int getScore()`: Returns the player's score.
   - `char getMove()`: Returns the player's current move.
   - `void setMove(char m)`: Sets the player's current move.
   - `char getStrategy()`: Returns the player's strategy code.
   - `void setStrategy(char strat)`: Sets the player's strategy code.
   - `char CooperateOrDefect(char other)`: Determines the player's move based on their strategy.

3. **Game Class**:
   - `void Interaction()`: Runs the game by setting strategies, simulating rounds, and printing results.
   - `void printingMove(int num)`: Prints the moves for each round.
   - `void scoringLogic()`: Calculates the scores after each round.
   - `void printScore()`: Prints the final scores and declares the winner.
   - `void changeStrategy(int player_ID, char strat)`: Changes the strategy for a player.
   - `bool isValidInput()`: Validates user input.
   - `void setupNewGame(int numPlayers)`: Sets up a new game with the specified number of players.
   - `void addPlayer()`: Adds a new player to the game.
   - `void dropPlayer(int playerID)`: Removes a player from the game.

## Usage Instructions
1. **Setting Player Strategies**:
   - Action: Select options 1 and 2.
   - Input: Enter the strategy codes for each player (e.g., 'e' for Evil, 'g' for Good, 't' for Tit for Tat, 'r' for Random).
   - Output: The strategies for each player are set.

2. **Entering First Move for Tit for Tat Strategy**:
   - Prerequisite: If Tit for Tat strategy is chosen.
   - Action: Follow the prompts to enter the first move if Tit for Tat is selected.
   - Input: Enter 'c' for Cooperate or 'd' for Defect.
   - Note: This step is skipped for other strategies.

3. **Running the Simulation**:
   - Prerequisite: Complete steps 1 and 2.
   - Action: Choose to run the simulation.
   - Output: The program simulates 20 rounds of the Iterated Prisoner's Dilemma and displays moves for each round.

4. **Exiting or Playing Again**:
   - Action: After the game concludes, choose to play again or exit.
   - Note: Selecting to play again will restart the simulation.

## Conclusion
This project successfully demonstrates the simulation of the Iterated Prisoner's Dilemma using object-oriented programming principles in C++. The program accurately simulates player interactions based on various strategies, calculates scores, and determines the winner, providing a useful tool for studying game theory and strategy dynamics.
