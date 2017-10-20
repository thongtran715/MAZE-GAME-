
// Thong Tran _ CS202

// This file is to implement the functionality of graph
#include "graph.h"
#include "list.h"
using namespace std;

 graph:: graph() {
	//Initialize the arrayChkpt
	arrayChkpt = NULL;
	arrayChkpt = new checkPoint[MAX_VERTEX];	
	// Name for the each check point 
	for ( int i = 0 ; i < MAX_VERTEX; i++) 
	{
		char name[2];
		name[0] = i + 65; // This will be translated to A->Z in ASCII 
		name[1] = '\0';
		arrayChkpt[i].set_name(name, i);
	}
}

graph::~graph() {
	
	if (arrayChkpt)
	delete [] arrayChkpt;
	arrayChkpt = NULL;

}
void graph::reward_checkpoint(int index, char * rName)
{
	arrayChkpt[index].set_reward(rName);
	arrayChkpt[index].display_reward();
}
void graph:: add_path ( int src, int dest) 
{
	// Check if this vertex connect to the any node
	if ( arrayChkpt[src].get_head() == NULL) 
	{
		// Connect the source vertex to new vertex
		arrayChkpt[src].get_head() = new checkpointNode ( &arrayChkpt[dest]);
		// also connect the new vertex to source vertex
		if (arrayChkpt[dest].get_head() == NULL)
			arrayChkpt[dest].get_head() = new checkpointNode ( &arrayChkpt[src]);
		else {
			// The following code will also check if the src had already been linked to dest 	
			if (arrayChkpt[dest].get_head()->isContain(&arrayChkpt[src])) return;
			checkpointNode * newNode = new checkpointNode (&arrayChkpt[src]);
			newNode->set_next(arrayChkpt[dest].get_head());
			arrayChkpt[dest].set_head(newNode);
		}
	}
	else {
		// need to check if the dest node has already been added
		if ( arrayChkpt[src].get_head()->isContain(&arrayChkpt[dest])) return;
	
		// else we add that node infront of the list 	
		else {
			// if it is not, then we add right the begin and set head equals to it.
			checkpointNode * newNode = new checkpointNode (& arrayChkpt[dest]);
			newNode->set_next(arrayChkpt[src].get_head());
			arrayChkpt[src].set_head(newNode);
			if (arrayChkpt[dest].get_head() == NULL)
				arrayChkpt[dest].get_head() = new checkpointNode ( &arrayChkpt[src]);
			else {
				// it will check if the src had already been linked to dest
				if (arrayChkpt[dest].get_head()->isContain(&arrayChkpt[src])) return;
				newNode = new checkpointNode (&arrayChkpt[src]);
				newNode->set_next(arrayChkpt[dest].get_head());
				arrayChkpt[dest].set_head(newNode);
			}		
		}
	}
}

// This function will then display the directions to the player from their locatiion
void graph:: display_directions(int start_point) {
	arrayChkpt[start_point].print_adjacent();
}

// reference to the checkpoint index and print the location
void graph::display_checkpoint_location(int index) {
	arrayChkpt[index].print_location();
}

// reference to the checkpoint functions to print out the entire graph
void graph:: display_entire_graph() 
{
	// display the adjacency list
	for ( int i = 0 ; i < MAX_VERTEX; i ++ ) 
	{
		arrayChkpt[i].print_location();
		arrayChkpt[i].print_adjacent();
		cout << endl;
	}
}

// DFS _ Algorithm 

int graph::DFS_Wrapper( int start) {
	
	// dynamically allocated an array of bool 
	bool * isVisited = new bool[MAX_VERTEX];
	// make all the checkpoints unvisited 
	for ( int i = 0; i < MAX_VERTEX; i++) isVisited[i] = false;
	// Calling the helper function 
	int temp  =  DFS_Res( start, isVisited);	
	// Deallocate 
	delete [] isVisited;
	return temp;
}
int graph:: DFS_Res( int start, bool *&isVisited) {
	isVisited[start] = true; // Mark it alrady visited
	arrayChkpt[start].print_location();
	checkpointNode * node = arrayChkpt[start].get_head();
	int number = start;
	while(node != NULL) {
		int value = node->go_adj()->get_id();
		// If that check point has not been visited then we call the recursive function
		if (!isVisited[value]) 
		{
				
		number = DFS_Res( value, isVisited);
		
		}
		// We must to tell the graph where is the dead end 
		else if (isVisited[value])// && node->go_next()== NULL) 
		{
			//cout << "This is the dead end " ;
			//int deadEndValue = node->go_adj()->get_id();
			//DFS_Res(deadEndValue, isVisited);
			node = node->go_next();				
		}
					
			
	}
		return number;
}
void graph::show_reward_in_this_checkpoint(int index, rewardList *rList) {

	arrayChkpt[index].show_reward_this_checkpoint(rList);
	return;	

}
bool graph::is_there(int index,int checkpoint)
{
	// return true or false if checkpoint has not been there
return	arrayChkpt[index].capture_nodes(checkpoint);
}


