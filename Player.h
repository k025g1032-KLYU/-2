#pragma once
#include "Vector2.h"
#include "Bullet.h"

class Player
{
public:

	Bullet bullets_[10];

	Player();
	~Player();

	Vector2 pos_ = {640,600};
	Vector2 vel_ = {0,0};
	float spd_=7;
	int size_=64;
	int cooldown = 10;
	//int point = 0;

	void Update( const char* keys, const char* preKeys);
	void Draw();

private:
	int shootSE;
	int playerTexture;
	
	int playerTextureFrame=0;
};


