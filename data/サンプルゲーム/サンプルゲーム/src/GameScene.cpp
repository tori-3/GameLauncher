#include"GameScene.hpp"
#include"DataManager.hpp"
#include"Enemy.hpp"


void GameScene::update()
{

	double oldScore = m_gameData.score;

	m_accumulateTime += Engine::DeltaTime();

	if (enemySpawn <= m_accumulateTime)
	{
		int random = Engine::Random(99);
		Point pos{ Engine::width,Engine::Random(Engine::height - 2) };

		if (random < 20)
		{
			m_gameData.enemies.push_back(std::unique_ptr<Entity>{new PunchEnemy{ pos }});
		}
		else if (random < 40)
		{
			m_gameData.enemies.push_back(std::unique_ptr<Entity>{new GunEnemy{ pos }});
		}
		else if (random < 60)
		{
			m_gameData.enemies.push_back(std::unique_ptr<Entity>{new DashEnemy{ pos }});
		}
		else if (random < 75)
		{
			m_gameData.enemies.push_back(std::unique_ptr<Entity>{new UpDownEnemy{ pos }});
		}
		else
		{
			m_gameData.enemies.push_back(std::unique_ptr<Entity>{new NormalEnemy{ pos }});
		}


		m_accumulateTime -= enemySpawn;
	}


	for (auto& enemy : m_gameData.enemies)
	{
		enemy->update(m_gameData);
	}

	for (auto& bullet : m_gameData.bullets)
	{
		bullet->update(m_gameData);
	}

	m_gameData.player.update(m_gameData);

	for (auto enemy = m_gameData.enemies.begin(); enemy != m_gameData.enemies.end(); )
	{
		if (not (*enemy)->isAlive())
		{
			enemy = m_gameData.enemies.erase(enemy);
		}
		else
		{
			Rect hitBox = (*enemy)->getHitBox();

			if (hitBox.pos.x + hitBox.size.x < 0)
			{
				enemy = m_gameData.enemies.erase(enemy);
				m_gameData.score -= 10;

				if (m_gameData.score < 0) {
					m_gameData.score = 0;
				}
			}
			else {
				++enemy;
			}
		}
	}


	for (auto bullet = m_gameData.bullets.begin(); bullet != m_gameData.bullets.end(); )
	{
		if (not (*bullet)->isAlive())
		{
			(*bullet)->~Bullet();

			m_gameData.poolAllocator.Free(*bullet);

			bullet = m_gameData.bullets.erase(bullet);
		}
		else
		{
			++bullet;
		}

	}

	if (0 < m_scoreTimer)
	{
		m_scoreTimer -= Engine::DeltaTime();
	}

	if (oldScore < m_gameData.score)
	{
		m_scoreUpFlg = true;
		m_scoreTimer = 0.3;
	}

	if (m_gameData.score < oldScore)
	{
		m_scoreUpFlg = false;
		m_scoreTimer = 0.3;
	}

	if (2000 <= m_gameData.score)
	{
		DataManager::getInstance().score = m_gameData.score;
		changeScene("GameClear");
	}
	else if (m_gameData.player.getHp() <= 0)
	{
		DataManager::getInstance().score = m_gameData.score;
		changeScene("GameOver");
	}
}

void GameScene::draw()const
{
	Engine::SetBackgroundColor(ColorF{ 0 });

	for (auto& enemy : m_gameData.enemies)
	{
		enemy->draw();
	}

	for (auto& bullet : m_gameData.bullets)
	{
		bullet->draw();
	}

	ColorF scoreColor{ 1 };

	if (0 < m_scoreTimer)
	{
		if (m_scoreUpFlg)
		{
			scoreColor = ColorF{ 0,1,0 };
		}
		else
		{
			scoreColor = ColorF{ 1,0,0 };
		}
	}

	std::string attackText;
	bool attackFlg = false;

	if (1.0 <= m_gameData.player.attackState()) {
		attackText = "OK";
		attackFlg = true;
	}
	else if (3.0 / 4.0 <= m_gameData.player.attackState()) {
		attackText = "III";
	}
	else if (2.0 / 4.0 <= m_gameData.player.attackState()) {
		attackText = "II";
	}
	else if (1.0 / 4.0 <= m_gameData.player.attackState()) {
		attackText = "I";
	}

	m_gameData.player.draw();
	Engine::SetText("                                        ", Point{ 0,Engine::height - 1 }, ColorF{ 1 }, ColorF{ 0.3 });
	Engine::SetText("HP:" + std::to_string(m_gameData.player.getHp()), Point{ 1,Engine::height - 1 }, m_gameData.player.isDamageState() ? ColorF{ 1,0,0 } : ColorF{ 1 }, ColorF{ 0.3 });
	Engine::SetText("Attack:", Point{ 7,Engine::height - 1 }, ColorF{ 1 }, ColorF{ 0.3 });
	Engine::SetText(attackText, Point{ 14,Engine::height - 1 }, attackFlg ? ColorF{ 1 } : ColorF{ 1,1,0 }, ColorF{ 0.3 });
	Engine::SetText("Score:" + std::to_string(m_gameData.score), Point{ 19,Engine::height - 1 }, scoreColor, ColorF{ 0.3 });

}
