#include <Novice.h>
#include "Player.h"


Player::Player()
{
	playerTexture = Novice::LoadTexture("./Resource/player.png");
	shootSE = Novice::LoadAudio("./Resource/sound/shoot.mp3");
}

Player::~Player()
{
}

void Player::Update(const char* keys, const char* preKeys)
{
	playerTextureFrame++;
	if(playerTextureFrame > 19)
	{
		playerTextureFrame = 0;
	}
	
	if(keys[DIK_A] || keys[DIK_LEFT])
	{
		if (vel_.x >= -spd_)
		{
			vel_.x -= 1;
		}
		if(keys[DIK_LSHIFT]&&!preKeys[DIK_LSHIFT])
		{
			vel_.x -= 10;
		}
	}
	if(keys[DIK_D] || keys[DIK_RIGHT])
	{
		if (vel_.x <= spd_)
		{
			vel_.x += 1;
		}
		if (keys[DIK_LSHIFT] && !preKeys[DIK_LSHIFT])
		{
			vel_.x += 10;
		}
	}
	if(keys[DIK_W] || keys[DIK_UP])
	{
		if (vel_.y >= -spd_)
		{
			vel_.y -= 1;
		}
		if (keys[DIK_LSHIFT] && !preKeys[DIK_LSHIFT])
		{
			vel_.y -= 10;
		}
	}
	if(keys[DIK_S]||keys[DIK_DOWN])
	{
		if (vel_.y <= spd_)
		{
			vel_.y += 1;
		}
		if (keys[DIK_LSHIFT] && !preKeys[DIK_LSHIFT])
		{
			vel_.y += 10;
		}
	}

	if(vel_.y> 0.1)
	{
		vel_.y -= 0.1f;
	}
	else if(vel_.y<-0.1)
	{
		vel_.y += 0.1f;
	}
	else
	{
		vel_.y = 0;
	}

	if(vel_.x> 0.1)
	{
		vel_.x -= 0.1f;
	}
	else if(vel_.x<-0.1)
	{
		vel_.x += 0.1f;
	}
	else
	{
		vel_.x = 0;
	}
	pos_.y += vel_.y;
	pos_.x += vel_.x;

	if(pos_.x < (float)size_/2)
	{
		pos_.x = (float)size_/2;
	}
	if(pos_.x > 1280 - (float)size_/2)
	{
		pos_.x = 1280 - (float)size_/2;
	}
	if(pos_.y < (float)size_/2)
	{
		pos_.y = (float)size_/2;
	}
	if(pos_.y > 720 - (float)size_/2)
	{
		pos_.y = 720 - (float)size_/2;
	}
	
	if(keys[DIK_SPACE] && cooldown <= 0)
	{
		
		for (int i = 0; i < 10; i++)
		{
			if(bullets_[i].getIsShot() == false)
			{
				bullets_[i].setIsShot(true)  ;
				bullets_[i].pos_.x = pos_.x;
				bullets_[i].pos_.y = pos_.y-10;
				cooldown = 10;
				Novice::PlayAudio(shootSE, 0,0.5);
				break;
			}
			
		}
		
	}
	if (cooldown > 0)
	{
		cooldown -= 1;
	}

	for (int i = 0; i < 10; i++)
	{
		bullets_[i].Update();
	}
}

void Player::Draw()
{
	for (int i = 0; i < 10; i++)
	{
		bullets_[i].Draw();
	}
	
	Novice::DrawSpriteRect(static_cast<int>(pos_.x) - size_ / 2,
		static_cast<int>(pos_.y) - size_ / 2, 0 + size_ * (playerTextureFrame/5), 0, size_, size_, playerTexture, 0.25f, 1.0f, 0.0f, WHITE);

	Novice::ScreenPrintf(0, 0, "X:%f Y:%f XV:%f YV:%f", pos_.x, pos_.y, vel_.x, vel_.y);
	/*Novice::DrawBox(static_cast<int>(pos_.x) - size_ / 2,
		static_cast<int>(pos_.y) - size_ / 2,
		size_,
		size_,
		0.0f,
		0xFFFFFFFF,
		kFillModeWireFrame);*/

}