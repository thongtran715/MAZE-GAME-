// Thong Tran CS202
// Program 1 
// 4/21/2017
// this file is to implement the interface of Graph

// This file is graph.h. It contains all the data structure and algorithm needed to 
// generate the maze 
// The graph basically will be able to add the path, connecting differnt checkpoints together
// The graph will create an array of checkpoint to create the adjacency list model
// The maze in this case will play an important role in generating the graph based on the 
// data structure that are already implemented from the graph 
// 		


//			People want to use this file because:
// 1. They need this file because they want to create checkpoints or locations with their iD or name
// 2. They want to form the complete graph
// 3. They want to have the maze that makes sure there is path from the first point to the winning point
// 4. They want to have the random maze that every game will have the different graph







#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
// Global constant variables 
const int MAX_VERTEX = 20;
const int MAX_DIRECTIONS = 3;


class rewardList;
class checkPoint;




class checkPoint {

	public:
	// Default constructor 
	checkPoint();	
	// Destructor 
	~checkPoint();
	// Copy Constructor 
	checkPoint ( const checkPoint& to_copy);
	// Display function 
	void print_location();
	// set the check point the name and the id 
	void set_name ( char * newName , int iD);
	// get the head checkpoint Node 
	class checkpointNode*& get_head() {return head;}
	// set head function 
	void set_head (class checkpointNode * connection) { head = connection;}
	// print adjancey 
	void print_adjacent();	
	// adjacent return 
	int get_numbers_adjacency() const;	
	// Get ID 
	int get_id() {return iD;}	
	// This function will then try to capture all the nodes from one specific checkpoint that it connects to 
	bool capture_nodes (int checkpoint); 	
	// show reward function 
	void show_reward_this_checkpoint(rewardList *rList);
	// set the reward name 
	void set_reward( char *rName);
	// diplay the reward 
	void display_reward();	
	protected:
	class checkpointNode * head;
	char * name;
	int iD;
	char * reward;
				
};
class checkpointNode {
	public:
	// default constructor 
	checkpointNode();
	~checkpointNode();
	// Constructor with paramized
	checkpointNode ( checkPoint * dest) {adj = dest;}	
	// go next function 
	checkpointNode *& go_next() {return next;}
	// get adjacent fucntion 
	checkPoint*& go_adj() { return adj;}
	//set next 
	void set_next ( checkpointNode * connection) { next = connection;}
	void set_adj(checkPoint * connection) { adj = connection;}
	bool isContain(checkPoint * dest);

	// This function will try to store the nodes that connect to one node.
	// The purpose of this is to traverse through the vertex and check if the player's move valid.
	// So , we can later on use that to check if the player's move is valid or not.
	bool store_nodes ( int checkpoint);
	void display_node();
	int get_nodes(checkpointNode* next);
	protected:
	// next pointer data member to access to the next node
	checkpointNode * next;
	// adj pointer to point to checkpoint node
	checkPoint* adj;

};





class graph {

 	public:
	
	// Default constructor 
	graph();
	// Destructor 
	virtual	~graph();	
	// add path function 
	void add_path ( int src, int dest);
	// display graph 
	void display_entire_graph();
	// display current directions 
	void display_directions ( int start_point);
	// display the checkpoint 
	void display_checkpoint_location ( int index);
	// DFS wrapper function to call the recursive function 
	int DFS_Wrapper ( int start);

	// THis function will call the store_nodes function to call all the nodes and 
	// check the if one checkpoint is in the list
	bool is_there( int index, int checkpoint); 

	// this function will set the reward at specific checkpoint when the player moves	
	void reward_checkpoint( int index, char * rName);
	// this function will return the number of path from specific checkpoint to another		
	int numbs_nodes( int index) {return arrayChkpt[index].get_numbers_adjacency();}
	
	// this function will show the reward from this checkpoint 	
	void show_reward_in_this_checkpoint (int index, rewardList *rList);
	protected:
	// creating the array of checkpoint inside the graph
	checkPoint * arrayChkpt;
	private:
	// DFS rescursive function 
	int DFS_Res ( int start, bool*& isVisited);

};




class maze : public graph {

	public:
	// default constructor 
	maze();	
	//random maze function 
	void random_maze();	
};






#endif
