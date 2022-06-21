#include "stdafx.h"
#include "mode.h"
#include "DxLib.h"
#include "time.h"
#include "input.h"
#include "dropshape.h"
#include "game.h"

int type = 2;
static shape shape1;

int type_return( ) { 
	
	return type;
}
int rando(int xc ) { 
	xc = GetRand(600 );
	return xc;
}

void _circle(bool hit ,int yaa) {

	//type = change_arm( );
	switch ( type ) {
	case Circle:
	{
		DrawCircle( shape1.x88 + 100, shape1.y88, 20, GetColor( 100, 0, 0 ), true );
		break;
	}
	case Box:
	{
		DrawBox( shape1.x88+80, shape1.y88-20, shape1.x88+120, shape1.y88+20, GetColor( 100, 0, 0 ), TRUE );

		break;

	}
	case Triangle:
	{
		DrawTriangle( shape1.x88 + 80, shape1.y88+20, shape1.x88+120 , shape1.y88+20, shape1.x88+100, shape1.y88-20, GetColor( 100, 0, 0 ), TRUE );
		break;
	}
}

	
	if (  shape1.y88 >= 900 ) {
		shape1.x88 = rando( shape1.x88 );
		shape1.y88 = -90;
		type = GetRand( 2 );
	} else if(hit == false) {
	
		shape1.y88 += 3;
	} else if ( hit == true &&  type == change_arm() ) {
	
		shape1.y88 = yaa;
	
	}

	if ( shape1.y88 > 680 && hit == true  ) {
		shape1.x88 = rando( shape1.x88 );
		shape1.y88 = -90;
	
		type = GetRand( 2);
	}
}

int gethity(bool i ) {
	if ( i ) { 
		shape1.y88 = 0;
	}
	return shape1.y88;

}
int gethitx( ) {

	return shape1.x88;

}
