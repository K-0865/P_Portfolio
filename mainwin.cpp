#include "DxLib.h"
#include "game.h"
#include "mode.h"
#include "input.h"
#include "stdafx.h"

int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd ){

	ChangeWindowMode(TRUE);
	SetGraphMode(1200, 900, 32);
	if ( DxLib_Init( ) == -1 )		
	{
		return -1;			
	}
	int ext;
	

		while (ProcessMessage() == 0) {
			ClearDrawScreen();//裏画面消す
		
			SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に
			inputPeripheralUpdate();
			ext = modeCtrl(0);
			ScreenFlip();//裏画面を表画面にコピー    
			if (ext) { break; }
			
		}
		
	
	WaitKey( );				// キー入力待ち

	DxLib_End( );				// ＤＸライブラリ使用の終了処理

	return (int)FALSE;				// ソフトの終了 
}