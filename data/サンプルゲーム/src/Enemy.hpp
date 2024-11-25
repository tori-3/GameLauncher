#pragma once
#include"Engine/Engine.hpp"
#include <cmath>
#include <array>

#include"Entity.hpp"
#include"GameData.hpp"


constexpr ColorF enemyColor{ 0.7,0,1 };


class NormalEnemy :public Entity 
{
public:

	static constexpr const char* kaomojiList[] = { "(¥_¥)","(-_-)","(^_^)","(¥o¥)","(-o-)","(^o^)","(¥w¥)","(-w-)","(^w^)","(¥p¥)","(-p-)","(^p^)","(¥-¥)","(^-^)"};

	static constexpr double moveSpawn = 0.3;

	NormalEnemy(const Point& pos);

	void update(GameData& gameData)override;

	void damage(GameData& gameData, int damage = 1)override;

	void draw()const override;

private:
	const char* m_kaomoji = kaomojiList[Engine::Random(13)];

	double m_accumulateTime = 0;

};

class PunchEnemy :public Entity
{
public:

	static constexpr double moveSpawn = 0.3;
	static constexpr double attackSpawn = 4.0;

	PunchEnemy(const Point& pos);

	void update(GameData& gameData)override;

	void damage(GameData& gameData, int damage = 1)override;

	void draw()const override;

private:
	double m_accumulateTime = 0;

	double m_attackAccumulateTime = 2.0;

};

class DashEnemy :public Entity 
{
public:

	static constexpr const char* kaomojiList[] = { "(^_^)/===","(¥o¥)/===","(^o^)/===","(¥w¥)/===","(^w^)/===","(¥p¥)/===","(^p^)/===","(^-^)/===" };

	static constexpr double moveSpawn = 0.15;

	DashEnemy(const Point& pos);

	void update(GameData& gameData)override;

	void draw()const override;

	void damage(GameData& gameData, int damage = 1)override;

private:

	const char* m_kaomoji = kaomojiList[Engine::Random(7)];

	double m_accumulateTime = 0;

};

class GunEnemy :public Entity 
{
public:

	static constexpr double moveSpawn = 0.3;
	static constexpr double attackSpawn = 0.1;

	GunEnemy(const Point& pos);

	void update(GameData& gameData)override;

	void draw()const override;

	bool isAttackTime()const;

	void damage(GameData& gameData, int damage = 1)override;

private:

	double m_accumulateTime = 0;

	double m_attackAccumulateTime = 2.0;

	double m_time = 0;

};

class UpDownEnemy :public Entity 
{
public:

	static constexpr double moveSpawn = 0.3;

	static constexpr double upDownSpawn = 0.5;

	UpDownEnemy(const Point& pos);

	void update(GameData& gameData)override;

	void draw()const override;

	void damage(GameData& gameData, int damage = 1)override;

private:
	double m_accumulateTime = 0;

	double m_upDownAccumulateTime = 0.0;

	int m_velX = 1;

};
