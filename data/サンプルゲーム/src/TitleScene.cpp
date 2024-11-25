#include"TitleScene.hpp"

void TitleScene::update()
{
	if (Engine::Down(' '))
	{
		m_selectedFlg = true;

		switch (m_selectIndex)
		{
		case 0:
			changeScene("Game");
			break;
		case 1:
			changeScene("Manual");
			break;
		case 2:
			Engine::Exit();
			break;
		default:
			break;
		}
	}

	if (Engine::Down('w') && 0 < m_selectIndex)
	{
		--m_selectIndex;
	}


	if (Engine::Down('s') && m_selectIndex < 2)
	{
		++m_selectIndex;
	}
}

void TitleScene::draw()const
{
	constexpr ColorF selectButtonColor{ 1 };
	constexpr ColorF defaultButtonColor{ 0.7 };
	constexpr ColorF explanationColor{ 0.85 };
	constexpr ColorF titleColor{ 0.7,0,1 };

	Engine::SetBackgroundColor(ColorF{ 0 });

	Engine::SetText("KAOMOJI Shooting (^o^)", Point{ 9,3 }, titleColor);
	Engine::SetText("Play", Point{ 18,6 }, m_selectIndex == 0 ? selectButtonColor : defaultButtonColor);
	Engine::SetText("Manual", Point{ 18,8 }, m_selectIndex == 1 ? selectButtonColor : defaultButtonColor);
	Engine::SetText("Exit", Point{ 18,10 }, m_selectIndex == 2 ? selectButtonColor : defaultButtonColor);
	Engine::SetText("W:up S:down A:left D:right", Point{ 14,13 }, explanationColor);
	Engine::SetText("Space:OK(Attack)", Point{ 14,14 }, explanationColor);

	Engine::SetText(m_selectedFlg ? "(^o^)" : "(-_-)", Point{ 13,6 + static_cast<int>(m_selectIndex * 2) });
}

