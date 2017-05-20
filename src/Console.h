#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h>
#include <iostream>

static const int row = 29;
static const int col = 90;

extern char map[row][col];

struct position { //Position struct that determine coordinates on the map
	int x, y;
};



class food_cls {  //foof class 
protected:
	position pos;
	char symbol;
public:
	food_cls() : symbol('X'), pos() {
		pos.x = pos.y = -1;
	}

	void set_pos(int x, int y) {
		pos.x = x;
		pos.y = y;
		map[y][x] = symbol;
	}

	void reposition(char field[][col]);

	int get_x() const { return pos.x; }
	int get_y() const { return pos.y; }
	char get_symbol() const { return symbol; }
};


class snake_cls {  //Snake Class
	enum { UP, DOWN, LEFT, RIGHT } dir;
	char symbol, head_symbol;
	position pos[100];
	position & head;
	int speed;
	int size;
	bool can_turn;
public:
	snake_cls(int x, int y) :
		symbol('o'), head_symbol('>'), pos(),
		speed(1), size(3), dir(RIGHT),
		head(pos[0]), can_turn(true)
	{
		pos[0].x = x;
		pos[0].y = y;
	}
	void setHead(char r) { head_symbol=r;}
	bool check_food(const food_cls & food);

	void get_input(char field[][col]);

	void move(char field[row][col]); 

	void draw(char field[][col]); 
	int get_x() const { return head.x; }
	int get_y() const { return head.y; }
	char get_symbol() const { return symbol; }
	int get_Size() const { return size; }
};

#endif // !CONSOLE_H


