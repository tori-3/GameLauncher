#pragma once
#include"GameData.hpp"
#include"Engine/Scene.hpp"


class GameScene :public IScene {
public:

	void update()override;

	void draw()const override;

private:

	static constexpr double enemySpawn = 1.8;

	GameData m_gameData;

	double m_accumulateTime = 0;

	double m_scoreTimer = 0;
	bool m_scoreUpFlg = false;;

};
