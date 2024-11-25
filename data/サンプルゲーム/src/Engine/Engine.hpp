#pragma once
#include"ColorF.hpp"
#include"Point.hpp"
#include <algorithm>
#include <chrono>
#include <string_view>
#include <set>
#include <windows.h>
#include <conio.h>
#include <random>

//ƒVƒ“ƒOƒ‹ƒgƒ“
class Engine {
private:
    Engine() = default;
    ~Engine() = default;

public:
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(Engine&&) = delete;

    static Engine& getInstance()
    {
        static Engine instance;
        return instance;
    }

    static constexpr int width = 40;
    static constexpr int height = 15;


    inline static int Random(int min, int max)noexcept;

    inline static int Random(int max)noexcept;

    static bool Update();

    inline static void SetText(std::string_view text, const Point& point, const ColorF& color = ColorF{ 1 }, const ColorF& backgroundColor = getInstance().m_drawManager.defaultBackgroundColor)noexcept;

    inline static void SetMultiplyColor(const ColorF& color) noexcept;

    inline static void SetAddColor(const ColorF& color) noexcept;

    inline static void SetBackgroundColor(const ColorF& color) noexcept;

    inline static void Exit()noexcept;

    inline static double Time()noexcept;

    inline static double DeltaTime()noexcept;

    inline static bool Down(int button)noexcept;

private:

    class RandomManager
    {
    public:

        inline RandomManager();

        inline int random(int min, int max);

        inline int random(int max);

    private:
        std::mt19937 m_randomEngine;

    };

    class TimeManager
    {
    public:
        double m_time = 0;
        double m_deltaTime = 0;
        double m_chronoTime = getSeconds();

        void update();

        double getSeconds()noexcept;

        inline double getTime();

        inline double getDeltaTime();

    };

    class DrawManager {
    public:

        ColorF multiplyColor{ 1 };
        ColorF addColor{ 0 };
        ColorF defaultBackgroundColor{ 0 };

        void update();

        void setText(std::string_view text, const Point& point, const ColorF& color, const ColorF& backgroundColor);

    private:
        struct Pixcel
        {
            char character = ' ';
            ColorF color{ 1 };
            ColorF backgroundColor{ 0 };
        };

        Pixcel m_display[height][width];

        void clearDisplay()noexcept;

        inline void setBackgroundColor(const ColorF& color);

        inline void setColor(const ColorF& color);

        inline int DoubleTo255(double rgb)noexcept;

        void drawDisplay();

    };

    class InputManager {
    public:

        void update();

        inline bool down(int button);

    private:
        std::set<int>m_buttonSet;

    };

    DrawManager m_drawManager;
    RandomManager m_randomManager;
    TimeManager m_timeManager;
    InputManager m_inputManager;

    bool m_exitFlg = false;

};

#include"detail/Engine.ipp"