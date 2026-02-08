#include <Novice.h>
#include "ResultScene.h"
#include "Player.h"



void ResultScene::Initialize() {

    winTexture = Novice::LoadTexture("./Resource/clear.png");
    lostTexture = Novice::LoadTexture("./Resource/gameOver.png");
	winSE = Novice::LoadAudio("./Resource/sound/win.mp3");
	loseSE = Novice::LoadAudio("./Resource/sound/lose.mp3");
    if (context->score == 0) {
        playloseSE=Novice::PlayAudio(loseSE, 0, 0.5);
    }
    else if (context->score == 1) {
        playwinSE=Novice::PlayAudio(winSE, 0, 0.5);
    }
}

void ResultScene::Update(const char* preKeys, const char* keys) {
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        nextScene = SceneType::Title;
		Novice::StopAudio(playwinSE);
		Novice::StopAudio(playloseSE);
    }
}

void ResultScene::Draw() {

    if(context->score==0){
        Novice::DrawSprite(0, 0, lostTexture, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
    }
    else if(context->score==1){
        Novice::DrawSprite(0, 0, winTexture, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
	}
}