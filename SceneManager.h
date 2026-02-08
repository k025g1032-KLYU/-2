#pragma once
#include "Scene.h"
#include "Context.h"

class SceneManager {
public:
    Scene* currentScene = nullptr;
   // GameContext context;

public:
    ~SceneManager();
    void ChangeScene(Scene* next);
    void Update(const char* preKeys, const char* keys);
    void Draw();

    GameContext* GetContext() {
        return &context;
    }
};
