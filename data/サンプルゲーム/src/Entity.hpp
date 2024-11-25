#pragma once
#include"Engine/Rect.hpp"

struct GameData;

class Entity
{
public:

	Entity() = default;

	Entity(const Rect& hitBox,int hp=1)
		: m_hitBox{ hitBox }
		, m_hp{hp} {}

	virtual ~Entity() = default;

	virtual void update(GameData& gameData) = 0;

	virtual void draw()const = 0;
	
	virtual void damage(GameData&,int damage = 1)
	{
		m_hp -= damage;
	}

	virtual bool isAlive()const
	{
		return 0 < m_hp;
	}

	Rect getHitBox()const
	{
		return m_hitBox;
	}

protected:
	int m_hp = 1;
	Rect m_hitBox;
};
