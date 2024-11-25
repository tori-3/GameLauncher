#pragma once
#include"Engine/Scene.hpp"


class TitleScene :public IScene {
public:

	void update()override;

	void draw()const override;

private:

	bool m_selectedFlg = false;

	size_t m_selectIndex = 0;
};
