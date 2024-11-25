#include"Engine.hpp"
#include<iostream>

bool Engine::Update()
{
    Sleep(20);

    getInstance().m_drawManager.update();

    getInstance().m_inputManager.update();

    getInstance().m_timeManager.update();

    return not getInstance().m_exitFlg;
}

void Engine::TimeManager::update()
{
    double oldChronoTime = m_chronoTime;
    m_chronoTime = getSeconds();
    m_deltaTime = (std::min)(m_chronoTime - oldChronoTime, 0.2);
    m_time += m_deltaTime;
}

double Engine::TimeManager::getSeconds()noexcept
{
    const auto time = std::chrono::high_resolution_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(time).count() / 1000.0;
}

void Engine::DrawManager::update() {
    //ƒJ[ƒ\ƒ‹‚ğ¶ã‚É‚Á‚Ä‚­‚é
    std::cout << "\033[H";

    drawDisplay();

    clearDisplay();

    multiplyColor = ColorF{ 1 };
    addColor = ColorF{ 0 };
}

void Engine::DrawManager::setText(std::string_view text, const Point& point, const ColorF& color, const ColorF& backgroundColor)
{
    if (width <= point.x || point.y < 0 || height <= point.y)
    {
        return;
    }

    int x = point.x;

    for (const char c : text)
    {
        if (width <= x)
        {
            break;
        }
        if (0 <= x)
        {
            m_display[point.y][x] = Pixcel{ c,color,backgroundColor };
        }
        ++x;
    }
}


void Engine::DrawManager::clearDisplay()noexcept {

    ColorF result = defaultBackgroundColor * multiplyColor + addColor;

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            m_display[y][x] = Pixcel{ ' ',ColorF{1},result };
        }
    }
}


void Engine::DrawManager::drawDisplay() {

    ColorF preColor{ 1 };
    ColorF preBackgroundColor{ 0 };

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            if (m_display[y][x].color != preColor)
            {
                setColor(m_display[y][x].color);
                preColor = m_display[y][x].color;
            }

            if (m_display[y][x].backgroundColor != preBackgroundColor)
            {
                setBackgroundColor(m_display[y][x].backgroundColor);
                preBackgroundColor = m_display[y][x].backgroundColor;
            }

            std::cout << m_display[y][x].character;
        }

        setBackgroundColor(ColorF{ 0 });
        preBackgroundColor = ColorF{ 0 };
        std::cout << "\n";
    }

    setColor(ColorF{ 1 });
    setBackgroundColor(ColorF{ 0 });

    std::cout << std::endl;
}

void Engine::InputManager::update()
{
    m_buttonSet.clear();

    while (_kbhit())
    {
        m_buttonSet.insert(_getch());
    }
}
