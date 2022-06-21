#include "stdio.h"
#include "DxLib.h"
#include "rule.h"
#include "mode.h"
#include "input.h"
#include "game.h"
int ruleTitle;
int ruletext;
int ruletext2;

int ruleInt( ) {

	ruleTitle = CreateFontToHandle( NULL, 50, 1 );
	ruletext = CreateFontToHandle( NULL, 40, 1 );
	ruletext2 = CreateFontToHandle( NULL, 30, 1 );
	SetBackgroundColor( 255, 0, 0 );
	return modeseq_Increase;

}


int ruleDis( ) { 
	
	DrawFormatStringToHandle( 500, 50, GetColor( 255, 255, 255 ), ruleTitle, ( const TCHAR* )"���[������" );
	DrawFormatStringToHandle( 120, 200, GetColor( 255, 255, 255 ), ruletext, ( const TCHAR* )" �~���Ă���}�`���˂���āA������O��GET���悤�I\n\n�c��̎��Ԃ�0�ɂȂ�O�ɁA�X�R�A��B������΃N���A!\n" );
	DrawFormatStringToHandle( 500, 450, GetColor( 255, 255, 255 ), ruletext2, ( const TCHAR* )" �ړ�                ���}�E�X����" );
	DrawFormatStringToHandle( 500, 550, GetColor( 255, 255, 255 ), ruletext2, ( const TCHAR* )" �}�`�̃L���b�`      �����N���b�N" );
	DrawFormatStringToHandle( 500, 650, GetColor( 255, 255, 255 ), ruletext2, ( const TCHAR* )" �L���b�`���[�ϐg    �������L�[�̍��E" );
	DrawBox( 880, 800, 1190, 880, GetColor( 255, 255, 255 ), FALSE );
	DrawFormatStringToHandle( 900, 825, GetColor( 255, 255, 255 ), ruletext2, ( const TCHAR* )"SPACE" );
	DrawBox( 880, 800, 1000, 880, GetColor( 255, 255, 255 ), FALSE );
	DrawFormatStringToHandle( 1050, 825, GetColor( 255, 255, 255 ), ruletext2, ( const TCHAR* )"START" );

	DrawBox( 20, 800, 330, 880, GetColor( 255, 255, 255 ), FALSE );
	DrawBox( 20, 800, 140, 880, GetColor( 255, 255, 255 ), FALSE );
	DrawFormatStringToHandle( 40, 825, GetColor( 255, 255, 255 ), ruletext2, ( const TCHAR* )"ESC" );
	DrawFormatStringToHandle( 190, 825, GetColor( 255, 255, 255 ), ruletext2, ( const TCHAR* )"BACK" );
	{ 
		DrawBox( 200 - 50, 650 - 100, 200 + 50, 650 - 110, GetColor( 255, 255, 255 ), TRUE );
		DrawBox( 200 - 2, 650 + 10, 200 + 2, 650 - 110, GetColor( 255, 255, 255 ), TRUE );
		DrawBox( 200- 50, 650 - 100, 200 - 40, 650-150, GetColor( 255, 255, 255 ), TRUE );
		DrawBox( 200 + 40, 650 - 100, 200 + 50, 650-150, GetColor( 255, 255, 255 ), TRUE );
		DrawCircle( 200, 650, 40.0f, GetColor( 0, 0, 0 ), TRUE );
		
	}
	if ( getKeyboardOnTrigger( KEY_INPUT_SPACE ) == 1 ) {

		return modeseq_Increase;
	} else if( getKeyboardOnTrigger( KEY_INPUT_ESCAPE ) == 1 ){
		return modeseq_Back;
	
	}

}