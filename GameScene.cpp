#include <Novice.h>
#include "GameScene.h"
#include "Player.h"
#include "Enemy.h"
#include "hitExplode.h"


void GameScene::Initialize() {
    player_ = Player(); 
    //enemy_ = Enemy();
    for(int i = 0; i < 5; i++) {
        enemy_[i] = Enemy();
        enemy_[i].posX_ = i * 200;
        enemy_[i].posY_ = -50;
	}
    BGTexture = Novice::LoadTexture("./Resource/backGround.png");
    gameMusic=Novice::LoadAudio("./Resource/sound/game.mp3");
    playgameMusic = Novice::PlayAudio(gameMusic, 1, 0.5f);
    
}

void GameScene::Update(const char* preKeys, const char* keys) {
    if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
        nextScene = SceneType::Result;
    }
    BGY++;
    if(BGY >= 720) {
        BGY = 0;
	}
    for (int i = 0; i < 5; i++)
    {
        enemy_[i].Update();
        
    }
    player_.Update(keys, preKeys);
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            HitExplode(&player_, &enemy_[i], j);
        }
	}
   
    if (context->score >= 40)
    {
        context->score = 1;
        nextScene = SceneType::Result;
        Novice::StopAudio(playgameMusic);
    }
    else if(context->score <=-15)
    {
        context->score = 0;
        nextScene = SceneType::Result;
        Novice::StopAudio(playgameMusic);
	}
}

void GameScene::Draw() {
	Novice::DrawSprite(0, BGY, BGTexture, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, BGY-720, BGTexture, 1.0f, 1.0f, 0.0f, WHITE);
    for (int i = 0; i < 5; i++)
    {
        enemy_[i].Draw();
        
    }
    player_.Draw(); 
    Novice::ScreenPrintf(0, 500, "point:%d", context->score);
   
}