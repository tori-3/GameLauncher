#include"Engine/Engine.hpp"
#include"GameData.hpp"
#include"Player.hpp"

void Player::update(GameData& gameData)
{

	if (Engine::Down('w') && 0 < m_hitBox.pos.y)
	{
		--m_hitBox.pos.y;
	}

	if (Engine::Down('s') && m_hitBox.pos.y < Engine::height - 2)
	{
		++m_hitBox.pos.y;
	}

	if (Engine::Down('a') && 0 < m_hitBox.pos.x)
	{
		m_hitBox.pos.x -= 2;
	}

	if (Engine::Down('d') && m_hitBox.pos.x < Engine::width - m_hitBox.size.x - 2)
	{
		m_hitBox.pos.x += 2;
	}

	if (Engine::Down(' ') && m_attackTimer <= 0)
	{
		gameData.addBullet(Bullet{ "+",Rect{m_hitBox.pos + Point{5,0},{1,1}},ColorF{1,1,0},0.15,true });
		m_attackTimer = attackInterval;
	}

	if (0 < m_attackTimer)
	{
		m_attackTimer -= Engine::DeltaTime();
	}

	if (0 < m_damageTimer)
	{
		m_damageTimer -= Engine::DeltaTime();
	}
}


void Player::draw()const
{
	if (0 < m_damageTimer) 
	{
		Engine::SetText("(>o<)", m_hitBox.pos, ColorF{ 1,0,0 });
	}
	else {
		Engine::SetText("(¥o¥)", m_hitBox.pos);
	}
}

void Player::damage(int damage)
{
	if (not isDamageState())
	{
		m_hp -= damage;
		m_damageTimer = damageInterval;
	}
}
