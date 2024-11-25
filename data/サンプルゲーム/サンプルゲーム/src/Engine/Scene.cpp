#include"Scene.hpp"

void IScene::drawFadeIn(double t)const
{
	Engine::SetMultiplyColor(ColorF{ t });

	draw();
}

void IScene::drawFadeOut(double t)const
{
	Engine::SetMultiplyColor(ColorF{ 1 - t });

	draw();
};

void IScene::changeScene(std::string_view sceneName)
{
	if (not m_nextSceneName.size())
	{
		m_nextSceneName = sceneName;
	}
}


void SceneManager::init(std::string_view sceneName)
{
	m_scene = std::unique_ptr<IScene>(m_maker.at(std::string(sceneName))());
}

void SceneManager::update()
{
	switch (m_state)
	{
	case State::game: {
		m_scene->update();
		m_scene->draw();
		if (m_scene->getNextSceneName().size())
		{
			m_state = State::fadeOut;
			m_time = 0;
		}
	}break;
	case State::fadeOut: {
		m_scene->drawFadeOut(m_time);
		m_time += Engine::DeltaTime();
		if (1.0 <= m_time)
		{
			m_state = State::fadeIn;
			m_time = 0;
			m_scene = std::unique_ptr<IScene>(m_maker.at(std::string(m_scene->getNextSceneName()))());

		}
	}break;
	case State::fadeIn: {
		m_scene->drawFadeIn(m_time);
		m_time += Engine::DeltaTime();
		if (1.0 <= m_time)
		{
			m_state = State::game;
			m_time = 0;
		}
	}break;
	default:
		break;
	}
}

