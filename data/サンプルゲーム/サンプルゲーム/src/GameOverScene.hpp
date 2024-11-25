#pragma once
#include"Engine/Scene.hpp"

class GameOverScene :public IScene {
public:

	void update()override;

	void draw()const override;

private:

	bool m_spaceDownFlg = false;

};
