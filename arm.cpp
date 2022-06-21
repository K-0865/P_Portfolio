#include "stdafx.h"
#include "arm.h"


static bullet_t* bp = NULL;

int bullet_Go(int initX, int initY)
{
	if (bp == NULL)
	{
		bp = (bullet_t*)malloc(sizeof(bullet_t));
		bullet_init(bp, initX, initY);
	}
	else {
		return -1;/*”­ŽË‚Å‚«‚È‚¢*/
	}
	return 0;
}

