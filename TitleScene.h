#pragma once
#include "Scene.h"
#include "SceneManager.h" 

class TitleScene : public Scene {
public:
    TitleScene(GameContext* ctx) : Scene(ctx) {}

    void Initialize() override;
    void Update(const char* preKeys, const char* keys) override;
    void Draw() override;

    int TitleTexture;
	int titleMusic;
    int playtitleMusic;
   
   
};
