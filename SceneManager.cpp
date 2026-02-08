#include <Novice.h>
#include "SceneManager.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "Context.h"

SceneManager::~SceneManager() {
    delete currentScene;
}

void SceneManager::ChangeScene(Scene* next) {
    delete currentScene;
    currentScene = next;
    currentScene->Initialize();

}

void SceneManager::Update(const char* preKeys, const char* keys) {
    if (!currentScene) return;

    currentScene->Update( preKeys,  keys);

    switch (currentScene->GetNextScene()) {
    case SceneType::Game:
        ChangeScene(new GameScene(&context));
        break;

    case SceneType::Title:
        ChangeScene(new TitleScene(&context));
        break;

    case SceneType::Result:
        ChangeScene(new ResultScene(&context));
        break;

    default:
        break;
    }
    
}

void SceneManager::Draw() {
    if (currentScene) currentScene->Draw();

	
}
