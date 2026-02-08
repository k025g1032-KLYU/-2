#include <Novice.h>
#include "TitleScene.h"

void TitleScene::Initialize() {
    TitleTexture = Novice::LoadTexture("./Resource/title.png");
	titleMusic = Novice::LoadAudio("./Resource/sound/title.mp3");
	playtitleMusic = Novice::PlayAudio(titleMusic, 1,0.5f);
}

void TitleScene::Update(const char* preKeys, const char* keys) {
    if(keys[DIK_SPACE]&&!preKeys[DIK_SPACE]){
        context->score = 0;    
        nextScene = SceneType::Game;
        Novice::StopAudio(playtitleMusic);
	}
}

void TitleScene::Draw() {

	Novice::DrawSprite(0, 0, TitleTexture, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}

