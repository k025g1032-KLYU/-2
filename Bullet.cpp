#include <Novice.h>
#include "Bullet.h"


Bullet::Bullet() 
{
	pBulletTexture = Novice::LoadTexture("./Resource/playerBullet.png");
}


Bullet::~Bullet() 
{
}

void Bullet::Update() 
{
	if (pos_.y < -20)
	{
		isShot_=false;
	}
	pos_.y -= spd_;
	if(!isShot_)
	{
		pos_.x = -100;
		pos_.y = 1000;
	}
}

void Bullet::Draw() 
{
	/*Novice::DrawBox(static_cast<int>(pos_.x) - size_ / 2,
					static_cast<int>(pos_.y) - size_ / 2,
					size_,
					size_,
					0.0f,
					0xFFFFFFFF,
		kFillModeSolid);*/

	Novice::DrawSprite(static_cast<int>(pos_.x) - 16, static_cast<int>(pos_.y) - size_ / 2, pBulletTexture, 1.0f, 1.0f, 0.0f, WHITE);

}