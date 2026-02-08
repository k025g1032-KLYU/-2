#pragma once
#include <Novice.h>
#include "Player.h"
#include "Scene.h"
#include "SceneManager.h" 

class ResultScene : public Scene {
public:
    ResultScene(GameContext* ctx) : Scene(ctx) {}
    void Initialize() override;
    void Update(const char* preKeys, const char* keys) override;
    void Draw() override;

	int winTexture;
	int lostTexture;
	int winSE;
	int playwinSE;
	int loseSE;
	int playloseSE;
};

