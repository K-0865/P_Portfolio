#include "stdio.h"
#include "DxLib.h"
#include "title.h"
#include "mode.h"
#include "input.h"
int TitleFont;
int StartFont;
static int num = 0;


void drawTitle() {
    DrawBox(0,0,1200,900,GetColor(0,0,200),TRUE);//Background
    DrawFormatStringToHandle(400, 300, GetColor(255, 255, 255), TitleFont, (const TCHAR*)"図形キャッチャー");//Title Text

    
    
    
    
    
    
    DrawBox(590, 50, 690, 150, GetColor(0, 255, 0), TRUE);
   
    DrawBox(40, 550, 140, 650, GetColor(0, 255, 0), TRUE);

    DrawBox(990, 450, 1090, 550, GetColor(0, 255, 0), TRUE);

    
    DrawCircleAA(120.0f, 150.0f, 80.0f, 5, GetColor(255,255,0), TRUE);
    
    DrawCircleAA(1020.0f, 200.0f, 80.0f, 5, GetColor(255, 255, 0), TRUE);

    DrawCircleAA(1020.0f, 800.0f, 80.0f, 5, GetColor(255, 255, 0), TRUE);

    
    
    
    num++;

    if ((num & 32) < 1)
    {
        DrawFormatStringToHandle(500, 700, GetColor(255, 255, 255), StartFont, (const TCHAR*)"Press Space or Enter To Start");

    }
}
int TitleInt() {
   // SetBackgroundColor( 0, 0, 200 );
    TitleFont = CreateFontToHandle(NULL, 60, 1);
    StartFont = CreateFontToHandle(NULL, 20, 1);
    return modeseq_Increase;
}
int TitleDis() {
    drawTitle();
    if ( getKeyboardOnTrigger(KEY_INPUT_SPACE) == 1 || getKeyboardOnTrigger(KEY_INPUT_RETURN) == 1) {
    
        return modeseq_Increase;
    }
}