// Implementing the maze class



maze::maze() {
}

// Algorithm to generate the random maze 
// 1. Add path 0 to 1
// 2. Generate randomly the path between 1 and 18
// 3. Performing the DFS to find the point that has the longest path from the first point
// 4. Connect that last node to point 19 which is the winning point

// TESTING 
// 1. Make sure that the checkpoint will not connect to itself 
// 2. Make sure that the checkpoint will not have more than 4 directions

void maze::random_maze() {

	int num_paths = 0;
	int connect_to_path = 0;

	// First we will add the path 0 and 1	
	add_path(0,1);
	// funciton to call random function
	srand((unsigned)time(NULL));


	// This outner loop will go through the check point 1 to check point 19 to randomly connecting 	
	for (int startChk = 1 ; startChk < MAX_VERTEX -1 ; startChk ++) 
	{
		// generate the number of paths that each checkpoint can have
		// 0 means no check point 
		
		num_paths = rand() % 4;
		for ( int i = 0 ; i < num_paths; i ++ ) 
		
		{
					
			// for each path, randomly select the checkpoint that can be connected to.
				
		do {	
			connect_to_path = rand() % (MAX_VERTEX - 2) + 1;
		// if the checkpoint has less than 4 points then connect
			if (numbs_nodes(connect_to_path) <2) {	
				if (startChk != connect_to_path) 	
					add_path(startChk, connect_to_path);
			}
		}while(connect_to_path == startChk);
			// This will generate from 2 to 19
		}	

	}	
	// perforimg the DFS
	int lastPoint = DFS_Wrapper(0);
	std::cout << std :: endl;
	// add path to the last node
	add_path(lastPoint, 19);



}

	
////////////////////////////////////////////////////////////////////////////////////////////////
// Implementing checkpoint class .cpp


// Implementing checkpoint class 
checkPoint::checkPoint() {

	head = NULL;
	name = new char [20];
	strcpy (name, "A");
	iD = 0;
		

}

checkPoint::~ checkPoint() {
	if(name)	delete [] name;	
	if (reward) delete [] reward;
	
	// Destructor for deleting the head
	// traverse through each node and delete it	
	while(head) 
	{
		  	
	checkpointNode * temp = head ->go_next();
	delete head;
	head = temp;	
	}

	head = NULL;
}
void checkPoint:: set_name(char* newName, int iD)
{
	if (name) delete [] name;
	name = new char[strlen(newName) + 1 ] ;
	strcpy( name,newName);
	this->iD = iD; 

}
void checkPoint::print_location() {
	cout << iD << " ";
} 
void checkPoint::print_adjacent() {
	// if the head is NULL then return else traverse the list and display the node
	if (!head) return;
	head->display_node();
}
int checkPoint :: get_numbers_adjacency() const {
	if (!head) return 0;
	return head-> get_nodes(head);	

}
void checkPoint::show_reward_this_checkpoint(rewardList *rList) {	
	rList->random_pick();
}
bool checkPoint::capture_nodes(int checkpoint)
{
	if (!head) return false;
	return head->store_nodes(checkpoint);

}
void checkPoint::set_reward(char*rName)
{
	if (reward) delete [] reward;
	reward = new char[strlen(rName) + 1];	
	strcpy(reward, rName);

}
void checkPoint::display_reward() {
	std::cout << reward << std::endl;
}


// Implementing the checkpointNode class
checkpointNode::checkpointNode () {
	next = NULL;
	adj = NULL;
}
checkpointNode::~checkpointNode() {
	
	next = NULL;
	adj = NULL;	

}
void checkpointNode::display_node() {
	// print out the current name of the head
	// using the recursive call to traverse the list
	adj->print_location();
	if (next != NULL) next->display_node();

}
bool checkpointNode::store_nodes(int checkpoint)
{
	int node_value =	adj->get_id();
	if (node_value == checkpoint) return true; 
	
	if (next!= NULL)
	return next->store_nodes(checkpoint);	
	return false;	

} 
int checkpointNode::get_nodes(checkpointNode* next) 
{
	if (next == NULL) return 0;
	return get_nodes(next->go_next()) + 1;	

}
bool checkpointNode:: isContain(checkPoint* dest) {

	// if the added checkpoint has been connected then return true
	if (adj == dest) return true;
	// if it is not, keep searching 
	else if (next != NULL) return next->isContain(dest);
	return false;

}








