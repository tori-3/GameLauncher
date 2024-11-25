#include"GameOverScene.hpp"
#include"DataManager.hpp"

void GameOverScene::update()
{
	if (Engine::Down(' '))
	{
		changeScene("Title");
		m_spaceDownFlg = true;
	}
}

void GameOverScene::draw()const
{
	Engine::SetBackgroundColor(ColorF{ 0 });
	Engine::SetText("GAME OVER (x_x)", Point{ 13,4 }, ColorF{ 1,0,0 });
	Engine::SetText("Score:" + std::to_string(DataManager::getInstance().score), Point{ 15,7 });
	Engine::SetText("[Space:OK]", Point{ 15,11 }, m_spaceDownFlg ? ColorF{ 0 } : ColorF{ 1 }, m_spaceDownFlg ? ColorF{ 1 } : ColorF{ 0 });
}
