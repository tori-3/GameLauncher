#pragma once

constexpr Rect::Rect(const Point& pos_, const Point& size_)noexcept
	: pos{ pos_ }
	, size{ size_ } {}

constexpr bool Rect::intersects(const Rect& otherRect) noexcept
{
	return (pos.x < otherRect.pos.x + otherRect.size.x && otherRect.pos.x < pos.x + size.x)
		&& (pos.y < otherRect.pos.y + otherRect.size.y && otherRect.pos.y < pos.y + size.y);
}



