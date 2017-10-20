// This class is to control the game 
#include "game.h"
game::game() {
	// Setting the cpn to NULL, cpi to 0 and had_rewads to NULL	
	this->cpn = NULL;
	cpi = 0;
	had_rewards = NULL;
	had_rewards = new bool[MAX_VERTEX];
	// meaning that player will not have the reward for the starting point	
	had_rewards[0] = true;
	for ( int i = 1; i < MAX_VERTEX; i++)
		had_rewards[i] = false; 
}

game::~game() {

	//	if (cpn)
	//	delete cpn;
	//	cpn = NULL;

	// deleting the array of bool
	delete [] had_rewards;
}


void game::generate_the_maze() {

	// calling the function random maze from map object
	map.random_maze();

}

void game::add_rewards (char *rewardName) 
{	
	// calling the reward function from rList through rList
	rList.insert_reward(rewardName);
}


void game::show_location_at_check_point(int index) {
	// display the function of the checkpoint through index
	map.display_checkpoint_location(index);	
}

bool game::isValid (int index, int checkpoint)
{
	// return true or false if the index 
	return map.is_there(index, checkpoint);

}
void game::player_options(int player_index, int location)
{
	std::cout << "Choose your actions before ending your turn "<<std::endl;
	std::cout << "(F) for seeing your teammates " <<std::endl;
	std::cout << "(R) for seeing the reward you might get " << std::endl;
	std::cout << "(L) for seeing your location right now " << std::endl;
	std::cout << "(C) for ignoring taking any action " << std::endl;	
	char choice = ' '; char re_choice = ' ';
	std::cin >> choice;
	if ( choice == 'F') 
	{	
		// Printing the list of teammates
		std::cout << "You are in the group of ";
		pList.display_groupName();	
		pList.display_players_in_group();
	}	
	if ( choice == 'R') 
	{
		// Printing the reward
		cpn = pList.get_head();		
		cpn->display_rewards(player_index);		

	}
	if ( choice == 'L') 
	{	

		std::cout << "You are at " << location << std::endl;
		//Printing the location 
	}
	if ( choice == 'C') {	
		return;
	}

	std::cout << "Do you want to take another action? (Y/N) : ";std::cin>>re_choice;
	if ( re_choice == 'Y')
		player_options(player_index,location); 


}
void game::add_player () {

	char y_n = ' ';
	char newName[100];
	char groupName[100];	
	bool is_done_adding = true;	
	do 
	{	
		std::cout << "Enter the player name: "; std::cin>>newName;	
		playersList.insert_player(newName);	
		pList.insert_player_special(newName, is_done_adding);			
		is_done_adding = false;
		std::cout << "Do you want to add more? (Y/N) "; 
		std::cin>>y_n;
	}while(y_n == 'Y');
	is_done_adding = true;	
	std::cout << "Let's put the name for your team: ";std::cin >> groupName;	
	pList.add_group_name(groupName);
	std::cout << "Do we have another group? (Y/N) " ;
	std::cin >> y_n;
	if (y_n == 'Y')	
		add_player();
	
	std::system("clear");	


}

void game::show_directions_to_player(int index) {

	map.display_directions(index);

}
void game::numbers_players_playing() {
	std::cout <<" In this game, there are "<<std::endl;
	playersList.display_players();


}
void game:: reward_initial() {

	// Creating the list of rewards for the games
	add_rewards( (char*)"You will get the head if you reach the final point");
	add_rewards( (char*)"You will be rewared 100 dollars if you are the first winner");
	add_rewards( (char*)"You will be rewared 1 cent if you are the first winner ");
	add_rewards((char*) "You will be rewared a computer science book made by Thong Tran");
	add_rewards((char*) "You will be rewared a keyboard ");
	add_rewards((char*) "You can have a new girl or boy friend when you are the first winner");
	add_rewards((char*) "You will pass CS 202 class. Yeah. Is that great ");
	add_rewards((char*) "Congratulation, A lamborgini is your ");
	add_rewards( (char*)"You will be rewared a pen if you reach the final point");
	add_rewards( (char*)"You will be rewared a pants if you reach the final point");	
	add_rewards( (char*)"You will be rewared a Macbook if you lose this game");
	add_rewards( (char*)"You have a free trip to Vietnam. OH YEAH");	
}
void game:: introduction () {

	std::cout << "///////////////////////////////////////////////////////////////////////////" <<std::endl;
	std::cout << "Welcome to the Maze Game!!!!!!!!!" << std::endl;
	std::cout << "The rule is easy. You will need to reach to the final point to be a winner " <<std::endl;
	std::cout << "Each point you passed might have the reward" << std::endl;
	std::cout << "The maxium number of players in your team is 5 "<< std::endl;
	std::cout << "Here is all possible rewards that you might get for each location you take"<<std::endl;
	rList.display_entire_rewards(); 
	std::cout << std::endl;
}


