#include <stdio.h>
#include <thread>
#include <chrono>
#include <signal.h>

#include "logger.h"
#include "config_manager.h"
#include "solution_manager.h"

void sig_proc(int sig) {
	SolutionManager::destroy();
}

void init_signal() {
    /**
    * 需要处理的信号，程序发生严重错误，为了保证后续可以恢复，需要重启进程
    */
    signal(SIGILL, sig_proc); // 非法指令
    signal(SIGABRT, sig_proc); // 由abort(3)发出的退出指令 ，如libc内存错误发出的退出信号
    signal(SIGFPE, sig_proc);  // 浮点异常
    signal(SIGSEGV, sig_proc); // 无效的内存引用
	signal(SIGINT, sig_proc); // 键盘中断（如break键被按下）小球内存不够，DEBUG包太大，用release包调试，键盘中断后确保海思资源能回收 

}

int main(int argc, char** argv) {
	// 初始化日志模块
	init_logger(argv);
	// 初始化信号
	init_signal();

	// 获取配置
	Config config;
	ERR_CODE ret = ConfigManager::get_config_from_local(config, "config.json");
	if (ret != SUCCESS) {
		LOG(ERROR) << "get config from local failed!";
		return -1;
	}

	// 创建解决方案
	ret = SolutionManager::create(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "create solution failed!";
		return -1;
	}

	// 启动解决方案
	ret = SolutionManager::start();
	if (ret != SUCCESS) {
		LOG(ERROR) << "start solution failed!";
		return -1;
	}

	std::this_thread::sleep_for(std::chrono::seconds(10));

	// 销毁解决方案
	ret = SolutionManager::destroy();
	if (ret != SUCCESS) {
		LOG(ERROR) << "destroy solution failed!";
		return -1;
	}
	return 0;
}