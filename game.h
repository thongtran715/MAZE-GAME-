// This class is game.h
// Thong Tran CS 202
// 4/21/2017
// Program 1
// This class is the game class which will controll the game. In other words, it is the manager class
// All it does is to assemble all the classes together and form the complete game
// This file is used because it contains the game class which plays an important role in managing 
// all species in this program 
// The game class will be able to access to each individual player and ask them to make a move. 
// It will be able to keep track of where the player is on the maze, as well as give the player 
// directions to go from their starting point
// The Game class can also have the rewards list which it can assign to each checkpoint when the plyer step into
// The game class will also keep tracking the numbers of players who are playing this game
// The game will also be able to add players into the friends list and players list
// The game will also manage where the winning spot is and stop when one of the players reaches the final destination 

// The game has the maze, friends list, rewards list , players list and the playerNode to help access
// to each indiviual player

// 		People want to use this class because it controls everything 
//  		Without this class, they will not be able to access to each class in this program


#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "graph.h"
#include "list.h"


// This game class is the manager for this game. It will have the reward lits, friends list and players list
// The game will also have the playernode to access to individual player
class game {
	public:
	// Default constructor 
	game();
	// destructor 
	~game();
	// Generate the maze function 
	void generate_the_maze();
	// Add player to List 
	void add_player();
	// add rewards to the game. 
	void add_rewards ( char *rewardName);
	// show the location 
	void show_location_at_check_point(int index); 
	// show the directions 
	void show_directions_to_player ( int index);
	// let's get started the game
	void play_game();
	// This function will tell the game if user's input wrong
	bool isValid (int index,int checkpoint);	
	// How many players are playing 
	void numbers_players_playing(); 
	// Add rewards Initial 
	void reward_initial (); 
	// Introudction
	void introduction();
	// options for player
	void player_options(int player_index,int location); 
	protected:
	// map is the object of maze
	maze map;
	// rList is the object of rewardList
	rewardList rList;
	// players list is the object of players list
	playerList playersList;
	// pList is the object of friends list
	friendsList pList;		
	// cpn is the pointer to the playerNode
	playerNode * cpn;
	int cpi;
	bool* had_rewards; // This will mark true if the player already visited the checkpoint that has the reward			    // This will make sure that the player will not have the reward twice. 
		
};



#endif
