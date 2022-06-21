#include "stdafx.h"
#include "result.h"
#include "game.h"
#include "DxLib.h"
#include "mode.h"
#include "input.h"
#include "time.h"

bool win = true;
int ReFont;
int ruletext23;
int datasc[ 10 ] = {0};
void height( ) { 
	for ( int i = 0; i < 10;i++ ) {
		if ( datasc[ i ] < score( ) ) {
			datasc[ i ] = score( );
			break;
		}
	}

}
int resultInt( ) { 
	ReFont = CreateFontToHandle( NULL, 60, 1 );
	height();
	ruletext23 = CreateFontToHandle( NULL, 30, 1 );
	return modeseq_Increase;
}

void save( ) { 
	//FILE* f;
	//person sco;	
	//char name[ 100 ] = "sadsad";
	////DrawFormatString( 0, 0, GetColor( 255, 255, 255 ), ( const TCHAR* )"Name" );
	//fopen_s( &f, "sc.txt", "w" );
	//if ( f == NULL ) {
	//	DrawFormatString( 0, 32, GetColor( 255, 255, 255 ), ( const TCHAR* )"ファイルをオープンできません。" );
	//} else {
	//	fprintf( f, "%s\t%.d\n", sco.name, sco.sco1);
	//	DrawFormatString( 0, 32, GetColor( 255, 255, 255 ), ( const TCHAR* )"%s : %d",name,score() );

	//}
	FILE* f;
	fopen_s( &f, "sc.txt", "wt" );
	fprintf( f, "%d:%02d", 2 - _return_sec( ) / 60, 59 - _return_sec( ) % 60 );
	fclose( f );
#if DEBUG
	
	
		DrawFormatString( 0, 16, GetColor( 255, 255, 255 ), ( const TCHAR* )"%d:%02d", 2 - _return_sec( ) / 60, 59 - _return_sec( ) % 60 );

	
#endif
}


int resultDis( ) { 
	int i = 0;
	if (i ==0 ) {
		save( );
		i++;
	}
	

	//DrawFormatStringToHandle( 430, 300, GetColor( 255, 255, 255 ), ReFont, ( const TCHAR* )"SCORES : %d" , score( ));//Title Text
	if ( _return_win() == true ) {
		DrawOval( 600, 330, 450, 100, GetColor( 255, 0, 255 ), TRUE );
		DrawFormatStringToHandle( 320, 300, GetColor( 255, 255, 255 ), ReFont, ( const TCHAR* )"TIME REMAINING : %d:%d", 2 - _return_sec( ) / 60, 59 - _return_sec( ) % 60 );//Title Text
		DrawBox( 800, 800, 1150, 880, GetColor( 255, 255, 255 ), FALSE );
		DrawFormatStringToHandle( 910, 825, GetColor( 255, 255, 255 ), ruletext23, ( const TCHAR* )"Return To Title" );
		DrawBox( 800, 800, 900, 880, GetColor( 255, 255, 255 ), FALSE );
		DrawFormatStringToHandle( 810, 825, GetColor( 255, 255, 255 ), ruletext23, ( const TCHAR* )"SPACE" );
	} else {
		DrawOval( 600, 330, 450, 100, GetColor( 255, 0,0 ), TRUE );
		DrawFormatStringToHandle( 450, 300, GetColor( 255, 255, 255 ), ReFont, ( const TCHAR* )"GAME OVER" );//Title Text
		DrawBox( 800, 800, 1150, 880, GetColor( 255, 255, 255 ), FALSE );
		DrawFormatStringToHandle( 910, 825, GetColor( 255, 255, 255 ), ruletext23, ( const TCHAR* )"Return To Title" );
		DrawBox( 800, 800, 900, 880, GetColor( 255, 255, 255 ), FALSE );
		DrawFormatStringToHandle( 810, 825, GetColor( 255, 255, 255 ), ruletext23, ( const TCHAR* )"SPACE" );
	}

	   

	if ( getKeyboardOnTrigger( KEY_INPUT_SPACE ) ) {

		return modeseq_Return;
	}
	return 0;
}