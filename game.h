#pragma once


void draw();
void move();
int score();
int change_arm( );

int gameDis();
int gameInt();
int _return_sec();
int _return_min();
bool _return_win();
enum {
	Circle = 0,
    Box = 1,
		Triangle = 2,
};

typedef struct pos {
	unsigned int state = 0;
	int invibx = 0;
	int invibx2 = 0;
	int inviby = 0;
	int inviby2 = 0;
	int x = 100;
	int y = 820;
	int y4;
	int y2;
	int y3 = 820;

};