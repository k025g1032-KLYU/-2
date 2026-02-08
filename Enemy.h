#pragma once
#include "Vector2.h"
#include <Novice.h>
#include "Context.h"


class Enemy
{
public:
	int isAlive;

	int posX_ ;
	int posY_ ;
	int speedX_;
	int speedY_;
	int radius_ ;

	Enemy();
	~Enemy();

	void Update();
	void Draw();

	int enemyTexture ;
	int explodeTexture ;
	int explodeTextureFrame = 0;
	int explodeSE;
};