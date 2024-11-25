#include"Engine.hpp"

void Main();

int main()
{
	// �G�X�P�[�v�V�[�P���X��L����
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdOut, &mode);
	SetConsoleMode(hStdOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	// �J�[�\��������
	std::cout << "\x1b[?25l" << std::endl;

	//�G���W���𐶐�
	Engine::getInstance();

	//���C��
	Main();

	// �J�[�\����߂�
	std::cout << "\x1b[?25h" << std::endl;

	return EXIT_SUCCESS;
}
