// THONG TRAN CS202
// 4/21/2017
// Program 1 
// This is the list.cpp file 


// This file is used for implementing all the functions in the list.h





#include "list.h"
// Implementing the Player list
playerList::playerList () {
	// set the default values of head and tail to NULL
	head = NULL;
	tail = NULL;
}
playerList::~playerList() {


	// traverse through the list and delete the head
	// the taill will point to nothing if we delete all the head
	while(head) 
	{
	// Have the temp point to the next node	
	playerNode * temp = head->go_next();
	// delete the head
	delete head;
	// reset the head
	head = temp;	
	}
	// Set the head to NULL after finishing deleteing all the head
	head = NULL;



}


void playerList :: insert_player(char*name) {

	// if head is NULL 
	if (head == NULL)  {
		// initialize the head for the size of 10
		head = new playerNode(10);
		// set data and the tail
		head->set_Data(name);
		// set tail to the current head
		// this case is used only if nothing in the list
		tail = head;
		return;
	}
	else {
		
		// check if the size is full. 1 is the return type from set_data function 
		// indicates the size is full
		if( tail->set_Data(name) == 1) 
		{	
			// create the new node and add after the head
			playerNode* newNode = new playerNode;
			// set that node to hold the variable name
			newNode->set_Data(name);
			// set the point to node we just added
			// By doing this way we will always have tail point to the last node
			tail->set_Next(newNode);
			// we move the tail to the last node
			tail = tail->go_next();
			return;
		}
	}

}




void playerList:: display_players() {
	
	// having the temp poiinter 	
	playerNode *temp = head;
	if(!head) return;
	// if head is not NULL
	while(head != NULL) 
	{
		// display the players in that node 
		head->getPlayers();
		// keep traversing the node
		head = head->go_next();
	}
	// reset the head back to the first position	
	head = temp;
	return;
}




// Implementing the reward List 

rewardList::rewardList() {
	
	// set the default head and tail to NULL
	head = NULL;
	tail = NULL;	

}
rewardList:: ~rewardList () {
	
	// if head is null
	if (!head)
		head = NULL;
	// this temp node will keep the head
	rewardNode* temp = head;
	// traversing the heead and delete each node
	while(head)
	{
		// move the head over 
		head = head->go_next();
		// delete the temp which is the previous node of the head	
		delete temp;
		// set the temp is null
		temp = NULL;
		// set the temp back to head and keep traversing
		temp = head;
	}
	// Lastly, set the head and the tail to NULL
	head = NULL;
	tail = NULL;
}



void rewardList::insert_reward ( char *name)
{	

	// same function insert_player in the player list class
	
	// if head is null, create the new node
	if ( head == NULL)
	{
		// setting the size array of the rewards to be 20  
		head = new rewardNode(20);
		// copy the data over. 
		// the reason we have the char* because of the conversion string to char*
		head->set_data((char*)name);
		tail = head;
		return;
	}
	else {
		if(tail ->set_data(name) == 1)
		{
			rewardNode * newNode = new rewardNode;
			newNode->set_data((char*)name);
			tail->set_next(newNode);	
			tail = tail->go_next();
			return; 

		}


	}

}

void rewardList :: display_entire_rewards() {

	rewardNode* temp = head;	
	if(!head) return;
	while(head != NULL) 
	{
		std::cout << "This is the reward list ";
		head->show_reward();
		head = head->go_next();
	}
	head = temp;

}

char *rewardList::random_pick() {
	// this function will then try to return a random char pointer from show_one_reward function
	if (!head) return NULL;
	return head->show_one_reward();
}

// Implementing the Friends List 
friendsList::friendsList (){}
friendsList::~friendsList() {

		
	if (!head) {
		delete head;
		head = NULL;
	}
	playerNode* temp = head;
	while(head)
	{
		head = head->go_next();
		delete temp;
		temp = NULL;
		temp = head;
	}
	head = NULL;
	tail = NULL;
}
void friendsList::display_groupName() {
	
	head->display_group_name();
}
void friendsList::add_group_name(char*gName)
{
	// we need to traverse to each node and set each of the node the name	
	playerNode * curr = head;
	// if it is not NULL, then go to the next node
	while ( curr->go_next() != NULL) curr = curr ->go_next();
	// set the name	
	curr->set_group_name(gName);
}
void friendsList:: display_players_in_group () {
	// if head is not null we get the players inside the node
	if(!head) return;
	head->getPlayers();
}

