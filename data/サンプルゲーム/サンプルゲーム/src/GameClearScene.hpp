#pragma once

#include"Engine/Scene.hpp"

class GameClearScene :public IScene {
public:

	void update()override;

	void draw()const override;

private:
	bool m_spaceDownFlg = false;
	double m_time = 0;
};
