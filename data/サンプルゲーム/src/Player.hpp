#pragma once
#include <algorithm>
#include"Engine/Rect.hpp"

struct GameData;

class Player {
public:

	static constexpr double attackInterval = 0.8;
	static constexpr double damageInterval = 1;

	void update(GameData& data);

	void draw()const;

	void damage(int damage = 1);

	constexpr bool isDamageState()const
	{
		return 0<m_damageTimer;
	}

	constexpr Rect getHitBox()const
	{
		return m_hitBox;
	}

	constexpr bool isAlive()const
	{
		return 0 < m_hp;
	}

	constexpr int getHp()const
	{	
		return m_hp;
	}

	constexpr double attackState()const
	{
		return (attackInterval -(std::max)(m_attackTimer,0.0))/ attackInterval;
	}

private:

	int m_hp = 5;

	Rect m_hitBox{ {0,7},{5,1} };

	double m_attackTimer = 0;

	double m_damageTimer = 0;
};
