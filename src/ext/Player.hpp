#pragma once
#include "PhysicsEntity.hpp"


class Player : public PhysicsEntity {
public:
    Player(const LoaderParams *pParams);
    virtual void Update();
    virtual void Draw();
    virtual void Clean();
};
