#include"Engine/Engine.hpp"
#include"GameData.hpp"
#include"Bullet.hpp"

Bullet::Bullet(std::string_view text_, const Rect& hitBox_, const ColorF& color_, double spawn_, bool isPlayerBullet)
	:m_text{ text_ }
	, m_hitBox{ hitBox_ }
	, m_color{ color_ }
	, m_spawn{ spawn_ }
	, m_isPlayerBullet{ isPlayerBullet } {}

void Bullet::update(GameData& gameData) {

	m_accumulateTime += Engine::DeltaTime();

	if (m_spawn <= m_accumulateTime)
	{
		if (m_isPlayerBullet) {
			++m_hitBox.pos.x;
		}
		else {
			--m_hitBox.pos.x;
		}

		m_accumulateTime -= m_spawn;
	}

	if (m_isPlayerBullet) {
		for (auto& enemy : gameData.enemies)
		{
			if (enemy->getHitBox().intersects(m_hitBox)) {
				enemy->damage(gameData,1);
				m_hp = 0;
				break;
			}
		}
	}
	else {
		if (gameData.player.getHitBox().intersects(m_hitBox))
		{
			gameData.player.damage(1);

			m_hp = 0;
		}
	}
}

void Bullet::draw()const
{
	Engine::SetText(m_text, m_hitBox.pos, m_color);
}

bool Bullet::isAlive()const
{
	if (m_isPlayerBullet) {
		return m_hitBox.pos.x < Engine::width && 0 < m_hp;
	}
	else {
		return 0 <= (m_hitBox.pos.x + m_hitBox.size.x) && 0 < m_hp;
	}
}
