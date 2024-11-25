#pragma once
#include<vector>
#include <memory>
#include"Bullet.hpp"
#include"Entity.hpp"
#include"Player.hpp"
#include"PoolAllocator.h"

struct GameData
{
	PoolAllocator<Bullet, 200> poolAllocator{};
	std::vector<Bullet*>bullets;
	std::vector<std::unique_ptr<Entity>>enemies;
	Player player;

	int score = 0;

	void addBullet(const Bullet&bullet)
	{
		Bullet* ptr = poolAllocator.Alloc();
		*ptr = bullet;
		bullets.push_back(ptr);
	}

};
