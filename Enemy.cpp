#include "Enemy.h"
#include "Vector2.h"
#include <Novice.h>
#include "Player.h"
#include "Context.h"


Enemy::Enemy()
{
	isAlive = 3;
	posX_ = 640;
	posY_= -50;
	speedX_ = 10;
	speedY_ = 10;
	radius_ = 32;
	enemyTexture = Novice::LoadTexture("./Resource/enemy.png");
	explodeTexture = Novice::LoadTexture("./Resource/enemyExplosion.png");
	explodeSE = Novice::LoadAudio("./Resource/sound/cannonExplosion.mp3");
}

Enemy::~Enemy() {
}

void Enemy::Update()
{
	if (isAlive == 0)
	{
		posY_ = posY_ + speedY_;
		if (posY_ > 50)
		{
			isAlive = 1;
		}
	}
	else if(isAlive == 1)
	{
		posX_ = posX_ + speedX_;
		posY_ = posY_ + speedY_;
		if (posX_ - radius_ < 0)
		{
			posX_ = radius_;
			speedX_ = -speedX_;
		}
		if (posX_ + radius_ > 1280)
		{
			posX_ = 1280 - radius_;
			speedX_ = -speedX_;
		}
		if (posY_ > 740 )
		{
			isAlive = 3;
			context.score -= 1;
		}
	}
	else if (isAlive ==2)
	{
		explodeTextureFrame++;
		if (explodeTextureFrame == 1)
		{
			Novice::PlayAudio(explodeSE, 0,0.5);
		}
		if (explodeTextureFrame > 19)
		{
			explodeTextureFrame = 0;
			isAlive = 3;
		}
	}
	else if (isAlive ==3)
	{
		posY_ = -50;
		posX_ = rand() % 1000 + 40;
		speedX_= rand() % 20-10 ;
		speedY_ = rand() % 3 + 2;
		isAlive = 0;
	}
	
	
};

void Enemy::Draw()
{
	if(isAlive < 2)
	{
		Novice::DrawSprite(posX_ - radius_, posY_ - radius_, enemyTexture, 1.0f, 1.0f, 0.0f, WHITE);
	}
	else if(isAlive == 2)
	{
		Novice::DrawSpriteRect(posX_ - radius_, posY_ - radius_, 0 + radius_ * 2 * (explodeTextureFrame / 5), 0, radius_*2, radius_ * 2, explodeTexture, 0.25f, 1.0f, 0.0f, WHITE);
		
	}
	//Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeWireFrame);
};