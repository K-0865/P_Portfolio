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
	int scrn_x, scrn_y;/* ��ʏ�̈ʒu */
	int velo_x, velo_y;/* �ړ����x */
	int radius;
	unsigned int cnt;/* Up �J�E���^�[ */
	unsigned int bcnt;/*�N���b�V�����̃J�E���^*/
	int state;
	float c_radius;
} bullet_t;

bullet_t* getBulletPtr(void);

int bullet_Go(int initX, int initY);
int bullet_update(void);


int bullet_init(bullet_t* p, int baseX, int baseY);
/* �v���C���[�̒e�̏����� */
int bullet_disp(void);/* �v���C���[�̒e�̕\��*/
int bullet_finish(void);/* �v���C���[�̒e�̏I���� */
int goBullet(int x, int y);/* �v���C���[�̒e�̕��o */
