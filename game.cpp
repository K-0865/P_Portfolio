#include "stdafx.h"
#include "mode.h"
#include "DxLib.h"
#include "game.h"
#include "time.h"
#include "input.h"
#include "dropshape.h"
#include "math.h"
static clock_t sec;
int ScoreText;
int armtext;
bool reset = false;
int img;
int min;
int sec2;
static clock_t startTm;
static pos pos1;
static pos pos2;
bool hit = false;
bool down = false;
int yc = 0;
int xc = rando( xc );
bool shapehit = false;
int sc = 0;
int pointx, pointy;
bool winornot;

int digit(int n ) { 
	int count = 0;
	if ( n == 0 ) {

		return 1;
	}
	while ( n != 0 ) {
		n = n / 10;
		++count;
	}
	
	return count;

}
void armdraw( int y ) {
	 pos1.y4 = y - 150;
	 pos1.invibx = pos1.x - 40;
	 pos1.invibx2 = pos1.x + 40;
	 pos1.inviby = y - 110;
	 pos1.inviby2 = y - 135;
	DrawBox( pos1.x - 50, y - 100, pos1.x + 50, y - 110, GetColor( 255, 255, 255 ), TRUE );
	DrawBox( pos1.x - 2, y + 10, pos1.x + 2, y - 110, GetColor( 255, 255, 255 ), TRUE );
	DrawBox( pos1.x - 50, y - 100, pos1.x - 40, pos1.y4, GetColor( 255, 255, 255 ), TRUE );
	DrawBox( pos1.x + 40, y - 100, pos1.x + 50, pos1.y4, GetColor( 255, 255, 255 ), TRUE );
	DrawBox( pos1.invibx, pos1.inviby, pos1.invibx2, pos1.inviby2, GetColor( 0, 0, 0 ), TRUE ); // invi box
}
int gameInt() {
	pos1 = pos2;
	reset = true;
	gethity( reset );
	reset = false;
	min = 2;
	sec2 = 00;
	SetBackgroundColor( 0, 0, 0 );
	ScoreText = CreateFontToHandle( NULL, 40, 1 );


	startTm = clock();
	img = LoadGraph("img.png");
	pos1.y2 = 100;
	return modeseq_Increase;


}
void scoreDis( ) { 

	if (sec % 60 == 0 ) { 
		sec2 = 59;
	
	}
	DrawBox( 800, 0, 1200, 900, GetColor( 255, 255, 255 ), TRUE );
	//Score
	DrawFormatStringToHandle( 950, 20+300, GetColor( 0, 0, 0 ), ScoreText, ( const TCHAR* )"SCORES" );//Title Text
	DrawBox( 810, 80+300, 1190, 200+300, GetColor( 0, 0, 0 ), FALSE );
	DrawFormatStringToHandle( 1000 - ( digit( sc ) * 20 ), 125+300, GetColor( 0, 0, 0 ), ScoreText, ( const TCHAR* )"%d / 3000", sc );//Title Text
	//------------------//
	sec = ( clock( ) - startTm ) / CLOCKS_PER_SEC; //TIME
	DrawFormatStringToHandle( 950, 20 , GetColor( 0, 0, 0 ), ScoreText, ( const TCHAR* )"TIME" );//Title Text
	DrawBox( 810, 80, 1190, 200 , GetColor( 0, 0, 0 ), FALSE );
	DrawFormatStringToHandle( 950, 125, GetColor( 0, 0, 0 ), ScoreText, ( const TCHAR* )"%02d:%02d", min-sec / 60, sec2-sec%60 );//Title Text

}
int score() {
	

	

	return sc;
}
int change_board( ) { 
	DrawBox( 850 - 40, 600 - 40, 1150 + 40, 850 + 40, GetColor( 156, 156, 156 ), TRUE );
	DrawBox( 850 - 40, 600 - 40, 1150 + 40, 610 + 40, GetColor( 110, 110, 110 ), TRUE );//title
	DrawFormatStringToHandle( 920, 590, GetColor( 0, 0, 0 ), ScoreText, ( const TCHAR* )"ARM Type" );//Title Text
	DrawBox( 990 - 40, 690 - 40, 1010 + 40, 710 + 40, GetColor( 255, 255, 100 ), TRUE );

	switch ( pos1.state ) {
	case Circle:
	{
		DrawCircle(1000, 700, 40.0f, GetColor( 255, 0, 0 ), TRUE ); //top
		DrawBox( 900 - 40, 800 - 40, 900 + 40, 800 + 40, GetColor( 255, 0, 0 ), TRUE );//left
		DrawTriangle( 1100, 800 - 40, 1100 + 40, 800 + 40, 1100 - 40, 800 + 40, GetColor( 255, 0, 0 ), TRUE );//right
		return  Circle;
		break;


	}
	case Box:
	{
		DrawCircle( 1100, 800, 40.0f, GetColor( 255, 0, 0 ), TRUE );
		DrawBox( 1000 - 40, 700 - 40, 1000 + 40, 700 + 40, GetColor( 255, 0, 0 ), TRUE );
		DrawTriangle( 900, 800 - 40, 900 + 40, 800 + 40,900 - 40, 800 + 40, GetColor( 255, 0, 0 ), TRUE );
		return  Box;
		break;
	}
	case Triangle:
	{
		DrawCircle( 900, 800, 40.0f, GetColor( 255, 0, 0 ), TRUE );
		DrawBox( 1100 - 40, 800 - 40, 1100 + 40, 800 + 40, GetColor( 255, 0, 0 ), TRUE );
		DrawTriangle( 1000, 700 - 40, 1000 + 40, 700 + 40, 1000 - 40, 700 + 40, GetColor( 255, 0, 0 ), TRUE );
		return  Triangle;
		break;
	}
	}


}
void draw() {
	
	armdraw(pos1.y3 );
	change_arm( );
	change_board( );

}
int change_arm( ) { 


	switch (pos1.state ) {
	case Circle:
	{
		DrawCircle( pos1.x, pos1.y, 40.0f, GetColor( 255, 0, 0 ), TRUE );
		return  Circle;
		break;
		

	}
	case Box:
	{
		DrawBox( pos1.x - 40, pos1.y - 40, pos1.x + 40, pos1.y + 40, GetColor( 255, 0, 0 ), TRUE );
		return  Box;
		break;
	}
	case Triangle:
	{
		DrawTriangle( pos1.x, pos1.y - 40, pos1.x + 40, pos1.y + 40, pos1.x - 40, pos1.y + 40, GetColor( 255, 0, 0 ), TRUE );
		return  Triangle;
		break;
	}
	}
	
}
void move( ) {
	//if ( getKeyboardOnTrigger( KEY_INPUT_UP ) == 1 && hit == false ) {

	//	pos1.state = ( pos1.state + 1 ) % 3;

	//} else if ( getKeyboardOnTrigger( KEY_INPUT_DOWN ) == 1 && hit == false ) {
	//	if ( pos1.state == 0 ) {
	//		pos1.state = 2;

	//	} else {
	//		pos1.state = ( pos1.state - 1 ) % 3;
	//	}
	//}
	if ( getKeyboardOnTrigger( KEY_INPUT_LEFT ) == 1 && hit == false ) {

		pos1.state = ( pos1.state + 1 ) % 3;

	} else if ( getKeyboardOnTrigger( KEY_INPUT_RIGHT ) == 1 && hit == false ) {
		if ( pos1.state == 0 ) {
			pos1.state = 2;

		} else {
			pos1.state = ( pos1.state - 1 ) % 3;
		}
	}
	//if ( getKeyboardState(KEY_INPUT_LEFT) == 1 && hit == false) {
	//	if (pos1.x < 50) {
	//		pos1.x = 50;
	//	}
	//	else if (pos1.x > 0 ) {
	//		pos1.x -= 8;
	//	}
	//	

	//}
	
		if (  hit == false ) {
		
			GetMousePoint( &pointx, &pointy );
			pos1.x = pointx % 900;
		}

	
	//if ( getKeyboardState(KEY_INPUT_RIGHT) == 1 && hit == false) {
	//	if (pos1.x > 750) {
	//		pos1.x = 750;
	//	}
	//	else if ( pos1.x < 750) {
	//		pos1.x += 8;
	//	}

		
	//}
	/*
	if ( getKeyboardOnTrigger(KEY_INPUT_SPACE) == 1 && hit == false) {
		
		hit = true;
			
	}*/	
	if ( ( GetMouseInput( ) & MOUSE_INPUT_LEFT ) != 0 == 1 && hit == false) {
		
		hit = true;
			
	}
	//if ( CheckHitKey( KEY_INPUT_SPACE ) == 0 && hit == false) 
	if ( hit == false) 
	{
		
		pos1.y3 = 820;
		shapehit = false;
		
	}
	if (hit == true  && down == false) { 
		
	
		
			
				DrawBox( pos1.x - 2, pos1.y, pos1.x + 2, pos1.y3, GetColor( 255, 255, 255 ), TRUE );

				pos1.y3 -= 5;
			
				
				//if ( gethity( reset ) >= ( pos1.inviby + pos1.inviby2 ) / 2 && gethitx( ) + 100 >= pos1.invibx && gethitx( ) + 100 <= pos1.invibx2 && type_return( ) == change_arm( ) ) {
				if ( gethity( reset ) >= ( pos1.inviby + pos1.inviby2)/2  && gethitx( ) + 100 >= pos1.invibx && gethitx( ) + 100 <= pos1.invibx2 && type_return( ) == change_arm( ) && gethity(reset) < 750) {
				shapehit = true;
				down = true;
				sc += 100+GetRand(50 );;
				}
				

	if ( pos1.y4 < 5 ) { down = true; }

	
	}
	if ( down == true && hit == true ) //Get it
	{
		

			DrawBox( pos1.x - 2, pos1.y, pos1.x + 2, pos1.y3, GetColor( 255, 255, 255 ), TRUE );

			pos1.y3 += 8;

			if ( pos1.y3 > 810 ) {
				hit = false;
				down = false;				
			}

	
	}
	if ( (GetMouseInput( ) & MOUSE_INPUT_RIGHT ) != 0 && hit == true && down == false ) {

		down = true;
	}
	/*if ( getKeyboardOnTrigger( KEY_INPUT_LSHIFT ) == 1 && hit == true && down == false ) {
	
		down = true;
	}*/

}
int gameDis() {

	
	scoreDis();
	move( );
	draw();
	_circle(shapehit, ( pos1.inviby + pos1.inviby2 ) / 2 );
	if (  sc >= 3000) {
		winornot = true;
		return modeseq_Increase;
	} else if( sec >= 179){
		winornot = false;
		return modeseq_Increase;
	}


#if DEBUG


	
	DrawFormatString(0, 15, GetColor(255, 255, 255), (const TCHAR*)"Pos X: %d", pos1.x);
	DrawFormatString(0, 30, GetColor(255, 255, 255), (const TCHAR*)"TIME: %02d:%02d", sec/60,sec%60);
	DrawFormatString(0, 45, GetColor(255, 255, 255), (const TCHAR*)"Shape Pos Y: %d", gethity(reset));
	DrawFormatString(0, 60, GetColor(255, 255, 255), (const TCHAR*)"Shape Pos X: %d", gethitx()+100);
	DrawFormatString(0, 75, GetColor(255, 255, 255), (const TCHAR*)"Stick Pos Y: %d", pos1.y3 );
	DrawFormatString(0, 90, GetColor(255, 255, 255), (const TCHAR*)"Shape Hit: %d", shapehit );
	DrawFormatString(0, 105, GetColor(255, 255, 255), (const TCHAR*)"Invi Box X: %d", pos1.invibx );
	DrawFormatString(0, 120, GetColor(255, 255, 255), (const TCHAR*)"Invi Box X2: %d", pos1.invibx2 );
	DrawFormatString(0, 135, GetColor(255, 255, 255), (const TCHAR*)"Shape Type: %d", type_return() );
	DrawFormatString(0, 150, GetColor(255, 255, 255), (const TCHAR*)"Arm Type: %d", pos1.state );
#endif
	return 0;
}
int _return_min( ) {
	return min;
}
int _return_sec( ) {
	return sec;
}
bool _return_win( ) {
	return winornot;
}