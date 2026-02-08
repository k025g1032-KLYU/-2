#pragma once
#include "Context.h"

enum class SceneType {
    None,
    Title,
    Game,
    Result
};

class Scene {
protected:
    SceneType nextScene = SceneType::None;
    GameContext* context;


public:
    Scene(GameContext* ctx) : context(ctx) {}
    virtual ~Scene() {}

    virtual void Initialize() = 0;
    virtual void Update(const char* preKeys, const char* keys) = 0;
    virtual void Draw() = 0;

    SceneType GetNextScene() const {
        return nextScene;
    }
};