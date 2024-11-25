#include"Enemy.hpp"

NormalEnemy::NormalEnemy(const Point& pos)
	:Entity{ Rect{pos,{5,1}},1 } {}

void NormalEnemy::update(GameData& gameData)
{
	m_accumulateTime += Engine::DeltaTime();

	if (moveSpawn <= m_accumulateTime)
	{
		--m_hitBox.pos.x;

		m_accumulateTime -= moveSpawn;
	}

	if (gameData.player.getHitBox().intersects(m_hitBox))
	{
		gameData.player.damage(1);
	}
}

void NormalEnemy::damage(GameData& gameData, int damage)
{
	m_hp -= damage;
	gameData.score += 10;
}

void NormalEnemy::draw()const
{
	Engine::SetText(m_kaomoji, m_hitBox.pos, enemyColor);
}





PunchEnemy::PunchEnemy(const Point& pos)
	:Entity{ Rect{pos,{7,1}},1 } {}

void PunchEnemy::update(GameData& gameData)
{
	m_accumulateTime += Engine::DeltaTime();

	if (moveSpawn <= m_accumulateTime)
	{
		--m_hitBox.pos.x;

		m_accumulateTime -= moveSpawn;
	}


	m_attackAccumulateTime += Engine::DeltaTime();

	if (attackSpawn <= m_attackAccumulateTime)
	{
		gameData.addBullet(Bullet{ "@",Rect{m_hitBox.pos + Point{-1,0},{1,1}},ColorF{ 0,1,0 },0.15 });

		m_attackAccumulateTime -= attackSpawn;
	}


	if (gameData.player.getHitBox().intersects(m_hitBox))
	{
		gameData.player.damage(1);
	}
}

void PunchEnemy::damage(GameData& gameData, int damage)
{
	m_hp -= damage;
	gameData.score += 30;
}

void PunchEnemy::draw()const
{
	Engine::SetText(m_attackAccumulateTime < attackSpawn / 2.0 ? "@=(¥o¥@)" : "@(¥o¥@)", m_hitBox.pos, enemyColor);
}




DashEnemy::DashEnemy(const Point& pos)
	:Entity{ Rect{pos,{5,1}},1 } {}

void DashEnemy::update(GameData& gameData)
{
	m_accumulateTime += Engine::DeltaTime();

	if (moveSpawn <= m_accumulateTime)
	{
		--m_hitBox.pos.x;

		m_accumulateTime -= moveSpawn;
	}

	if (gameData.player.getHitBox().intersects(m_hitBox))
	{
		gameData.player.damage(1);
	}
}

void DashEnemy::draw()const
{
	Engine::SetText(m_kaomoji, m_hitBox.pos, enemyColor);
}

void DashEnemy::damage(GameData& gameData, int damage)
{
	m_hp -= damage;
	gameData.score += 50;
}





GunEnemy::GunEnemy(const Point& pos)
	:Entity{ Rect{pos,{8,1}},1 } {}

void GunEnemy::update(GameData& gameData)
{
	m_time += Engine::DeltaTime();

	m_accumulateTime += Engine::DeltaTime();

	if (moveSpawn <= m_accumulateTime)
	{
		--m_hitBox.pos.x;

		m_accumulateTime -= moveSpawn;
	}

	if (isAttackTime()) {

		m_attackAccumulateTime += Engine::DeltaTime();

		if (attackSpawn <= m_attackAccumulateTime)
		{
			gameData.addBullet(Bullet{ "+",Rect{m_hitBox.pos + Point{-1,0},{1,1}},ColorF{0,1,0},0.15 });

			m_attackAccumulateTime -= attackSpawn;
		}
	}

	if (gameData.player.getHitBox().intersects(m_hitBox))
	{
		gameData.player.damage(1);
	}
}


void GunEnemy::draw()const
{
	Engine::SetText(isAttackTime() ? "\"\"](^o-)" : "\"\"](^o¥)", m_hitBox.pos, enemyColor);
}

bool GunEnemy::isAttackTime()const
{
	return std::fmod(m_time, 5) <= 1.5;
}

void GunEnemy::damage(GameData& gameData, int damage)
{
	m_hp -= damage;
	gameData.score += 50;
}






UpDownEnemy::UpDownEnemy(const Point& pos)
	:Entity{ Rect{pos,{7,1}},1 } {}

void UpDownEnemy::update(GameData& gameData)
{
	m_accumulateTime += Engine::DeltaTime();

	if (moveSpawn <= m_accumulateTime)
	{
		--m_hitBox.pos.x;

		m_accumulateTime -= moveSpawn;
	}

	m_upDownAccumulateTime += Engine::DeltaTime();

	if (upDownSpawn <= m_upDownAccumulateTime)
	{
		if (m_velX < 0) {

			if (0 < m_hitBox.pos.y) {
				--m_hitBox.pos.y;
			}
			else {
				++m_hitBox.pos.y;
				m_velX = 1;
			}

		}
		else {
			if (m_hitBox.pos.y < Engine::height - 2) {
				++m_hitBox.pos.y;
			}
			else {
				--m_hitBox.pos.y;
				m_velX = -1;
			}
		}
		m_upDownAccumulateTime -= upDownSpawn;
	}

	if (gameData.player.getHitBox().intersects(m_hitBox))
	{
		gameData.player.damage(1);
	}
}

void UpDownEnemy::draw()const
{
	Engine::SetText("\\(^o^)/", m_hitBox.pos, enemyColor);
}

void UpDownEnemy::damage(GameData& gameData, int damage)
{
	m_hp -= damage;
	gameData.score += 100;
}

