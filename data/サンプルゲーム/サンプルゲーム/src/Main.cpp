#include"Engine/Engine.hpp"
#include"Engine/Scene.hpp"

#include"TitleScene.hpp"
#include"GameScene.hpp"
#include"GameOverScene.hpp"
#include"GameClearScene.hpp"
#include"ManualScene.hpp"

void Main() 
{
	SceneManager manager;

	manager.add<GameScene>("Game");
	manager.add<TitleScene>("Title");
	manager.add<ManualScene>("Manual");
	manager.add<GameOverScene>("GameOver");
	manager.add<GameClearScene>("GameClear");
	manager.init("Title");

	while (Engine::Update()) 
	{
		manager.update();
	}
}

