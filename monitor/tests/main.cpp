#include <doctest/doctest.h>

#include <windows.h>

void initialize() {
	SetConsoleOutputCP(CP_UTF8);
	// utils::init_log();
}

int main(int argc, char **argv) {
	initialize(); // 在所有测试之前进行初始化
	int result = 0;
	{
		doctest::Context context(argc, argv);
		result = context.run();
		// 尝试显式清理 context 状态
	} // context在这里显式析构，确保释放所有资源

	return result;
}
