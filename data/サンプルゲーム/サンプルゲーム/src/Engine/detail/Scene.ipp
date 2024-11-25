#pragma once



constexpr std::string IScene::getNextSceneName()const noexcept
{
	return m_nextSceneName;
}


template<class SceneType>
void SceneManager::add(std::string_view sceneName)
{
	m_maker.insert(std::make_pair(std::string(sceneName), [] { IScene* ptr = new SceneType(); return ptr; }));
}
