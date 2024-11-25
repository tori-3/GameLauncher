#pragma once

struct ColorF {

	double r=1;
	double g=1;
	double b=1;

	[[nodiscard]]
	constexpr ColorF(double r_, double g_, double b_)noexcept;

	[[nodiscard]]
	constexpr ColorF(double rgb)noexcept;

	[[nodiscard]]
	constexpr ColorF() = default;

	[[nodiscard]]
	constexpr ColorF operator+(const ColorF& rhs)const noexcept;

	[[nodiscard]]
	constexpr ColorF operator-(const ColorF& rhs)const noexcept;

	[[nodiscard]]
	constexpr ColorF operator*(const ColorF& rhs)const noexcept;

	[[nodiscard]]
	constexpr bool operator==(const ColorF& rhs)const noexcept;

	[[nodiscard]]
	constexpr bool operator!=(const ColorF& rhs)const noexcept;
};

#include"detail/ColorF.ipp"
