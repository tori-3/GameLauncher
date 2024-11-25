#pragma once
#include"Engine.hpp"
#include <string>
#include <string_view>
#include <map>
#include <functional>


class IScene {
public:

	IScene() = default;

	virtual ~IScene() =default;

	virtual void update() = 0;

	virtual void draw()const = 0;

	virtual void drawFadeIn(double t)const;

	virtual void drawFadeOut(double t)const;

	void changeScene(std::string_view sceneName);

	constexpr std::string getNextSceneName()const noexcept;

private:

	std::string m_nextSceneName;
};


class SceneManager {
public:

	std::unique_ptr<IScene>m_scene;

	template<class SceneType>
	void add(std::string_view sceneName);

	void init(std::string_view sceneName);

	void update();

private:

	std::map<std::string, std::function<IScene* ()>>m_maker;

	double m_time = 0;

	enum class State{game,fadeOut,fadeIn} m_state= State::game;
};

#include"detail/Scene.ipp"