
// THONG TRAN CS202
// 4/21/2017
// Program 1

// This is the list.h file 
// This file is used to implement there list classes which are friends list, players list and rewardslist
// It also implements node data structure which are player node and reward node
// This file keeps all the implementation of the list classes into one specific file 
// We want to use this file because they want to call the list classes to store players into 
// an overall players list. In addition, they also want to call the players into the assigned group
// We can store the rewards into the reward lists. 
// Basically this class keeps all the data related to the players and the rewards



#ifndef list_h
#define list_h
#include "player.h"
#include <iostream>
#include <cctype>
#include <cstring>
// This file is the list 
class playerNode;
class rewardNode;
class playerList {
	
	public:
	// Default constructor 
	playerList () ;
	// destructor 
	virtual	~playerList();
	// insert player that takes the name of that player as an argument
	void insert_player ( char *name);
	// display players function to display all the players in the players list
	void display_players();	
	// getter function to get the head of the players list.
	// We want to traverse through the list and get access to the players. 
	// That's why we need that function
	playerNode *& get_head() {return head;}
	protected: 
	// this head will point to the first node
	playerNode * head;
	// this tail will point to the last node
	playerNode * tail;	
};


class friendsList: public playerList {
	
	// Default constructor 
	public:
	friendsList ();
	// Destructor
	~friendsList();
	// display group name
	void display_groupName();
	// add group name taking the name as an argument
	void add_group_name(char *gName);
	// displayer all the players in the group
	void display_players_in_group(); 
	// This function will help the game to add the players into the specific group
	// when the player is done at adding their members into the group
	// this function will get notice and assign a new group for new members
	void insert_player_special (char *newName, bool done_adding);	
	protected:
	// inherit from players list ,so we do not need to have any data member here
};



class rewardList {
	
	public:
	// Default constructor 
	rewardList();
	//Destructor 
	~rewardList();
	// insert the reward into the list that have the name of the reward as an argument
	void insert_reward(char *name);
	// display the entire rewards in the list
	void display_entire_rewards();
	// This function will return the pointer of character of the reward. 
	// This function is made because we want to generate randomly the reward and 
	// assign to specific checkpoint
	char* random_pick ();
	protected:
	// This head will point to the first node of the reward list
	 rewardNode * head;
	// This tail will point to the last node of the reward list
	rewardNode *tail;	


};



// This class is about the node. There are two classes. The first one is playernode
// and the second one is rewardNode. Their job is to contain datas and each of them will form the // the list. For example, the playernode class contains the array of players and group name. 
// each player node can connect together and form one list 
// The same thing with rewardNode. It contains the data about the reward.




// We will say hey compiler the player class is coming. Do not panic
class player;

class playerNode {

	public: 
	// Default Constructor 
	playerNode() ;
	// constructor with argument
	playerNode(int maxSize);
	// copy constructor	
	playerNode ( const playerNode& to_copy);
	// go next function 	
	playerNode*& go_next() {return next;}

	// destructor
	~playerNode ();

	// setting the player name with the name as an argument 
	int set_Data(char *name);
	// get all the players
	void getPlayers() const ;
	// display one specific player
	void get_player(int index);
	// set next to connect to the next node
	void set_Next (playerNode * connect);
	// This function will execute the move of the specific player
	void get_execution_player ( int index, int move); 
	// get the location move of the player
	int get_location_move( int index);
	// get the size of the array
	int getSizeArray() {return sizeArray;}	
	// this function will add the reward into the list reward of each player 
	void players_reward(int index, char *rName); 	
	// This fucntion will display all the list of rewards that the user has
	void display_rewards(int index);
	// setting the group name. Each node is the group of the player
	void set_group_name(char *gName);
	//displaying the group name	
	void display_group_name();	
	protected:
	// creating the array of players
	player * arr;
	// next pointer to connect or get to the next node
	playerNode* next;
	// index keep tracks the index of the arrray when adding the new data
	int index;
	// the maximum size of the array can hold
	int maxSizeArray;
	// this will tell how much the current size of the array is 
	// it will be always less than or equal to maxSizeArray
	int sizeArray;
	// takingn the variable name to assign the group's name	
	char *groupName;
};

class rewardNode {

	public:
	// default constructor 
	rewardNode();
	// Destructor 
	~rewardNode(); 
	// constructor with argument
	rewardNode( int maxSize);	
	// set the reward name by having the name as an argument
	int set_data(char*name);
	// display the reward
	void show_reward();
	// go to the next node function. This is the inline code. We could have the return 
	// next to the function 
	rewardNode *& go_next () {return next;}
	// set next pointer function
	void set_next(rewardNode * connect);
	// randomly select the reward and return it
	char* show_one_reward();	
	protected:
	// reward name is an pointer to array pointer. This will hold different rewards 
	char ** rewardName;
	// next variable to access to the next node
	rewardNode* next;
	// index keep tracks the array index
	// maxSizeArray is the maximum size of array that the array can hold
	// sizeArray is the current size of array when done adding the new data
	int index, maxSizeArray, sizeArray;


};






#endif