void friendsList::insert_player_special(char *newName, bool done_adding)
{
	
	// if head is NULL 
	if (head == NULL)  {
		// we set 5 players in each node
		head = new playerNode(5);
		head->set_Data(newName);
		tail = head;
		return;
	}
	else {
		// check if the user is done adding the new player in to the group 
		// if it is true, we create the new node and let other user to enter their new players	
		if ( done_adding == true) 
		{ 
			// if the player is done adding. we make a new node with the size 5
		        playerNode* newnode = new playerNode(5);
			newnode->set_Data(newName);
			tail->set_Next(newnode);
			tail = tail->go_next(); 
			return;   	
		}	// check if the size is full	
		else if( tail->set_Data(newName) == 1)
		{
			// if the player exceeds the allowed number of players in each group
			// display the function 
			std::cout << "The maxium players in your group is 5";		
			return;
		} // Done edditing

	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// Implementing the node classes 

// Implementing the Player Node
playerNode::playerNode () {
	next = NULL;
	arr = NULL;
	index = 0;
	sizeArray = maxSizeArray;
	arr = new player[maxSizeArray]; 
	groupName = new char[100];
}

playerNode:: playerNode ( int maxSize)
{
	
	next = NULL;
	arr = NULL;
	index = 0;
	// Setting the size array to assigned size
	this->maxSizeArray = maxSize;
	// allocate the memory
	arr = new player[maxSize];
}
playerNode:: ~playerNode() {
	// deleting the pointer of player and char 
	delete [] groupName;
	delete [] arr;
	// set the next to NULL
	next = NULL;
}
void playerNode::set_group_name(char *gName)
{
	// allocatate and copy the name
	if(groupName) delete [] groupName;
	groupName = new char [strlen(gName) + 1];
	strcpy(groupName, gName);
}
void playerNode::display_group_name() {
	
	std::cout << groupName << std::endl;
}


void playerNode::set_Next(playerNode* connect) {
	next = connect;
}
void playerNode::get_player(int index) {
	// It will get the index of the player in the index and display it 
	arr[index].display_player();	
}
int playerNode::set_Data(char *name)
{
	// set data. If the size of arrays grows up to the max size of array
	// reseting the index and return 1 to indicate that it is full
	if (index == maxSizeArray)
	{
		index = 0;
		return 1; // FULL
	}
	// Otherwise keep adding the player and increment the index
	arr[index].copy_player(name);
	// increment the index. 
	index ++;
	// set the current size of array to the index
	sizeArray = index;
	return 0;
}
void playerNode::getPlayers() const
{
	// loop through the array and get the player name
	for (int i = 0; i< sizeArray; i++)
	{
		// each i is the index of player in the array inside the node
		// loop through it and display it to the user
		arr[i].display_player();
	}
}
void playerNode::get_execution_player(int index, int move) {
	// setting the player move
	arr[index].set_move(move);	
}
int playerNode :: get_location_move( int index)
{
	// return the current move of the player
	// index will say which player we want to access in the node
	return arr[index].get_move();

}

void playerNode::players_reward(int index, char *rName) {
	
	// this will add the reward into assigned player
	// rName contains the reward
	// index will say which player we want to access to
	arr[index].add_rewards(rName);
}
void playerNode::display_rewards(int index)
{	
	// The player node will point to the node that contains the player
	// the index will tell which player we want to access to 
	arr[index].display_reward();	
}






// Implementing the rewardNode 
rewardNode::rewardNode () {
	// set the default next to NULL and all the default data memebers
	next = NULL;
	index = 0;
	maxSizeArray = 10;
	sizeArray = 0;
	// allocate  the array of char pointer 	
	rewardName = new char*[maxSizeArray];
	for ( int i = 0; i< maxSizeArray;i++)
	{
		// set the size of characters it can hold up to 150 
		rewardName[i] = new char[150];
		// set the default name of all the rewards to none
		strcpy(rewardName[i], "None");
	}
}
rewardNode:: rewardNode (int maxSize)
{
	// if we have the assiged size of array
	// we do the same thing like default constructor  
	// instead set the size of array to the max size
	next = NULL;
	index = 0;
	// assigned the maxSizeArray to maxSize
	this->maxSizeArray = maxSize;
	sizeArray = 0;
	rewardName = new char*[maxSize];
	// looping the array 
	for ( int i = 0; i< maxSize; i++)
	{	
		// setting the size of character to 150
		rewardName[i] = new char[150];
		strcpy(rewardName[i], "None");

	}


}
rewardNode::~rewardNode() {

	if (rewardName){ 
		for ( int i = 0; i < maxSizeArray; i++)
		{			
				delete [] rewardName[i];
				rewardName[i] = NULL;
		}
		delete [] rewardName;
		rewardName = NULL;
		next = NULL;
	}

}
void rewardNode::show_reward()  {
	std::cout << std::endl;
	// We use the for loop go through the rewardName array and print out the reward inside 
	// the array
	for (int i = 0; i< sizeArray; i++)
	{
		std::cout << i +1 << " . " ;	
		std::cout <<rewardName[i]<< std::endl;
	}

}
int rewardNode::set_data ( char *name ) {
	// pretty much the same thing with the function set data in player node class
	if (index == maxSizeArray)
	{
		index = 0;
		return 1; // FULL
	}
	// allocate the memory of rewardName array
	if (rewardName[index]) delete [] rewardName[index]; 
	rewardName[index] = new char[strlen(name) + 1];
	// copy the value of name over the index of rewardName
	strcpy(rewardName[index], name);
	// increement the index
	index ++;
	// set the size of array to the index
	sizeArray = index;
	return 0;

}

void rewardNode::set_next(rewardNode*connect) {
	// set the next to connect  
	next = connect;
}

char* rewardNode::show_one_reward() {
	// Extend the range of randomly from 1 to size Array
	int random = rand() % sizeArray + 1;
	if ( random == sizeArray ) return NULL; // This means no reward at that check point
	// return the reward with the type of char *
	// this return will then pass this data over the player when they step into one checkpoint
	return rewardName[random]; 		
}

























