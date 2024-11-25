#pragma once

constexpr Point::Point(int x_, int y_) noexcept
	: x{ x_ }
	, y{ y_ } {}

constexpr Point Point::operator+(const Point& rhs)const noexcept
{
	return { x + rhs.x,y + rhs.y };
}

constexpr Point Point::operator-(const Point& rhs)const noexcept
{
	return { x - rhs.x,y - rhs.y };
}

constexpr bool Point::operator==(const Point& rhs)const noexcept
{
	return  (x == rhs.x) && (y == rhs.y);
}

constexpr bool Point::operator!=(const Point& rhs)const noexcept
{
	return  (x != rhs.x) || (y != rhs.y);
}
