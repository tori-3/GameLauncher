#pragma once

struct Point {

	int x = 0;
	int y = 0;

	[[nodiscard]]
	constexpr Point() = default;

	[[nodiscard]]
	constexpr Point(int x_, int y_)noexcept;

	[[nodiscard]]
	constexpr Point operator+(const Point& rhs)const noexcept;

	[[nodiscard]]
	constexpr Point operator-(const Point& rhs)const noexcept;

	[[nodiscard]]
	constexpr bool operator==(const Point& rhs)const noexcept;

	[[nodiscard]]
	constexpr bool operator!=(const Point& rhs)const noexcept;
};

#include"detail/Point.ipp"