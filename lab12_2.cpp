#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	int x = rand()%13+1,card;
	if(x == 1) card = 1;
	else if(x == 2) card = 2;
	else if(x == 3) card = 3;
	else if(x == 4) card = 4;
	else if(x == 5) card = 5;
	else if(x == 6) card = 6;
	else if(x == 7) card = 7;
	else if(x == 8) card = 8;
	else if(x == 9) card = 9;
	else if(x == 10) card = 10;
	else if(x == 11) card = 11;
	else if(x == 12) card = 12;
	else if(x == 13) card = 13;
    return card;
}

int calScore(int x,int y,int z){

	if(x == 11 ){
		x = 0;
	}else if(x == 12){
		x = 0;
	}else if(x == 13){
		x = 0;
	}else if(y == 11){
		y = 0;
	}else if(y == 12){
		y = 0;
	}else if(y == 13){
		y = 0;
	}else if(z == 11){
		z = 0;
	}else if(z == 12){
		z = 0;
	}else if(z == 13){
		z = 0;
	}
	int score = 0+x+y+z;
	if(score >= 10){
		score -= 10;
	}else if(score >= 20){
		score -= 20;
	}
	return score;
}

int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1;
	else{
		int prob = rand()%100;
		if(prob < 69){
			return 1;
		}else{
			return 2;
		}
	}
}

void checkWinner(int p, int y){

	cout << "\n---------------------------------\n";
	if(p == y){
		cout <<   "|             Draw!!!           |"; 
	}else if(p > y){
		cout <<   "|         Player wins!!!        |"; 
	}else{
		cout <<   "|          Yugi wins!!!         |"; 
	}
	cout << "\n---------------------------------\n";
}

int main(){	
	int playerScore, yugiScore, playerAction, yugiAction,playerNew,yugiNew;
	srand(time(0));
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(),drawCard(), 0}; //This line of code is not completed. You need to initialize value of yugiCards[].
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2); //This line of code is not completed. You need to set the condition to do loop if user's input is not 1 or 2. 
	if(playerAction == 1){
		
		cout << "Player draws the 3rd card!!!" << "\n";
		playerCards[2] = drawCard();
		playerNew = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
		if(playerNew >= 10){
			playerNew -= 10;
		}else if(playerNew >= 20){
			playerNew -= 20;
		}
		cout << "Your new score: " << playerNew << "\n";
			
		playerScore = playerNew;
	
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2] = drawCard();
		yugiNew = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] << "\n";
		if(yugiNew >= 10){
			yugiNew -= 10;
		}else if(yugiNew >= 20){
			yugiNew -= 20;
		}
		cout << "Yugi's new score: " << yugiNew << "\n";
		
		yugiScore = yugiNew;
	}
	cout << "------------ Turn end -------------------\n";
	
	checkWinner(playerScore,yugiScore);
}
