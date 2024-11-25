#include"Engine.hpp"

void Main();

int main()
{
	// エスケープシーケンスを有効に
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdOut, &mode);
	SetConsoleMode(hStdOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	// カーソルを消す
	std::cout << "\x1b[?25l" << std::endl;

	//エンジンを生成
	Engine::getInstance();

	//メイン
	Main();

	// カーソルを戻す
	std::cout << "\x1b[?25h" << std::endl;

	return EXIT_SUCCESS;
}
