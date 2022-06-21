#pragma once

/**
*
*
*
*
*/

#define BULETTE_TYPE_1 true


enum {
	kBULLETSTATE_NORMAL = 0,

};


typedef struct {
	int scrn_x, scrn_y;/* 画面上の位置 */
	int velo_x, velo_y;/* 移動速度 */
	int radius;
	unsigned int cnt;/* Up カウンター */
	unsigned int bcnt;/*クラッシュ時のカウンタ*/
	int state;
	float c_radius;
} bullet_t;

bullet_t* getBulletPtr(void);

int bullet_Go(int initX, int initY);
int bullet_update(void);


int bullet_init(bullet_t* p, int baseX, int baseY);
/* プレイヤーの弾の初期化 */
int bullet_disp(void);/* プレイヤーの弾の表示*/
int bullet_finish(void);/* プレイヤーの弾の終了化 */
int goBullet(int x, int y);/* プレイヤーの弾の放出 */
