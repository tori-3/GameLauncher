#pragma once
#include"Point.hpp"

struct Rect {

	Point pos;

	Point size;

	[[nodiscard]]
	constexpr Rect() = default;

	[[nodiscard]]
	constexpr Rect(const Point& pos_, const Point& size_)noexcept;

	[[nodiscard]]
	constexpr bool intersects(const Rect& otherRect)noexcept;
};

#include"detail/Rect.ipp"