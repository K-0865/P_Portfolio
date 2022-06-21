#pragma once
int modeCtrl(int foo);

enum {
	mode_TitleInt = 0,
	mode_TitleDisp ,
	mode_ruleInt ,
	mode_ruleDis ,
	//mode_RuleInt,
	//mode_RuleDis,
	mode_GameInt,
	mode_GameDis,
	mode_ResInt,
	mode_ResDis
};
enum {
	modeseq_Thuru = 0,/* mode‘JˆÚ•ÏX‚È‚µ */
	modeseq_Exit = -1,/* mode‘JˆÚI—¹ */
	modeseq_Increase = 1,/* mode‘JˆÚŸ‚Ö */
	modeseq_Back = 3,
	modeseq_Game = 2,
	modeseq_Return = 4,/* mode‘JˆÚƒQ[ƒ€‚Ö*/
};