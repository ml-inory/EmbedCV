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
    * ��Ҫ������źţ����������ش���Ϊ�˱�֤�������Իָ�����Ҫ��������
    */
    signal(SIGILL, sig_proc); // �Ƿ�ָ��
    signal(SIGABRT, sig_proc); // ��abort(3)�������˳�ָ�� ����libc�ڴ���󷢳����˳��ź�
    signal(SIGFPE, sig_proc);  // �����쳣
    signal(SIGSEGV, sig_proc); // ��Ч���ڴ�����
	signal(SIGINT, sig_proc); // �����жϣ���break�������£�С���ڴ治����DEBUG��̫����release�����ԣ������жϺ�ȷ����˼��Դ�ܻ��� 

}

int main(int argc, char** argv) {
	// ��ʼ����־ģ��
	init_logger(argv);
	// ��ʼ���ź�
	init_signal();

	// ��ȡ����
	Config config;
	ERR_CODE ret = ConfigManager::get_config_from_local(config, "config.json");
	if (ret != SUCCESS) {
		LOG(ERROR) << "get config from local failed!";
		return -1;
	}

	// �����������
	ret = SolutionManager::create(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "create solution failed!";
		return -1;
	}

	// �����������
	ret = SolutionManager::start();
	if (ret != SUCCESS) {
		LOG(ERROR) << "start solution failed!";
		return -1;
	}

	std::this_thread::sleep_for(std::chrono::seconds(10));

	// ���ٽ������
	ret = SolutionManager::destroy();
	if (ret != SUCCESS) {
		LOG(ERROR) << "destroy solution failed!";
		return -1;
	}
	return 0;
}