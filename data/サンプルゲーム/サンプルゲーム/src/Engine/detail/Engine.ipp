#pragma once
#include<iostream>

inline int Engine::Random(int min, int max)noexcept
{
    return getInstance().m_randomManager.random(min, max);
}

inline int Engine::Random(int max)noexcept
{
    return getInstance().m_randomManager.random(max);
}

inline void Engine::SetText(std::string_view text, const Point& point, const ColorF& color, const ColorF& backgroundColor)noexcept
{
    getInstance().m_drawManager.setText(text, point, color, backgroundColor);
}

inline void Engine::SetMultiplyColor(const ColorF& color) noexcept
{
    getInstance().m_drawManager.multiplyColor = color;
}

inline void Engine::SetAddColor(const ColorF& color) noexcept
{
    getInstance().m_drawManager.addColor = color;
}

inline void Engine::SetBackgroundColor(const ColorF& color) noexcept
{
    getInstance().m_drawManager.defaultBackgroundColor = color;
}

inline void Engine::Exit()noexcept
{
    getInstance().m_exitFlg = true;
}

inline double Engine::Time()noexcept
{
    return getInstance().m_timeManager.getTime();
}

inline double Engine::DeltaTime()noexcept
{
    return getInstance().m_timeManager.getDeltaTime();
}

inline bool Engine::Down(int button)noexcept
{
    return getInstance().m_inputManager.down(button);
}

inline Engine::RandomManager::RandomManager()
{
    std::random_device seed;
    m_randomEngine.seed(seed());
}

inline int Engine::RandomManager::random(int min, int max)
{
    return m_randomEngine() % ((max - min) + 1) + min;
}

inline int Engine::RandomManager::random(int max)
{
    return random(0, max);
}

inline double Engine::TimeManager::getTime() {
    return m_time;
}

inline double Engine::TimeManager::getDeltaTime() {
    return m_deltaTime;
}

inline void Engine::DrawManager::setBackgroundColor(const ColorF& color)
{
    ColorF result = color * multiplyColor + addColor;

    std::cout << "\x1b[48;2;" << DoubleTo255(result.r) << ";" << DoubleTo255(result.g) << ";" << DoubleTo255(result.b) << "m";
}

inline void Engine::DrawManager::setColor(const ColorF& color)
{
    ColorF result = color * multiplyColor + addColor;

    std::cout << "\x1b[38;2;" << DoubleTo255(result.r) << ";" << DoubleTo255(result.g) << ";" << DoubleTo255(result.b) << "m";
}

inline int Engine::DrawManager::DoubleTo255(double rgb)noexcept
{
    return (std::min)((std::max)(static_cast<int>(rgb * 255), 0), 255);
}

inline bool Engine::InputManager::down(int button)
{
    return m_buttonSet.contains(button);
}
