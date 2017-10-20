// This file is the file where we design the player class
// Thong Tran  CS 202
// Program 1
// 4/21/2017


// This file contains the player list class 
// This class will represent for the player itself. This class will be able to set the name of the
// player and return the location index 
// Player class has their friends list and rewards list. They are able to move around the maze. 
// Display their friends, display their name and display their rewards 
// They are able to tell the graph. "Hey I am here" by returning their current location to the graph
// and the graph will tell which directions you can go next 
// Along their journey on the maze, they will step into different checkpoints and they might collect
// different rewards. Therefore, they will have their own sheet of paper to write down all the rewards
// Therefore, instead of having the rewards list class which contains all possible rewards. 
// I created the pointer to the array pointer that can store the list of rewards inside the player
// Think about it as a sheet of paper that player can write down 



#ifndef player_h
#define player_h
#include "list.h"
#include "graph.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
// The purpose of this class is to have the player object. They have their name, their reward list
// their friends list. 
class checkPoint;
class rewardList;
class player {
	
	public:
	
	// Default constructor

	player();	
	player(char *newName);
	//Copy Constructor	
	player(const player& to_copy);
	//Destructor 
	~player();
	void display_location(int index); 	
	void set_move ( int move_index);
	int get_move() {return current_index;}
	void copy_player (char *playerName);
	void deep_copy (const player&newName);	
	void display_reward(); 
	void add_rewards (char* rewardName);
	void display_player() const ;	
	protected:
	char* name;
	int current_index; 
	checkPoint *location;
	char ** rList;
	int sizeArray; // this will keep track the size of rList
};




#endif
