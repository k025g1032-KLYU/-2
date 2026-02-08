#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "hitExplode.h"

class GameScene : public Scene {
public:
    GameScene(GameContext* ctx) : Scene(ctx) {}

    void Initialize() override;
    void Update(const char* preKeys, const char* keys) override;
    void Draw() override;

    Player player_;
    Enemy enemy_[5];
   
    int BGTexture = Novice::LoadTexture("./Resource/backGround.png");
    int BGY = 0;
    int gameMusic;
    int playgameMusic;
   
    int shootSE;
};
