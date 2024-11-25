#include"ManualScene.hpp"

void ManualScene::update()
{

	if (Engine::Down(' '))
	{
		changeScene("Title");

		m_spaceDownFlg = true;
	}
}

void ManualScene::draw()const
{
	Engine::SetBackgroundColor(ColorF{ 0.2 });
	Engine::SetText("マニュアル", Point{ 15,1 });
	Engine::SetText("【ルール説明 】", Point{ 1,2 });
	Engine::SetText("顔文字(･o･)を操作して敵を倒そう！", Point{ 1,3 });
	Engine::SetText("画面右から敵がやってきます。", Point{ 1,4 });
	Engine::SetText("画面左に到達する前に倒します！", Point{ 1,5 });
	Engine::SetText("スコアが2000を超えたらクリア！", Point{ 1,6 });
	Engine::SetText("敵を倒すと10～100スコアが増加", Point{ 1,7 });
	Engine::SetText("敵が画面左に到達すると10スコアが減少", Point{ 1,8 });
	Engine::SetText("【操作方法 】", Point{ 1,10 });
	Engine::SetText("Wキー:上 Sキー:下 Aキー:左 Dキー:右", Point{ 1,11 });
	Engine::SetText("Spaceキー：攻撃", Point{ 1,12 });
	Engine::SetText("[Space:OK]", Point{ 15,13 }, m_spaceDownFlg ? ColorF{ 0 } : ColorF{ 1 }, m_spaceDownFlg ? ColorF{ 1 } : ColorF{ 0 });
}

