#include"ManualScene.hpp"

void ManualScene::update()
{

	if (Engine::Down(' '))
	{
		changeScene("Title");

		m_spaceDownFlg = true;
	}
}

void ManualScene::draw()const
{
	Engine::SetBackgroundColor(ColorF{ 0.2 });
	Engine::SetText("�}�j���A��", Point{ 15,1 });
	Engine::SetText("�y���[������ �z", Point{ 1,2 });
	Engine::SetText("�當��(�o�)�𑀍삵�ēG��|�����I", Point{ 1,3 });
	Engine::SetText("��ʉE����G������Ă��܂��B", Point{ 1,4 });
	Engine::SetText("��ʍ��ɓ��B����O�ɓ|���܂��I", Point{ 1,5 });
	Engine::SetText("�X�R�A��2000�𒴂�����N���A�I", Point{ 1,6 });
	Engine::SetText("�G��|����10�`100�X�R�A������", Point{ 1,7 });
	Engine::SetText("�G����ʍ��ɓ��B�����10�X�R�A������", Point{ 1,8 });
	Engine::SetText("�y������@ �z", Point{ 1,10 });
	Engine::SetText("W�L�[:�� S�L�[:�� A�L�[:�� D�L�[:�E", Point{ 1,11 });
	Engine::SetText("Space�L�[�F�U��", Point{ 1,12 });
	Engine::SetText("[Space:OK]", Point{ 15,13 }, m_spaceDownFlg ? ColorF{ 0 } : ColorF{ 1 }, m_spaceDownFlg ? ColorF{ 1 } : ColorF{ 0 });
}

