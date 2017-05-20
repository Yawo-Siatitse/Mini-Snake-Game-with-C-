// myGame.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" //comment if not using Visual Studio
#include "Console.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include<string>


int speed = 50;  //speed of the snake 
using namespace std;
int score = 0; //score


void clearScreen();
void welcome();
void load();
void saveScore();



int main() {
	welcome();  //printing instructions 
	cin.get();
	system("cls");
	load();
	cin.get();

	food_cls food; 
	snake_cls snake(3,3); //creating a new snake object
	
	
	system("cls");

	food.reposition(map); 

	while (1) {
		

		snake.get_input(map);
		try {
			snake.move(map);
		}
		catch (const char * er) {
				system("cls");
				cerr << er << endl;
				system("pause");
				saveScore();
				system("pause");
				return -1;
			
		}
		snake.draw(map);
		


		if (snake.check_food(food)) {
			food.reposition(map);
			score++;
		}
		
		cout << "SCORE: " << score << endl;
		for (int i = 0; i < row; i++) {
			cout << map[i]<<endl;
		}
		
		clearScreen(); //setting cursor to the begining of console
		if (snake.get_Size() % 10 == 0) //Increasing the speed of the game after every ten food eaten
			speed -= 20;
		Sleep(speed);
	}

	


	return 0;
}

void clearScreen() //Setting cursor at the begining of the console
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}


void welcome()// Intructions 
{
	cout<<"\tWelcome to the mini Snake game.(press any key to continue)\n";

	cin.get();

	system("cls");

	cout<<"\tGame Play Instructions:\n";

	cout << "\n-> Use arrow keys to move the snake.\n\n"
		<< "-> You will be provided food blobs at the several coordinates of the screen which you have to make your snake eat. "
		<< "Everytime you eat a food the length of the snake will be increased by 1 element and thus the score."
		<< "\n\n-> Game is over when you hit the wall or snake's body.";


	cout <<"\n\nPress any key to continue...";
}

void load() {   //Displaying the loading stimulation 
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 36;
	Position.Y = 14;
	SetConsoleCursorPosition(hOut, Position);

	int r, q;
	unsigned char ch = 177;
	cout<<"loading..."<<endl;
	Position.X = 30;
	Position.Y = 15;
	SetConsoleCursorPosition(hOut, Position);
	for (r = 1;r <= 20;r++) {
		for (q = 0;q <= 100000000;q++);//to display the character slowly
		cout<<ch;
	}
	Position.X = 30;
	Position.Y = 17;
	SetConsoleCursorPosition(hOut, Position);
	cout << "Press any key to start!" << endl;
	
}

void saveScore()  // Checking out if record is broken by current player
{
	struct SCORE{
		string name;
		short score;
	} high;
	struct SCORE current;

	ifstream record;
	record.open("record.txt");
	record >> high.name >> high.score;
	record.close();
	system("cls");
	cout << "Enter you fisrt name: ";
	cin >> current.name;
	current.score = score;
	if (current.score > high.score) {
		high = current;
	}

	cout << "Your Score: \n"
		<< current.name << "  " << current.score << endl;
	cout << "\nHighest Score: \n"
		<< high.name << "  " << high.score << endl;
	ofstream newR;
	newR.open("record.txt");
	newR<< high.name << "  " << high.score << endl;  //Updating highest score data file
	newR.close();
}
