//#include "stdafx.h"
#include "Console.h"
#include <time.h>

extern char map[row][col] = {// Game map
//	"															                              ",
	"#########################################################################################",
	"#                                                                                       #",
	"#                                                                                       #",
	"#                                                                                       #",
	"#          #############           ################           ##############            #",
	"#          #                       #                          #                         #",
	"#          #                       #                          #                         #",
	"#          #                       #                          #                         #",
	"#          #                       #                          #                         #",
	"#          #                       #                          #                         #",
	"#          ############            #                          ##############            #",
	"#          #                       #                          #                         #",
	"#          #                       #                          #                         #",
	"#          #                       #                          #                         #",	
	"#          #                       #                          #                         #",
	"#          #                       #                          #                         #",
	"#          #                       #                          #                         #",
	"#          #############           ################           ##############            #",
	"#                                                                                       #",
	"#                                                                                       #",
	"#                                                                                       #",
	"##################################                 ######################################",
	"#                                                                                       #",
	"#                                                                                       #",
	"#                                                                                       #",
	"#                      ########################################                         #",
	"#                                                                                       #",
	"#                                                                                       #",
	"#########################################################################################",
};


void food_cls::reposition(char field[][col]) //food generator
{
	srand((unsigned)time(NULL));
	do {
		pos.x = rand() % col;
		pos.y = rand() % row;
	} while (field[pos.y][pos.x] != ' ');
	set_pos(pos.x, pos.y);
}


void snake_cls::draw(char field[][col])
{
	for (int c = 0; c < size; ++c) {
		if (c == 0) {
			field[pos[c].y][pos[c].x] = head_symbol; //print head symbol
		}
		else {
			field[pos[c].y][pos[c].x] = symbol;  //print body symbol 
		}
	}
}

void snake_cls::move(char field[row][col]) {  //This method handle the ovement of the snake
	position next = { 0, 0 };
	switch (dir) {
	case UP:
		next.y = -speed;
		setHead('^');
		break;
	case DOWN:
		next.y = speed;
		setHead('v');
		break;
	case LEFT:
		next.x = -speed;
		setHead('<');
		break;
	case RIGHT:
		next.x = speed;
		setHead('>');
	}
	map[pos[size - 1].y][pos[size - 1].x] = ' ';
	for (int c = size - 1; c > 0; --c) {
		pos[c] = pos[c - 1];

	}

	head.x += next.x;
	head.y += next.y;

	if (field[head.y][head.x] == '#'|| field[head.y][head.x] == 'o') {//Game over handler
		throw "G A M E   O V E R !!!!";
	}
}

void snake_cls::get_input(char field[][col]) {  //get direction of fro the Keyboard
	if (GetAsyncKeyState(VK_UP) && dir != DOWN) {
		dir = UP;
	}
	if (GetAsyncKeyState(VK_DOWN) && dir != UP) {
		dir = DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT) && dir != RIGHT) {
		dir = LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) && dir != LEFT) {
		dir = RIGHT;
	}
}

bool snake_cls::check_food(const food_cls & food) {  //CHeck in the snake eat a food
	if (food.get_x() == head.x && food.get_y() == head.y) {
		size += 1;
		return true;
	}
	return false;
}





