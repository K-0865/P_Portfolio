#include "stdafx.h"
#include "mode.h"
#include "DxLib.h"
#include "title.h"
#include "game.h"
#include "rule.h"
#include "result.h"
static int modeNum = 0;
int modeCtrl(int foo) 
{
	int ret = FALSE;

	switch (modeNum) {
	case mode_TitleInt:
	{
		ret = TitleInt();
	} break;
	case mode_TitleDisp:
	{
		ret = TitleDis();
	} break;
	case mode_ruleInt:
	{
		ret = ruleInt( );
	} break;
	case mode_ruleDis:
	{
		ret = ruleDis( );
	} break;

	case mode_GameInt:
	{
		ret = gameInt();
	} break;

	case mode_GameDis:
	{
		ret = gameDis();
	} break;
	case mode_ResInt:
	{
		ret = resultInt( );
	} break;
	case mode_ResDis:
	{
		ret = resultDis( );
		
	} break;



	}
#if DEBUG
	DrawFormatString(0, 0, GetColor(255, 255, 255), (const TCHAR*)"MODE: %d", modeNum);
#endif
	if ( ret == modeseq_Back ) {
		modeNum = modeNum - ret;
		ret = 0;
	} else if( ret == modeseq_Return ) {
		modeNum = modeNum - ret-3;
		ret = 0;
	}
	else if (ret > modeseq_Thuru)
	{
		modeNum = modeNum + ret;
		ret = 0;
	}
	else if (ret < modeseq_Thuru)
	{
		return ret;
	}

	return ret;

}
