#include <Novice.h>
#include <math.h>
#include "Enemy.h"
#include "Vector2.h"
#include "Bullet.h"
#include "Player.h"
#include "hitExplode.h"
#include "Context.h"



void HitExplode(Player* player, Enemy* enemy, int i)
{
	if(enemy->isAlive < 2)
	{
		float dis = sqrtf((player->bullets_[i].pos_.x - enemy->posX_) * (player->bullets_[i].pos_.x - enemy->posX_) +
			(player->bullets_[i].pos_.y - enemy->posY_) * (player->bullets_[i].pos_.y - enemy->posY_));
		if (dis < player->bullets_[i].size_ + enemy->radius_)
		{
			enemy->isAlive = 2;
			player->bullets_[i].setIsShot(false);
			context.score += 1;
			
		};
		float dis2 = sqrtf((player->pos_.x - enemy->posX_) * (player->pos_.x - enemy->posX_) +
			(player->pos_.y - enemy->posY_) * (player->pos_.y - enemy->posY_));
		if (dis2 < player->size_/2 + enemy->radius_)
		{
			enemy->isAlive = 2;
		};
	}
	
}

