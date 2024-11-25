#pragma once

constexpr ColorF::ColorF(double r_, double g_, double b_)noexcept
	:r{ r_ }
	, g{ g_ }
	, b{ b_ } {}

constexpr ColorF::ColorF(double rgb)noexcept
	:r{ rgb }
	, g{ rgb }
	, b{ rgb } {}

constexpr ColorF ColorF::operator+(const ColorF& rhs)const noexcept
{
	return { r + rhs.r,g + rhs.g,b + rhs.b };
}

constexpr ColorF ColorF::operator-(const ColorF& rhs)const noexcept
{
	return { r - rhs.r,g - rhs.g,b - rhs.b };
}

constexpr ColorF ColorF::operator*(const ColorF& rhs)const noexcept
{
	return { r * rhs.r,g * rhs.g,b * rhs.b };
}

constexpr bool ColorF::operator==(const ColorF& rhs)const noexcept
{
	return  (r == rhs.r) && (g == rhs.g) && (b == rhs.b);
}

constexpr bool ColorF::operator!=(const ColorF& rhs)const noexcept
{
	return  (r != rhs.r) || (g != rhs.g) || (b != rhs.b);
}
