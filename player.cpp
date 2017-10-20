
#include "player.h"
using namespace std;
player::player () {
	
	rList = NULL;
	this->current_index = 0; 
 	name = new char[20];	
	strcpy(name, "none");
	this->sizeArray = 0;	
	rList = new char * [MAX_VERTEX];
	
	for ( int i = 0; i < MAX_VERTEX; i++)
		rList[i] = new char [100];	


}
void player::set_move(int move_index) 
{

	// setting the index move to the player's location index
  this->current_index = move_index;


}
player::player(char* newName) {
	this->current_index = 0;
	copy_player(newName);
}

player::~player()
{
	// delete name
	delete [] name;
	for ( int i = 0; i < MAX_VERTEX; i++)
	{
		delete [] rList[i];
	}
	delete [] rList;

}
player::player(const player& to_copy) {

	// We are going to pass the copy 
	deep_copy(to_copy);
}
void player::display_location (int index) {

	location[index].print_location();	
}
void player::copy_player (char *playerName) 
{

	if (name) delete [] name;
	name = new char [strlen(playerName) + 1];
	strcpy(name, playerName);

}
void player::deep_copy( const player & newName ) 
{
	if (name) delete [] name;
	name = new char [strlen(newName.name) + 1];
	strcpy(name, newName.name);

}
void player::display_player() const  {
	cout << " Name: " << name << endl;

}
void player::display_reward() 
{
	// if nothing in the list, need to display it to the user
	if (sizeArray == 0) 
	{
		std::cout << "Your list is empty " << std::endl;
		return; 	
	}
	// Goes through the loop and output it
	for ( int i = 0 ; i < sizeArray; i++)
	std::cout << rList[i] << std::endl;

}
	

void player:: add_rewards(char * rewardName) {
	
	// Copy the rewadrd name opver 
	if (rList[sizeArray]) delete []  rList[sizeArray];	
	rList[sizeArray] = new char [strlen(rewardName) + 1];
	strcpy(rList[sizeArray], rewardName);
	sizeArray ++;
	// each player will have the maxium of 20 rewards beacause they go to 20 different points	
	if ( sizeArray == 20) return;		
	
}
