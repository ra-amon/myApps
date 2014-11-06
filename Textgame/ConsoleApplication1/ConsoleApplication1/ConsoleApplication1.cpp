// made by Ramon Sloos
//Contact: Ramonsloos@gmail.com
//Name: simpel text game.
// goal: Explore the use of vectors.

#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;
#include <vector>  //include the vector to use

// end score
int score;
// a struct for the thing the players have to enter
struct Input{
	 string thing;
};

vector<Input>ThingsYouLove; //the name of the vector

int _tmain(int argc, _TCHAR* argv[]) //like setup
{
	int score=0;
	for(int x = 0; x< 11; x++){
		Input c;
		c.thing;
		ThingsYouLove.push_back(c);
	}
	//instructions for the player
	cout<<"..............................Enter 5 things you love..........................."<< endl;
	cout<<"...............Type it in by useing the keyboard and press Enter................"<< endl;
	getline(cin,ThingsYouLove[1].thing); //how the player can enter the thing they love
	
	getline(cin, ThingsYouLove[2].thing);
	
	getline(cin,ThingsYouLove[3].thing);

	getline(cin, ThingsYouLove[4].thing);

	getline(cin, ThingsYouLove[5].thing);
	//backspace
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	//end blackspace
	cout<<"..............................Now its player two its turn......................"<< endl;
	cout<<"......................Guess the 5 things he or she loved......................"<< endl;
	
	getline(cin,ThingsYouLove[6].thing);
	//forloop for checking all the options that you have filled in
	for(int x=1; x<6; x++){
		
		if(ThingsYouLove[6].thing==ThingsYouLove[x].thing){
			cout <<"..............................Good JOP!....................."<<endl; //feedback player
         score++; // score counter
		}
	}

	getline(cin, ThingsYouLove[7].thing);
		for(int x=1; x<6; x++){
		
		if(ThingsYouLove[7].thing==ThingsYouLove[x].thing){
			cout <<"..............................Good JOP!....................."<<endl;
         score++;
		}
	}
	getline(cin,ThingsYouLove[8].thing);
		for(int x=1; x<6; x++){
		
		if(ThingsYouLove[8].thing==ThingsYouLove[x].thing){
			cout <<"..............................Good JOP!....................."<<endl;
         score++;
		}
	}
	getline(cin, ThingsYouLove[9].thing);
		for(int x=1; x<6; x++){
		
		if(ThingsYouLove[9].thing==ThingsYouLove[x].thing){
			cout <<"..............................Good JOP!....................."<<endl;
         score++;
		}
	}
	getline(cin, ThingsYouLove[10].thing);
		for(int x=1; x<6; x++){
		
		if(ThingsYouLove[10].thing==ThingsYouLove[x].thing){
			cout <<"..............................Good JOP!....................."<<endl;
         score++;
		}
	}
		//end game
		//cout the score 
		cout<< ""<< endl;
		cout << "..............................Your score is:.............................."<<endl;
		cout << score << endl;

	return 0;
}


