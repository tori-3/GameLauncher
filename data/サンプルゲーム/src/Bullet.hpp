#pragma once
#include"Engine/ColorF.hpp"
#include"Engine/Rect.hpp"
#include<string_view>


struct GameData;

class Bullet {
public:

	Bullet() = default;

	Bullet(std::string_view text_, const Rect& hitBox_, const ColorF& color_, double spawn_, bool isPlayerBullet = false);

	void update(GameData& data);

	void draw()const;

	bool isAlive()const;

	constexpr Rect getHitBox()const noexcept
	{
		return m_hitBox;
	}

private:
	std::string m_text;
	Rect m_hitBox;
	double m_spawn = 0;
	ColorF m_color;
	int m_hp = 1;
	bool m_isPlayerBullet = false;
	double m_accumulateTime = 0;
};
