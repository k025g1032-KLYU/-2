#pragma once
#include "Vector2.h"


class Bullet
{
public:

	Bullet();
	~Bullet();

	Vector2 pos_ = { -100,-100 };
	
	
	int getIsShot() const { return isShot_; }
	void setIsShot(int isShot) { isShot_ = isShot; }

	void Update();
	void Draw();
	int size_ = 16;

private:
	float spd_ = 10;
	int isShot_ = false;
	int pBulletTexture;


};