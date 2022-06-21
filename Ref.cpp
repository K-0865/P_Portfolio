#include "DxLib.h"
#include "game.h"
#include "mode.h"
#include "input.h"
#include "stdafx.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd ) {

	ChangeWindowMode(TRUE);
	SetGraphMode(1200, 900, 32);
	if ( DxLib_Init( ) == -1 )		
	{
		return -1;			
	}
	int ext;


		while (ProcessMessage() == 0) {
			ClearDrawScreen();//����ʏ���
		
			SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�
			inputPeripheralUpdate();
			ext = modeCtrl(0);
			ScreenFlip();//����ʂ�\��ʂɃR�s�[    
			if (ext) { break; }
			
		}
		
	
	WaitKey( );				// �L�[���͑҂�

	DxLib_End( );				// �c�w���C�u�����g�p�̏I������

	return (int)FALSE;				// �\�t�g�̏I�� 
}