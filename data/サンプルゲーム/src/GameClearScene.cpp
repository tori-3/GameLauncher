#include"GameClearScene.hpp"
#include"DataManager.hpp"

void GameClearScene::update()
{
	m_time += Engine::DeltaTime();

	if (Engine::Down(' '))
	{
		changeScene("Title");

		m_spaceDownFlg = true;
	}
}

void GameClearScene::draw()const
{
	Engine::SetBackgroundColor(ColorF{ 0 });
	Engine::SetText("GAME Clear \\(^o^)/", Point{ 13,4 }, ColorF{ 0,1,0 });
	Engine::SetText(std::fmod(m_time, 2.0) <= 1.0 ? " (¥_¥)" : "\\(^o^)/", Point{ 17,7 });
	Engine::SetText("[Space:OK]", Point{ 15,10 }, m_spaceDownFlg ? ColorF{ 0 } : ColorF{ 1 }, m_spaceDownFlg ? ColorF{ 1 } : ColorF{ 0 });
}