void game::play_game() {
	int player_move = 0;
	int winning_point = 19;
	reward_initial();
	// Introduction function 	
	introduction();
	// promting the user to have their name
	add_player();
	// Show the number of players are playing
	numbers_players_playing(); 
	//Get head 
	cpn = pList.get_head();	
	playerNode*temp = pList.get_head();	
	// after finishing the prompt. Let's get started to the game
	// set the cpn to be a head of the player list



	char * rewardName = NULL;

	// This loop will determine when the game terminates if it reaches to the last point
	while ( player_move != winning_point) {	
		int player_location_index =  cpn-> get_location_move(cpi);		
		std::cout << "Now it is turn of "; cpn->get_player(cpi); std::cout <<std::endl;	
		// Calling the random reward to add on 	
		rewardName = rList.random_pick();			
		std::cout << "You currently can go to point(s) ";
		// show all possible locations to the user
		show_directions_to_player(player_location_index);
		std::cout <<std:: endl;
		std::cout << "Enter your next move in interger: "; 	


		// We need to check for the apporiate input from the user 
		// We also need to check if the user's move is not valid
		do {	
			std::cin>>player_move;
			std::cin.ignore(100, '\n');
			if (isalpha(player_move))
			{
				std::cout << "Invalid input. Intergers only "; std::cin >> player_move;
			}
			else	if ( player_move > 19)
			{
				std::cout << "Wrong Input. Please try again ";
				std::cin>>player_move;	
				std::cin.ignore(100, '\n');
			}
			else if ( isValid (player_location_index, player_move) == false)
			{
				std::cout << "Your move is not valid. ";
				std::cin >> player_move;
				std::cin.ignore(100, '\n');	
			}	
		}while(player_move > 19 ||  isValid(player_location_index, player_move) == false); 


		// This if statement will check if that checkpoint has the reward
		// Or it will check if the user has not had any reward from that checkpoint
		// If it has no reward, display it to the user	
		if (!rewardName || had_rewards[player_move] == true){

			std::cout << "Sorry you do not have any reward for this location"<<std::endl;	
		}
		else {
			std::cout << "Here is the reward of this checkpoint:  "<<std::endl;
			// This will add the reward into the check point
			map.reward_checkpoint(player_location_index, rewardName);	
			// add the reward into the reward list of player
			cpn->players_reward(cpi,rewardName);	
			// Mark that player already visited that checkpoint and has a reward
			had_rewards[player_move] = true;	
		}
		// Asking the actions from player 
		player_options(cpi,player_move);	

		// We got the WINNER yeah!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if ( player_move == winning_point) { 
			std::cout << "Congratulation " ;
			// Print out the name of the player who wins the game
			cpn->get_player(cpi); 
			std::cout << "You have reach the final destination. Enjoy your victory ";

			std::cout << std::endl<< "Here is the complete maze: "; map.display_entire_graph();
			return;
		}


		//Calling the function to execute the move from the player 	
		cpn->get_execution_player (cpi, player_move);	
		cpi++; // moving to the next player in the array
		// Check if the index of player is at the end of the size of the node 

		if (cpi >= cpn->getSizeArray() ) {
			// cpn will now point to the different node	
			cpn = cpn->go_next();
			// reseting the index
			cpi = 0;
			// if the next node is NULL, we set the cpn back to current head
			if (!cpn) cpn = temp;
			// we check in the friends list class if the next node is not NULL
			// we move the head to the next node in order to access to each individual player
			// in the next node
			if (pList.get_head()->go_next() != NULL)	
				pList.get_head() = pList.get_head()->go_next();	
		}
		// clear the screen
		std::system("clear");	

	}

}
